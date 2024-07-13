/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        vector<ListNode *> list;
        for (int i = 0; i < lists.size(); i++)
        {
            ListNode *cur = lists[i];
            while (cur != nullptr)
            {
                list.push_back(cur);
                cur = cur->next;
            }
        }

        // sort the list
        MergeSort(list, 0, list.size() - 1);

        ListNode *sorted = new ListNode();
        ListNode *tempt = sorted;

        for (int i = 0; i < list.size(); i++)
        {
            tempt->next = list[i];
            tempt = tempt->next;
        }

        return sorted->next;
    }

    void MergeSort(vector<ListNode *> &list, int low, int high)
    {
        if (low < high)
        {
            int mid = (low + high) / 2;
            MergeSort(list, low, mid);
            MergeSort(list, mid + 1, high);
            Merge(list, low, mid, high);
        }
    }

    void Merge(vector<ListNode *> &list, int low, int mid, int high)
    {
        int n1 = mid - low + 1;
        int n2 = high - mid;

        vector<ListNode *> leftArray;
        leftArray.reserve(n1);
        vector<ListNode *> rightArray;
        rightArray.reserve(n2);

        // copy data to tempt array
        for (int i = 0; i < n1; i++)
        {
            leftArray[i] = list[low + i];
        }
        for (int i = 0; i < n2; i++)
        {
            rightArray[i] = list[mid + 1 + i];
        }

        // Merge the tempt array back into arr
        int i = 0;
        int j = 0;
        int k = low;

        while (i < n1 && j < n2)
        {
            if (leftArray[i]->val <= rightArray[j]->val)
            {
                list[k] = leftArray[i];
                i++;
            }
            else
            {
                list[k] = rightArray[j];
                j++;
            }
            k++;
        }

        while (i < n1)
        {
            list[k] = leftArray[i];
            i++;
            k++;
        }
        while (j < n2)
        {
            list[k] = rightArray[j];
            j++;
            k++;
        }
    }
};
