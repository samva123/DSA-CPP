#include <iostream>
#include <queue>
using namespace std;

void solveForMedian(double &median, priority_queue<int> &maxi, priority_queue<int, vector<int>, greater<int>> &mini, int element) {
    
    // Step 1: insert into correct heap
    if (maxi.empty() || element < maxi.top()) {
        maxi.push(element);
    } else {
        mini.push(element);
    }

    // Step 2: balance heaps (sizes differ at most by 1)
    if (maxi.size() < mini.size()) {
        maxi.push(mini.top());
        mini.pop();
    } else if (maxi.size() > mini.size() + 1) {
        mini.push(maxi.top());
        maxi.pop();
    }

    // Step 3: calculate median
    if (maxi.size() == mini.size()) {
        median = (maxi.top() + mini.top()) / 2.0;
    } else {
        median = maxi.top();
    }
}

int main() {
    int arr[] = {12, 10, 8, 4, 2, 3, 15};
    int n = 7;

    double median = 0;
    priority_queue<int> maxi; // max-heap (left half)
    priority_queue<int, vector<int>, greater<int>> mini; // min-heap (right half)

    for (int i = 0; i < n; i++) {
        int element = arr[i];
        solveForMedian(median, maxi, mini, element);
        cout << "Median found after inserting " << element << ": " << median << endl;
    }

    return 0;
}


// this question is left 









class MedianFinder
{
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;

public:
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (maxheap.size() == 0 || num < maxheap.top())
            maxheap.push(num);
        else
            minheap.push(num);

        if (maxheap.size() < minheap.size())
        {
            maxheap.push(minheap.top());
            minheap.pop();
        }
        else if (maxheap.size() > minheap.size() + 1)
        {
            minheap.push(maxheap.top());
            maxheap.pop();
        }
    }

    double findMedian()
    {
        if (maxheap.size() == minheap.size())
        {
            return (maxheap.top() + minheap.top()) / 2.0;
        }
        return maxheap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */