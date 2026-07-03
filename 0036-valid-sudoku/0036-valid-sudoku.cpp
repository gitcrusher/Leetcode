class Solution {
public:
    bool validbox(vector<vector<char>>& board, int sr , int er , int sc, int ec){
        unordered_set<char>st;
        for(int i = sr; i<=er ;i++){
            for(int j = sc; j<=ec; j++){
                if(board[i][j]=='.')continue;
                if(st.find(board[i][j])!=st.end())return false;
                st.insert(board[i][j]);
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        //cols = 9
        //rows = 9
        //validate rows
        for(int rows = 0 ; rows < 9 ; rows++){
            unordered_set<int>st;
            for(int cols = 0 ; cols<9 ; cols++){
                if(board[rows][cols]=='.')continue;
                if(st.find(board[rows][cols])!=st.end())return false;
                st.insert(board[rows][cols]);
            }
        }

        // validate columns
        for(int cols = 0 ; cols < 9 ; cols++){
            unordered_set<int>st1;
            for(int rows = 0 ; rows<9; rows++){
                if(board[rows][cols]=='.')continue;
                if(st1.find(board[rows][cols])!=st1.end())return false;
                st1.insert(board[rows][cols]);
            }
        }

        //validate boxes

        for(int sr = 0 ; sr< 9; sr+=3){
            int er = sr+2;
            for(int sc = 0 ; sc<9; sc+=3){
                int ec = sc+2;
                if(!validbox(board, sr,er,sc,ec)) return false;
            }
        }
        return true;
    }
};