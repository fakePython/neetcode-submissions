class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(int i = 0 ;i < nums.size(); i++){
            s.insert(nums[i]);
        }

        vector<int> start_seqs;

        for(int i = 0 ;i < nums.size(); i++){
            if(s.find(nums[i] - 1) == s.end()){
                //start of the sequence
                start_seqs.push_back(nums[i]);
            }
        }

        int max_len = 0;
        for(auto start : start_seqs){
            int len = 1;
            while(true){
                if(s.count(start+1)){
                    len++;
                    start++;
                } else {
                    break;
                }
            }

            max_len = max(max_len, len);
        }

        return max_len;
    }
};


//dp

//choose next big