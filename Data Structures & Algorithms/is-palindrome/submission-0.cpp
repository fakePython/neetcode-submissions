class Solution {
public:
    bool isAlphaNumeric(char c){
        if(c - 'a' >= 0 && c - 'a' < 26){
            return true;
        } else if (c - 'A' >= 0 && c - 'A' < 26) {
            return true;
        } else if(c - '0' >= 0 && c - '0' <= 9) {
            return true;
        }

        return false;
    }
    bool isPalindrome(string s) {
        /***
            1.reverse a copy and compare strings : O(N) time complexity + O(N) Space
            2. Splint in half & check (two pointer) : O(n) + O(1)
        */
        string temp;
        for(char &c : s){
            if(!isAlphaNumeric(c)){
                continue;
            }
            c = tolower(c);
            temp.push_back(c);
        }

        s = temp;

        cout << s << endl;

        int start = 0, end = s.size() - 1;

        while(start < end){
            if(s[start] != s[end]){
                return false;
            }
            start++;
            end--;
        }

        return true;
    }
};
