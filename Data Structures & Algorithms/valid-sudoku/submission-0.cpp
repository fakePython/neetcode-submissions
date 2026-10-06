class Solution {
public:
    int findSubBox(int x){
        if(x <= 2){
            return 0;
        } else if(x > 2 && x <= 5){
            return 3;
        } else {
            return 6;
        }
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        

        for(int i = 0; i < 9;i++){
            for(int j = 0; j < 9;j++){
                if(board[i][j] == '.'){
                    continue;
                }

                int num = board[i][j] - '0';

                //find in row;
                for(int k = 0; k < 9; k++){
                    if(k == j) continue;
                    if(board[i][k] == '.') continue;

                    int n = board[i][k] - '0';
                    if(num == n){
                        cout<<"i : "<<i<<"j: "<<j << "row" <<endl;
                        return false;
                    }
                }

                //find in col
                for(int k = 0; k < 9; k++){
                    if(k == i) continue;
                    if(board[k][j] == '.') continue;

                    int n = board[k][j] - '0';
                    if(num == n){
                        cout<<"i : "<<i<<"j: "<<j << "col" <<endl;
                        return false ;
                    }
                }

                //find in sub 3*3 cell
                int x = findSubBox(i), y = findSubBox(j);

                for(int p = x; p< x + 3; p++){
                    for(int q = y;q < y + 3; q++){
                        if(board[p][q] == '.') continue;
                        if(p == i && q == j) continue;
                        
                        int n = board[p][q] - '0';
                        if(num == n){
                            cout<<"i : "<<i<<"j: "<<j << "pq"<< x << y << endl;
                            return false;
                        }
                    }
                }


            }
        }

        return true;
    }
};

//for every poistion check these things.
//row - col & 3x3 box

// [0 1 2] [3 4 5] [6 7 8]