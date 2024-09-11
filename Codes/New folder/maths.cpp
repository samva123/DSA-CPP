// lc-204 but ye solution tle mar dega 

class solution {
    public:
    bool isprime(int n ){
        if(n <= 1) return false;

        for(int i =2 ; i<n ; ++i){
            if(n%i == 0){
                return false;
            }
        }
        return true;



    }
    int countprime(int n){
        int c = 0 ;

        for(int i = 0 ; i<n ; i++){
            if(isprime(i)){
                ++c;
            }
        }
        return c ;
    }

};