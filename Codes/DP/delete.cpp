#include<iostream>
#include<vector>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int n , m , k ;
        cin >> n >> m >> k;
        
        vector<int>a(m);
        for(int i  = 0 ; i < m ; i++){
            cin >> a[i];
        }
        
        vector<int>q(k);
        for(int  i = 0 ; i < k ; i++){
            cin >> q[i];
        }
        
        vector<int>res(m);
        
        if(k == n ){
            for(int  i = 0 ; i < m ; i++){
                res[i] = 1;
            }
        }
        else if(k == n -1){
            int list_num = 1;
            for(int elem : q){
                if(list_num == elem){
                    ++list_num;
                }
            }
            for(int i = 0 ; i < m ; i++){
                if(a[i] == list_num){
                    res[i] = 1;
                }
            }
        }
        for(int i = 0 ; i < m ; i++){
            cout << res[i];
        }
        cout << endl;
    }
}