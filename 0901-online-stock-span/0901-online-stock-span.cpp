
class StockSpanner {
private:
    // Store pairs: {stock price, span}
    stack<pair<int, int>> st;

public:
    StockSpanner() {
        // Initially, the stack is empty
    }

    int next(int price) {
        int span = 1;

        // Remove all previous prices <= current price
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }

        // Store current price and its calculated span
        st.push({price, span});

        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */