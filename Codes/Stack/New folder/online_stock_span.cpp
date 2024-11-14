  // this is a type of question of monotonic stack question

class StockSpanner {
public:
    stack<pair<int , int>>st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span =  1;
        while(!st.empty() && st.top().first <= price){
            span += st.top().second;
            st.pop();

        }
        st.push({price , span});
        return span;
        
    }
};
// time complexity is O(n) and space complexity is O(n) in worst case
/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */