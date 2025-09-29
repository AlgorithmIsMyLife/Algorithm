class Solution
{
public:
    // Structure of the condition
    // for sorting the pair by its
    // second elements
    struct myComp
    {
        constexpr bool operator()(
            pair<int, int> const &a,
            pair<int, int> const &b)
            const noexcept
        {
            return a.second > b.second;
        }
    };
    int leastInterval(vector<char> &tasks, int n)
    {
        vector<bool> isInQueue(26);
        vector<int> leftTasks(26);
        int totalLeft{};
        priority_queue<pair<int, int>, vector<pair<int, int>>, myComp> mq; // min heap

        for (int i = 0; i < tasks.size(); i++)
        {

            leftTasks[tasks[i] - 'A']++;
            totalLeft++;
        }

        int time = 1;
        while (totalLeft > 0)
        {
            // Pop
            if (!mq.empty() && (time - mq.top().second) > n)
            {
                int i = mq.top().first;
                isInQueue[i] = false;
                mq.pop();
            }

            // Push
            // find the one with the most left and not in queue
            // O(26)
            int mostIndex = -1;
            int most = 0;
            for (int i = 0; i < leftTasks.size(); i++)
            {
                if (!isInQueue[i] && leftTasks[i] > most)
                {
                    most = leftTasks[i];
                    mostIndex = i;
                }
            }

            if (mostIndex != -1)
            {
                mq.push({mostIndex, time});
                isInQueue[mostIndex] = true;
                leftTasks[mostIndex]--;
                totalLeft--;
            }

            time++;
        }

        return time - 1;
    }
};
