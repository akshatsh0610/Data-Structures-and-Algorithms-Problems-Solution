class StockSpanner {
public:
    stack<int>stk;
    vector<int>arr;
    int idx;
    
    StockSpanner() {idx=0;}
    
    int next(int val) {
          
        arr.push_back(val);
        
        while(!stk.empty() and arr[stk.top()]<=val)
        {
            stk.pop();
        }
        if(stk.empty()==true)
        {
            stk.push(idx);
            int ans=(idx+1);
            idx++;
            return ans;
            
        }
        else if(stk.empty()==false)
        {
            int ans=(idx-stk.top());
            
            stk.push(idx);
            idx++;
            return ans;
            
        }
        return 1;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
