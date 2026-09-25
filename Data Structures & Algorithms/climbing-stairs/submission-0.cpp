class Solution {
public:
    int memoization(int i, int n, vector<int> &cache) {
        if (i == n) return 1;
        if (i > n) return 0;
        
        if (cache[i] != -1) {
            return cache[i];
        }
        
        int i_1 = memoization(i + 1, n, cache);
        int i_2 = memoization(i + 2, n, cache);
        
        return cache[i] = i_1 + i_2;
    }
    
    int climbStairs(int n) {
        vector<int> cache(n + 1, -1);
        return memoization(0, n, cache);
    }
};
