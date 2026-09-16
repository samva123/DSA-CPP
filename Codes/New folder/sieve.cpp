#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int countprimes(int n){
    if(n <= 1) return 0;

    vector<bool> prime(n + 1 , true);
    prime[0] = prime[1] = false;

    //int m = sqrt(n);

    for(int i = 2 ; i*i <= n ; i++){
        if(prime[i]){

            //int j = 2*i;
            int j = i*i; 
            // Optimisation 1:
            // first unmarked number would be i*i , as others have been
            // marked by 2 to (i-1)

            while(j <= n){
                prime[j] = false;
                j += i;
            }
        }
    }

    int ans = 0;
    for(int i = 2 ; i <= n ; i++){
        if(prime[i]) ans++;
    }

    return ans;
}

// time complexity is O(n/2 + n/3 + n/5 + n/7.....);
// it is a harmonic progression
//so by taylor series O(n*log(log n))
