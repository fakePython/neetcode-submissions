class Solution {
public:

    string encode(vector<string>& strs) {
        //count chars in string and add the string

        string encoded_string = "";

        for(string str : strs){

            string len = to_string((int) str.size());

            encoded_string += len + "#";
            encoded_string += str;  
        }

        cout<<" " << encoded_string << "  ";

        return encoded_string;
    }

    vector<string> decode(string s) {

        vector<string> decoded_strings;

        int i = 0, j = 0; // j = i + 1 start from next char

        while(j < s.size()){
            string num = "";
            while(s[i] != '#'){
                num += s[i];
                i++;
            }
            int nums = stoi(num);
            j = i + 1;
            string decoded_string = "";
            while(nums > 0){
               decoded_string += s[j];
               j++;
               nums--; 
            }
            // cout<<" " << decoded_string << "  ";
            decoded_strings.push_back(decoded_string);
            nums--; //0
            i = j;
        }


        return decoded_strings;
    }
};
