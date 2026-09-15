class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        // int max_profit = 0;

        // for(int i = 0 ; i < prices.size(); i++){
        //     int buy = prices[i];
        //     for(int j = i + 1; j < prices.size(); j++){
        //         int sell = prices[j];

        //         int curr_profit = sell - buy;
        //         max_profit = max(max_profit, curr_profit);
        //     }
        // }

        // return max_profit;

        int l = 0, r = 1;
        int maxP = 0;

        while(r < prices.size()){
            if(prices[l] < prices[r]){
                int profit = prices[r] - prices[l];
                maxP = max(maxP, profit);
            }else{
                l = r;
            }
            r++;
        }

        return maxP;

        /***
            1: Intuition: Brute Force : Time O(n^2), space O(1)
            2: Dynamic / Sliding Window
                - 
        */
    }
};
