class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int max_length = 0, i = 0, j = 0;
        unordered_map<char, int> seen;

        while(j < s.size()){
            if(!seen.count(s[j])){
                seen.insert({s[j], j});
                j++;
            } else {
                int l = seen[s[j]];
                while(i <= l){
                    seen.erase(s[i]);
                    i++;
                }
            }

            int curr_length = j - i;
            max_length = max(max_length, curr_length);
        }


        return max_length;
    }
};


/**
BRUTE FORCE:
O(N) + O(1) :: but it should not repeat use hash-table.
**/