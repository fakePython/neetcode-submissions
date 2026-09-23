class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //BRUTE FORCE
        //SPACE: O(N), TIME: O(N)
        unordered_map<int,int> valFreq;

        for(int i = 0; i < nums.size(); i++){
            if(valFreq.find(nums[i]) != valFreq.end()){
                valFreq[nums[i]]++;
            } else{
                valFreq.insert({nums[i],1});
            }
        }

        // map<int, int, greater<int>> freqVal;
        // for(auto it : valFreq){
        //     freqVal.insert({it.second, it.first});
        // }

        priority_queue<pair<int,int>> freqVal;

        for(auto it: valFreq){
            freqVal.push({it.second, it.first});
        }


        vector<int> res;

        while(k){
            res.push_back(freqVal.top().second);
            freqVal.pop();
            k--;
        }

        return res;

        //SORT & COUNT
        // sort(nums.begin(), nums.end());

        // in this case we don't have to use two maps, one map will be enough.
    }
};
