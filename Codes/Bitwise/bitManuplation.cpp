#include <iostream>
#include<vector>
using namespace std;

void checkEvenOdd(int n) {
	if(n & 1) {
		cout << "Odd" << endl;
	}
	else {
		cout << "Even " << endl;
	}
}

void getIthBit(int n,int i) {
	int mask = (1 << i);//by this we are making the ith bit one
	int ans = n & mask;
	if(ans == 0) {
		cout << "bit-> 0" << endl;
	}
	else {
		cout << "bit-> 1" << endl;
	}
}

void setIthBit(int n, int i) {
	int mask = (1<<i);
	n = n | mask;
	cout << "Updated number: " << n << endl;
}

void clearIthBit(int &n, int i) {
	int mask = ~(1<<i);
	n = n & mask;
	//cout << "Updated number: " << n << endl;
}

void udpateIthBit(int n, int i, int target) {
	//clear ith bit
	clearIthBit(n, i);
	//cout << "after clearing: " << n;
	//create mask
	int mask = (target << i);
	//update n
	n = n | mask;
	cout << "Updated number: " << n << endl;
}

void clearLastIBits(int n, int i) {
	int mask = (-1 << i);
	n = n & mask;
	cout << "Updated number: " << n << endl;
}

bool checkPowerOf2(int n) {
	//count set bit
	int count = 0;

	while(n != 0 ) {
		int lastbit = n & 1;
		if(lastbit) {
			count++;
		}
		n = n >> 1;
	}

	if(count == 1 ){
		return true;
	}
	else {
		return false;
	}	
}


// class Solution {
// public:
//     bool isPowerOfTwo(int n) {
//         if (n <= 0) {  // Handles n == 0 and negative numbers
//             return false;
//         }
//         if (n == INT_MIN) {  // Special case for INT_MIN, which is not a power of two
//             return false;
//         }
//         return (n & (n - 1)) == 0;
//     }
// };


int fastCOuntSetBits(int n) {
	int count = 0;
	while(n != 0) {
		//cout << "n value: " << n << endl;
		count++;
		n = (n & (n-1));//(Brian Kernighan’s Algorithm)
	}
	return count;
}

////////////Striver////////////////
#include <iostream>
using namespace std;

int countSetBitsLoop(int n) {
    int count = 0;
    for (int i = 0; i < 32; i++) {  // Loop through all 32 bits
        if (n & (1 << i)) {  // Check if the i-th bit is set
            count++;
        }
    }
    return count;
}

int main() {
    int n = 29;  // Binary: 11101, expected output: 4
    cout << "Set bits count: " << countSetBitsLoop(n) << endl;
    return 0;
}


void clearBitsInRange(int n, int i, int j) {
    // Step 1: Create a mask with 1s everywhere except between i and j
    int left = (~0) << (j + 1);   // 1s from (j+1)th bit to MSB
    int right = (1 << i) - 1;     // 1s from 0th bit to (i-1)th bit
    int mask = left | right;      // combine both sides

    // Step 2: Apply mask to clear bits i to j
    n = n & mask;

    cout << "Updated number: " << n << endl;
}


void getSubsequences(string str) {
	int n = str.length();
	vector<string> ans;
	for(int num = 0; num < (1<<n); num++ ) {
		//number is ready
		//use num, to create subsequences

		//num -> set bit -> index -> char -> incl
		string temp = "";
		for(int i=0; i<n; i++) {
			//i -> represent index
			char ch = str[i];
			//agar i index pr num k andar set bit present hai
			//toh character ko include krdlo
			int mask = (1 << i);
			if(num & mask) {
				temp.push_back(ch);
			}
		}
		ans.push_back(temp);
	}

	cout << "printing the subsequences: " << endl;
	for(auto i: ans) {
		cout << i << endl;
	}
}

int main() {

	string str = "abc";
	getSubsequences(str);
	// int n = 1023;
	// int i = 8;
	// int j = 1;
	// clearBitsInRange(n, i, j);
	//cout << fastCOuntSetBits(n);
	//cout << fastCheckPowerOf2(n) << endl;
	

	
	//int n = 15;
	//checkEvenOdd(n);
	//int i =  2;
	//clearLastIBits(n, i);
	//int target = 0;
	//udpateIthBit(n, i, target);
	//clearIthBit(n,i);
	//getIthBit(n, i);

	return 0;
}