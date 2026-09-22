class Solution {
public:

    bool isAnagram(string s, string t){
        if(s.size() != t.size()){
            return false;
        }

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        /*
          //Brute Force: for every pos i , find all the anagrams and put it into sub-list and return.
        

        vector<vector<string>> res;

        unordered_set<int> already;

        for(int i = 0; i < strs.size(); i++){
            if(already.find(i) != already.end()){
                continue;
            }
            vector<string> anags;
            for(int j = i + 1; j < strs.size(); j++){
                if(already.find(j) != already.end()){
                    continue;
                }
                if(isAnagram(strs[i], strs[j])){
                    already.insert(j);
                    anags.push_back(strs[j]);
                }
            }
            already.insert(i);
            anags.push_back(strs[i]);

            res.push_back(anags);
        }

        return res;

        */

        //optimized brute force:
        vector<vector<string>> res;
        unordered_map<string, vector<string>> umap;

        for(int i = 0; i < strs.size(); i++){
            string key = strs[i];
            sort(key.begin(), key.end());

            if(umap.find(key) != umap.end()){
                umap[key].push_back(strs[i]);
            } else{
                vector<string> first = {strs[i]};
                umap.insert({key, first});
            }
        }

        for(auto it : umap){
            res.push_back(it.second);
        }

        return res;

    }
};
