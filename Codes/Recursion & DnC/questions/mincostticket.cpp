class Solution {
public:
int helper(vector<int>&days , vector<int>& costs , int i){

    if(i >= days.size()) return 0;

    int cost1  = costs[0] + helper(days , costs , i+1);


    //7 day
    int passendday = days[i] +7 -1;
    int j =1;
    while(j<days.size() && days[j] <= passendday){
        j++;
    }
    int cost7 = costs[1] + helper(days , costs ,j);

    //30 days
    passendday = days[i] +30 -1;
    j =1;
    while(j<days.size() && days[j] <= passendday){
        j++;
    }
    int cost30 = costs[2] + helper(days , costs ,j);

    return min(cost1 , min(cost7 ,cost30));


    
}
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        return helper(days , costs , 0);
        
    }
};