class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /***
            #Brute Force:
            - Traverse both array and find such indices
            Complexiy : Time O(n^2), Space O(1)

            #Hash Map
            - Traverse Once the array and check if complimnet already added
            Complexity: Time : O(n) , Space O(N), hashmap operation: nLog(n) ?
        */

        vector<int> result;

        map<int, int> mp;
        mp.insert({target - nums[0], 0});

        //[-7,0], [-6,1], [-5,2], [-4,3], [-3,4]

        for(int i = 1; i< nums.size();i++){
            if(mp.find(nums[i]) != mp.end()){
                int x = mp[nums[i]], y = i;
                result.push_back(x);
                result.push_back(y);
            } else{
                mp.insert({target - nums[i], i});
            }
        }

        return result;
    }
};
