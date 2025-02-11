#include<bits/stdc++.h>
using namespace std;


bool is_in_matrix(vector<vector<int>>& matrix, int& target, int& col, int front, int end){
    if(end <= front) return false;
    // if (end-front == 0){
    //     int crt_row = front / col;
    //     int crt_col = front - front / col * col;
    //     if(matrix[crt_row][crt_col] == target) return true;
    //     else return false;
    // }

    int middle = (front + end) / 2;
    int crt_row = middle / col;
    int crt_col = middle % col;

    if(target == matrix[crt_row][crt_col]) return true;
    else if(target < matrix[crt_row][crt_col]) return is_in_matrix(matrix, target, col, front, middle);
    else return is_in_matrix(matrix, target, col, middle+1, end);
}

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int total = m * n;
        return is_in_matrix(matrix, target, n, 0, total);
    }
};