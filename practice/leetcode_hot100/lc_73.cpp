#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int pre=0, crt=0;
        int row = matrix.size(), col=matrix[0].size();
        for(int j=0; j<col; j++){
            if(matrix[0][j] == 0){
                pre = 1;
                break;
            }
        }
        for(int i=1; i<row; i++){
            for(int j=0; j<col; j++){
                if(matrix[i][j] == 0){
                    crt = 1;
                    if(matrix[i-1][j] != 0){
                        for(int k=i-1; k>=0; k--) matrix[k][j] = 0;
                    }
                }
                if(matrix[i-1][j] == 0) matrix[i][j] = 0; 
            }
            if(pre){
                for(int j=0; j<col; j++){
                    matrix[i-1][j] = 0;
                }
            }
            pre = crt;
            crt = 0;
        }
        if(pre){
            for(int j=0; j<col; j++) matrix[row-1][j] = 0;
        }
    }
};