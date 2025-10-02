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


class StockSpanner {
public:
    vector<pair<int, int>> stocks;

    StockSpanner() { }

    int next(int price) {
        int span = 1;
        int index = stocks.size() - 1;

        while (index >= 0 && stocks[index].first <= price) {
            span += stocks[index].second;
            index -= stocks[index].second;
        }

        stocks.push_back({price, span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

//below is brute force

class StockSpanner {
public:
    vector<int> prices;

    StockSpanner() { }

    int next(int price) {
        int span = 1;
        int index = prices.size() - 1;

        while (index >= 0 && prices[index] <= price) {
            span++;
            index--;
        }

        prices.push_back(price);
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
