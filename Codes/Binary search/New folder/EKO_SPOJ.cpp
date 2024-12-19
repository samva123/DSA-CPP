#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(vector<long long int> trees, long long int m, long long int mid){
    long long int sum = 0;
    for(long long int i = 0; i < trees.size(); i++){
        if(trees[i] > mid){
            sum += trees[i] - mid;
        }
    }
    return sum >= m;
}

long long int maxSawBlade(vector<long long int> trees, long long int m){
    long long int low = 0;
    long long int high = *max_element(trees.begin(),trees.end());
    long long int ans = -1;
    while(low <= high){
        long long int mid = low + (high - low)/2;
        if(isPossible(trees,m , mid)){
            ans = mid;
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return ans;
}

int main(){
    long long int n , m ;
    cin >> n >> m;
    vector<long long int> trees;
    while(n--){
        long long int temp;
        cin >> temp;
        trees.push_back(temp);
    }

    cout << maxSawBlade(trees,m) << endl;
    
}

