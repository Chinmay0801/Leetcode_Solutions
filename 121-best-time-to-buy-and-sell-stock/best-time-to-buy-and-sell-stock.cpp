class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int MaxP =0;
        int minP = prices[0];
        for(int i = 1 ; i <prices.size(); i++ ){
            minP = min(minP , prices[i]);
          int  p = prices[i] - minP;
            MaxP = max(p , MaxP);
        }
        return MaxP;
        
    }
};