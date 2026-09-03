class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> u_set;

        for(int num : nums){
            if(u_set.count(num) != 0){
                return true;
            }
            u_set.insert(num);
        }

        return false;
    }
};