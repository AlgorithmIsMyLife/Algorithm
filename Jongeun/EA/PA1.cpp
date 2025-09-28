
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <sstream>

using namespace std;

bool compareDate(const string &date1, const string &date2)
{
    return date1 <= date2;
}

string getNewExpiryDate(const string &date, int months)
{
    int year, month, day;
    sscanf(date.c_str(), "%d.%d.%d", &year, &month, &day);

    // Add months
    month += months;

    // Adjust overflow
    while (month > 12)
    {
        month -= 12;
        year += 1;
    }

    // Subtract one day
    day -= 1;

    if (day == 0)
    {
        month -= 1;
        if (month == 0)
        {
            month = 12;
            year -= 1;
        }
        // All months have 28 days
        day = 28;
    }

    char newDate[11];
    sprintf(newDate, "%04d.%02d.%02d", year, month, day);
    return string(newDate);
}

string join(const vector<string> &items, const string &delimiter)
{
    string joinedString;
    for (size_t i = 0; i < items.size(); i++)
    {
        if (i > 0)
            joinedString += delimiter;
        joinedString += items[i];
    }
    return joinedString;
}

vector<string> solution(vector<string> category, vector<string> form, vector<string> record)
{
    unordered_map<string, int> categoryExpired;      // store basic category and its expiration
    unordered_map<string, string> savedDataExpiry;   // store saved data's category and its calculated expiration date
    unordered_map<string, string> categoryLastSaved; // store category and its start date
    vector<string> answer;

    for (const auto &c : category)
    {
        stringstream ss(c);
        string categoryName;
        int duration;
        ss >> categoryName >> duration;
        categoryExpired[categoryName] = duration;
    }

    // Process each record
    for (const auto &r : record)
    {
        string date, formIdxString;
        stringstream ss(r);
        ss >> date >> formIdxString;

        int formIdx = stoi(formIdxString) - 1; // Zero-based index

        // Extract the categories
        string formContent = form[formIdx];
        stringstream formStream(formContent);
        string categoryName;
        vector<string> requiredCategories;
        set<string> autoFilledCategories;

        while (formStream >> categoryName)
        {
            requiredCategories.push_back(categoryName);
        }

        // Check which category can be auto-filled
        for (const auto &reqCategory : requiredCategories)
        {
            if (savedDataExpiry.find(reqCategory) != savedDataExpiry.end() &&
                compareDate(categoryLastSaved[reqCategory], date) &&
                compareDate(date, savedDataExpiry[reqCategory]))
            {
                autoFilledCategories.insert(reqCategory);
            }
        }

        // Update the expiry dates for all categories in the form
        for (const string &cat : requiredCategories)
        {
            int validity = categoryExpired[cat];
            string newExpiryDate = getNewExpiryDate(date, validity);
            savedDataExpiry[cat] = newExpiryDate;
            categoryLastSaved[cat] = date;
        }

        // Prepare the result
        if (autoFilledCategories.empty())
        {
            answer.push_back("None");
        }
        else
        {
            vector<string> sortedAutoFilled(autoFilledCategories.begin(), autoFilledCategories.end());
            sort(sortedAutoFilled.begin(), sortedAutoFilled.end());
            answer.push_back(join(sortedAutoFilled, " "));
        }
    }

    return answer;
}
