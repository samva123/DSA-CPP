#include <bits/stdc++.h>
using namespace std;
int evenDigits(int n)
{
    
    int ans  = 0;
    int i = 1;
    while(n > 0){
    
    
    int help = n%10;
    
    if(help%2 == 0){
        
        ans  = ans+help*i;
        i = i*10;
    }
    n = n/10;
        
    }
    return ans;
  
  
}

int main(){
    int n;
    cin>>n;

    cout<<evenDigits(n);
    return 0;
}
