#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define MaxV 1000000000

int main(int argc, char **argv)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string temp;
    cin >> temp;
    while (temp != "QUIT")
    {

        vector<pair<string, int>> program;
        while (temp != "END")
        {
            if (temp == "NUM")
            {
                int num;
                cin >> num;
                program.push_back({temp, num});
            }
            else
            {
                program.push_back({temp, 0});
            }
            cin >> temp;
        }

        int N;
        cin >> N;

        for (int i = 0; i < N; i++) // Run each program
        {
            int num;
            cin >> num;
            vector<int> stack;
            stack.push_back(num);
            string result{};
            bool error = false;
            for (auto it : program)
            {
                if (it.first == "NUM")
                {
                    stack.push_back(it.second);
                }
                else if (it.first == "POP")
                {
                    if (stack.empty())
                    {
                        error = true;
                        break;
                    }
                    stack.pop_back();
                }
                else if (it.first == "INV")
                {
                    if (stack.empty())
                    {
                        error = true;
                        break;
                    }
                    int temp = stack.back();
                    temp = -temp;
                    stack.pop_back();
                    stack.push_back(temp);
                }
                else if (it.first == "DUP")
                {
                    if (stack.empty())
                    {
                        error = true;
                        break;
                    }
                    int temp = stack.back();
                    stack.push_back(temp);
                }
                else if (it.first == "SWP")
                {
                    if (stack.size() < 2)
                    {
                        error = true;
                        break;
                    }
                    int first = stack.back();
                    stack.pop_back();
                    int second = stack.back();
                    stack.pop_back();

                    stack.push_back(first);
                    stack.push_back(second);
                }
                else
                {
                    if (stack.size() < 2)
                    {
                        error = true;
                        break;
                    }
                    long long first = stack.back();
                    stack.pop_back();
                    long long second = stack.back();
                    stack.pop_back();
                    long long temp;

                    if (it.first == "ADD")
                    {
                        temp = (long long)first + second;
                    }
                    else if (it.first == "SUB")
                    {
                        temp = second - first;
                    }
                    else if (it.first == "MUL")
                    {
                        temp = first * second;
                    }
                    else if (it.first == "DIV")
                    {
                        if (first == 0)
                        {
                            error = true;
                            break;
                        }

                        int minusCnt = (first < 0) + (second < 0);
                        temp = abs(second) / abs(first) * (minusCnt == 1 ? -1 : 1);
                    }
                    else if (it.first == "MOD")
                    {
                        if (first == 0)
                        {
                            error = true;
                            break;
                        }
                        int minusCnt = (second < 0);
                        temp = abs(second) % abs(first) * (minusCnt == 1 ? -1 : 1);
                    }

                    if (abs(temp) > MaxV)
                    {
                        error = true;
                        break;
                    }
                    else
                    {
                        stack.push_back(temp);
                    }
                }
            }
            if (error || stack.size() != 1)
            {
                cout << "ERROR" << '\n';
            }
            else
            {
                cout << stack.back() << '\n';
            }
        }

        cout << '\n';
        cin >> temp;
    }

    return 0;
}
