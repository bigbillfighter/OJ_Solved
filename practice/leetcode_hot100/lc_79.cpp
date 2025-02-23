#include <bits/stdc++.h>
using namespace std;

int visited[6][6];

class Solution {
public:
    bool findcrt(vector<vector<char>>& board, string& word, int len, int crt, int x, int y){
        if(crt == len - 1) return true;

        int row = board.size(), col = board[0].size();
        bool ans = false;

        if(x + 1 < row && !visited[x+1][y] && board[x+1][y] == word[crt+1]){
            visited[x+1][y] = 1;
            ans = ans || findcrt(board, word, len, crt+1, x+1, y);
            visited[x+1][y] = 0;
        }

        if(x > 0  && !visited[x-1][y] && board[x-1][y] == word[crt+1]){
            visited[x-1][y] = 1;
            ans = ans || findcrt(board, word, len, crt+1, x-1, y);
            visited[x-1][y] = 0;
        }

        if(y+1 < col && !visited[x][y+1] && board[x][y+1] == word[crt+1]){
            visited[x][y+1] = 1;
            ans = ans || findcrt(board, word, len, crt+1, x, y+1);
            visited[x][y+1] = 0;
        }

        if(y > 0 && !visited[x][y-1] && board[x][y-1] == word[crt+1]){
            visited[x][y-1] = 1;
            ans = ans || findcrt(board, word, len, crt+1, x, y-1);
            visited[x][y-1] = 0;
        }

        return ans;

    }

    void set_zero(){
        for(int i=0; i<6; i++) for(int j=0; j<6; j++) visited[i][j] = 0;

    }

    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size(), col = board[0].size();
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(board[i][j] == word[0]){
                    set_zero();
                    visited[i][j] = 1;
                    if(findcrt(board, word, word.size(), 0, i, j)) return true;
                }
            }
        }
        return false;
    }
};