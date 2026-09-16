#include <bits/stdc++.h>
using namespace std;

vector<int>sieve(int n){
    vector<bool>primes(n+1 , true );
    vector<int>ans;
    primes[0] = primes[1] = false;

    for(int  i = 2  ; i*i <= n ; i++){

        if(primes[i] == true){
            
        
            int j = i*i;
            while(j <= n){
                //ans.push_back(j);
                primes[j] = false;
                j += i;
            }
        }
        
    }
    return ans;

}

int main(){
    
}