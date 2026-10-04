class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long prod = 1;

        int zero_cnt = 0;
        for(int num : nums){
            if(num == 0){
                zero_cnt++;
                continue;
            } 
            prod *= num;
        }

        cout<<prod<< " " << zero_cnt;


        vector<int> res;
        for(int num : nums){
            if(num == 0){
                if(zero_cnt == 1){
                    res.push_back(prod);
                } else if(zero_cnt > 1){
                    res.push_back(0);
                }
            } else{
                int prod_except_self = prod/num;
                if(zero_cnt > 0){
                    prod_except_self *= 0;
                }
                res.push_back(prod_except_self);
            }
        }


        return res;
    }
};
