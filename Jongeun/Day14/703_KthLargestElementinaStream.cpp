class KthLargest
{
public:
    KthLargest(int k, vector<int> &nums)
    {
        largest = k;
        stream = nums;
        // construct Min Heap
        for (int i = nums.size() / 2 - 1; i >= 0; i--)
        {
            DownHeap(i);
        }

        while (stream.size() > largest)
        {
            ExtractMin();
        }
    }

    int add(int val)
    {

        stream.push_back(val);
        Upheap(stream.size() - 1);

        while (stream.size() > largest)
        {
            ExtractMin();
        }

        int kth = stream.front();
        return kth;
    }

    void DownHeap(int i)
    {
        while (2 * i + 1 < stream.size())
        {
            int win = 2 * i + 1;
            if (2 * i + 2 < stream.size() && stream[2 * i + 2] < stream[2 * i + 1])
            {
                win = 2 * i + 2;
            }
            if (stream[win] < stream[i])
            {
                std::swap(stream[win], stream[i]);
                i = win;
            }
            else
            {
                return;
            }
        }
    }

    void Upheap(int i)
    {
        while ((i - 1) / 2 >= 0)
        {
            if (stream[i] < stream[(i - 1) / 2])
            {
                std::swap(stream[i], stream[(i - 1) / 2]);
                i = (i - 1) / 2;
            }
            else
            {
                return;
            }
        }
    }

    void ExtractMin()
    {
        std::swap(stream[0], stream[stream.size() - 1]);
        stream.pop_back();
        DownHeap(0);
    }

private:
    vector<int> stream;
    int largest;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
