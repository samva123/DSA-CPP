#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int cdevices(string &binary)
    {
        int c = 0;
        for (int i = 0; i < binary.length(); i++)
        {
            int b = binary[i];
            c += b - '0';
        }

        return c;
    }

    int numberOfBeams(vector<string> &bank)
    {
        vector<int> devices;
        for (auto row : bank)
            devices.push_back(cdevices(row));
        int beams = 0;
        for (int i = 0; i < devices.size(); ++i)
        {
            int j = i + 1;
            while (j < devices.size())
            {
                beams += devices[i] * devices[j];
                if (devices[j] == 0)
                {
                    j++;
                }
                else
                {
                    break;
                }
            }
        }
        return beams;
    }
};

// upper  has O(n square) time complexity and O(n) space complexity
//  below has O(n.m) time complexity and O(1) space complexity

class Solution
{
public:
    int numberOfBeams(vector<string> &bank)
    {
        int prevDevices = 0, beams = 0;
        for (const string &row : bank)
        {
            int currentDevices = count(row.begin(), row.end(), '1'); // Count '1's in the current row
            if (currentDevices > 0)
            {
                beams += prevDevices * currentDevices;
                prevDevices = currentDevices;
            }
        }
        return beams;
    }
};