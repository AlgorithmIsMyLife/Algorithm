class MedianFinder
{
public:
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (total == 0)
        {
            maxHeap.push(num);
            total++;
        }
        else
        {
            if (total % 2 == 0)
            {
                if (maxHeap.top() < num)
                {
                    minHeap.push(num);
                    int temp = minHeap.top();
                    minHeap.pop();
                    maxHeap.push(temp);
                }
                else
                {
                    maxHeap.push(num);
                }
            }
            else
            {
                if (maxHeap.top() < num)
                {
                    minHeap.push(num);
                }
                else
                {
                    maxHeap.push(num);
                    int temp = maxHeap.top();
                    maxHeap.pop();
                    minHeap.push(temp);
                }
            }

            total++;
        }
    }

    double findMedian()
    {
        if (total % 2 == 0)
        {
            return ((double)maxHeap.top() + minHeap.top()) / 2;
        }
        else
        {
            return maxHeap.top();
        }
    }

private:
    int total = 0;
    priority_queue<int> maxHeap;
    priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
