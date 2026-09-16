class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(int i = 0; i< s.size(); i++){
            if(st.empty() && (s[i] == '(' || s[i] == '[' || s[i] == '{')){
                st.push(s[i]);
            } else if(st.empty() && (s[i] == ')' || s[i] == ']' || s[i] == '}')){
                return false;
            } else if(!st.empty() &&  (s[i] == '(' || s[i] == '[' || s[i] == '{')) {
                st.push(s[i]);
            } else{
                char top = st.top();
                if(s[i] == ')'){
                    if(top != '('){
                        return false;
                    } else{
                        st.pop();
                    }
                } else if(s[i] == ']'){
                    if(top != '['){
                        return false;
                    } else{
                        st.pop();
                    }
                } else {
                    if(top != '{'){
                        return false;
                    } else{
                        st.pop();
                    }
                }
            }
        }


        return st.empty() ? true : false;
    }
};
