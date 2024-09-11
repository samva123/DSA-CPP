// to find a^b in O(log b ) time

int fast(int a , int b){
    int ans = 1;
    while(b>0){
        if(b&1){
            ans = ans*a;
        }
        a = a*a;
        b>>=1;
    }
    return ans;
}