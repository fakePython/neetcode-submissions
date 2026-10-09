class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        //use hashmap;
        unordered_map<int,int> seen;
        
        for(int i = 0; i < numbers.size();i++){
            if(seen.count(target-numbers[i])){
                return {seen[target-numbers[i]]+1, i+1};
            }
            seen.insert({numbers[i], i});
        }

        return {-1,-1};
    }
};
