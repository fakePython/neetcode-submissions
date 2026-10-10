class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        /**
            BRUTE FORCE : O(N^3), O(?)
        */
        /**
        sort(nums.begin(), nums.end());
        set< vector<int> > u_set;
        for(int i  = 0; i < nums.size(); i++){
            for(int j = i + 1;j < nums.size(); j++) {
                for(int k = j + 1; k < nums.size();k++){
                    if(nums[i] + nums[j]+ nums[k] == 0 && !u_set.count({nums[i],nums[j],nums[k]})){
                        res.push_back({nums[i],nums[j],nums[k]});
                        u_set.insert({nums[i],nums[j],nums[k]});
                    }
                }
            }
        }
        */

        /**
            TWO POINTER:
        */
        sort(nums.begin(), nums.end());
        set< vector<int> > u_set; // to remove duplicates.

        for(int i  = 0; i < nums.size(); i++){
            int l = i + 1, r = nums.size() - 1;
            while(l < r){
                if(nums[i] + nums[l]+ nums[r] == 0){
                    if(!u_set.count({nums[i],nums[l],nums[r]})){
                        res.push_back({nums[i],nums[l],nums[r]});
                        u_set.insert({nums[i],nums[l],nums[r]});
                    }
                    l++;
                    r--;
                } else if(nums[i] + nums[l]+ nums[r] > 0) {
                    r--;
                } else {
                    l++;
                }
            }
        }


        return res;
    }
};



//sort ??