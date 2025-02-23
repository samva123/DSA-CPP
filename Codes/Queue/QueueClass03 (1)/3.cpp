// Question 1: first non repeating character in a stream
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str = "ababc";
    queue<char> q;
    int freq[26] = {0};
    // har char ko pakdo frequency store kro queue mai dalo aur check kro
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        freq[ch - 'a']++;
        // queue ke ander push taki track rakh pao
        q.push(ch);

        // answer find kro
        while (!q.empty())
        {
            char frontChar = q.front();
            // check freq
            if (freq[frontChar - 'a'] > 1)
            {
                // not an answer
                q.pop();
            }
            else
            {
                //==1 vala case
                // unique character
                cout << frontChar << " ";
                break;
            }
        }
        if (q.empty())
        {
            // no answer found
            cout << '#' << " ";
        }
    }
    return 0;
}
// Question 2: Gas Station Leetcode->134
int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int deficit = 0;
    int balance = 0;
    int start = 0;
    for (int i = 0; i < gas.size(); i++)
    {
        balance = balance + gas[i] - cost[i];
        if (balance < 0)
        {
            deficit += abs(balance);
            start = i + 1;
            balance = 0;
        }
    }
    if (balance - deficit >= 0)
        return start;
    else
        return -1;
}

// Question 3:Sliding windows Maximum
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    vector<int> ans;
    deque<int> dq;
    int size = nums.size();
    // first window process till k size
    for (int i = 0; i < k; i++)
    {
        int ele = nums[i];
        // push elements in the queue and remove chote vale elements
        while (!dq.empty() && ele > nums[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    // processs the remaining window Removal and Insertion
    for (int i = k; i < size; i++)
    {

        ans.push_back(nums[dq.front()]);

        // remove
        if (i - dq.front() >= k)
            dq.pop_front();
        int ele = nums[i];
        // push elements in the queue and remove chote vale elements
        while (!dq.empty() && ele > nums[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    // handle last window
    ans.push_back(nums[dq.front()]);

    return ans;
}









// C++ program to find sum of all minimum and maximum
// elements Of Sub-array Size k.
#include<bits/stdc++.h>
using namespace std;

// Returns sum of min and max element of all subarrays
// of size k
int SumOfKsubArray(int arr[] , int n , int k)
{
    int sum = 0;  // Initialize result

    // The queue will store indexes of useful elements
    // in every window
    // In deque 'G' we maintain decreasing order of
    // values from front to rear
    // In deque 'S' we  maintain increasing order of
    // values from front to rear
    deque< int > S(k), G(k);

    // Process first window of size K
    int i = 0;
    for (i = 0; i < k; i++)
    {
        // Remove all previous greater elements
        // that are useless.
        while ( (!S.empty()) && arr[S.back()] >= arr[i])
            S.pop_back(); // Remove from rear

        // Remove all previous smaller that are elements
        // are useless.
        while ( (!G.empty()) && arr[G.back()] <= arr[i])
            G.pop_back(); // Remove from rear

        // Add current element at rear of both deque
        G.push_back(i);
        S.push_back(i);
    }

    // Process rest of the Array elements
    for (  ; i < n; i++ )
    {
        // Element at the front of the deque 'G' & 'S'
        // is the largest and smallest
        // element of previous window respectively
        sum += arr[S.front()] + arr[G.front()];

        // Remove all elements which are out of this
        // window
        if ( !S.empty() && S.front() == i - k)
            S.pop_front();
        if ( !G.empty() && G.front() == i - k)
            G.pop_front();

        // remove all previous greater element that are
        // useless
        while ( (!S.empty()) && arr[S.back()] >= arr[i])
            S.pop_back(); // Remove from rear

        // remove all previous smaller that are elements
        // are useless
        while ( (!G.empty()) && arr[G.back()] <= arr[i])
            G.pop_back(); // Remove from rear

        // Add current element at rear of both deque
        G.push_back(i);
        S.push_back(i);
    }

    // Sum of minimum and maximum element of last window
    sum += arr[S.front()] + arr[G.front()];

    return sum;
}

// Driver program to test above functions
int main()
{
    int arr[] = {2, 5, -1, 7, -3, -1, -2} ;
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 4;
    cout << SumOfKsubArray(arr, n, k) ;
    return 0;
}
