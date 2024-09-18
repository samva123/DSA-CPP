class Solution {
public:

    int numsquarehelper(int n ){
        if(n == 0 ) return 1;
        if(n < 0) return 0;

        int ans = INT_MAX;

        int i = 1;
        int end = sqrt(n);
        while(i <= end){
            int perfectSquare = i*i;
            int number = 1 + numsquarehelper(n - perfectSquare);
            if(number < ans){
                ans = number;
            }
            ++i;

        }
        return ans;

    }
    int numSquares(int n) {
        return numsquarehelper(n)-1;
        
        
    }
};