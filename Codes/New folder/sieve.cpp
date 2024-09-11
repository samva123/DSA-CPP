int countprimes(int n){
    if(n == 0) return 0;

    vector<bool> prime(n , true);
    prime[0] = prime[1] = false;
    int ans = 0;

    for(int i = 2 ; i<n;i++){
        if(prime[i]){
            ans++;

            int j = 2*i;
            while(j<n){
                prime[j] = false;
                j+=i;
            }
        }
    }
}

// time complexity is O(n/2 + n/3 + n/5 + n/7.....);
// it is a harmonic progression
//so by taylor series O(n*log(log n))