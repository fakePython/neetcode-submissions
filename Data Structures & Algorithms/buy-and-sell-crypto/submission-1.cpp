class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int max_profit = 0;

        for(int i = 0 ; i < prices.size(); i++){
            int buy = prices[i];
            for(int j = i + 1; j < prices.size(); j++){
                int sell = prices[j];

                int curr_profit = sell - buy;
                max_profit = max(max_profit, curr_profit);
            }
        }

        return max_profit;

        /***
            1: Intuition: Brute Force : Time O(n^2), space O(1)
            2: Dynamic / Sliding Window
                - 
        */
    }
};
