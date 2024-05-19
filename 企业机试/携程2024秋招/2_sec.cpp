#include<bits/stdc++.h>
using namespace std;

const int max_n = 1005;
int crt_map[max_n][max_n] = {-1};

typedef long long ll;


// y o u
int pre_sum_col[3][max_n][max_n] = {0};
int pre_sum_row[3][max_n][max_n] = {0};


ll cal_tri(int row_row, int row_col, int col_row, int col_col, int m, int n, int x, int y){
    if(row_col < 0 || row_col >= m) return 0;
    if(col_col < 0 || col_col >= n) return 0;

    ll row_sum, col_sum;
    if(x>row_col){
        row_sum = pre_sum_row[row_row][row_col][y]; 
    }else{
        row_sum = pre_sum_row[row_row][m-1][y] - pre_sum_row[row_row][x][y]; 
    }

    if(y>col_col){
        col_sum = pre_sum_col[col_row][x][col_col]; 
    }else{
        col_sum = pre_sum_col[col_row][x][n-1] - pre_sum_col[col_row][x][y]; 
    }

    return row_sum * col_sum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m, n;
    cin >> m >> n;
    char ccr;
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> ccr;
            crt_map[i][j] = ccr - 'a';
            if(crt_map[i][j] == 'y'-'a'){
                if(j > 0){
                    pre_sum_col[0][i][j] = pre_sum_col[0][i][j-1] + 1;
                }else{
                    pre_sum_col[0][i][j] = 1;
                }
                if(i > 0){
                    pre_sum_row[0][i][j] = pre_sum_row[0][i-1][j] + 1;
                }else{
                    pre_sum_row[0][i][j] = 1;
                }
            }else{
                if(j > 0){
                    pre_sum_col[0][i][j] = pre_sum_col[0][i][j-1];
                }
                if(i > 0){
                    pre_sum_row[0][i][j] = pre_sum_row[0][i-1][j];
                }
            }

            if(crt_map[i][j] == 'o'-'a'){
                // row[1][i] ++;
                // col[1][j] ++;
                if(j > 0){
                    pre_sum_col[1][i][j] = pre_sum_col[1][i][j-1] + 1;
                }else{
                    pre_sum_col[1][i][j] = 1;
                }
                if(i > 0){
                    pre_sum_row[1][i][j] = pre_sum_row[1][i-1][j] + 1;
                }else{
                    pre_sum_row[1][i][j] = 1;
                }
            }else{
                if(j > 0){
                    pre_sum_col[1][i][j] = pre_sum_col[1][i][j-1];
                }
                if(i > 0){
                    pre_sum_row[1][i][j] = pre_sum_row[1][i-1][j];
                }
            }

            if(crt_map[i][j] == 'u'-'a'){
                // row[2][i] ++;
                // col[2][j] ++;

                if(j > 0){
                    pre_sum_col[2][i][j] = pre_sum_col[2][i][j-1] + 1;
                }else{
                    pre_sum_col[2][i][j] = 1;
                }
                if(i > 0){
                    pre_sum_row[2][i][j] = pre_sum_row[2][i-1][j] + 1;
                }else{
                    pre_sum_row[2][i][j] = 1;
                }
            }else{
                if(j > 0){
                    pre_sum_col[2][i][j] = pre_sum_col[2][i][j-1];
                }
                if(i > 0){
                    pre_sum_row[2][i][j] = pre_sum_row[2][i-1][j];
                }
            }

        }
    }

    // for(int i=0; i<3; i++){
    //     for(int j=0; j<m; j++){
    //         cout << pre_sum_row[i][j] << " ";

    //     }
    //     cout << endl;
    // }

    // cout << endl;
    // for(int i=0; i<3; i++){
    //     for(int j=0; j<n; j++){
    //         cout << pre_sum_col[i][j] << " ";

    //     }
    //     cout << endl;
    // }
    // exit(0);
    



    ll ans = 0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(crt_map[i][j] == 'y'-'a'){
                ans +=  cal_tri(1, i-1, 2, j-1, m, n, i, j) + cal_tri(1, i+1, 2, j-1, m, n, i, j) +
                        cal_tri(1, i-1, 2, j+1, m, n, i, j) + cal_tri(1, i+1, 2, j+1, m, n, i, j);

                ans +=  cal_tri(2, i-1, 1, j-1, m, n, i, j) + cal_tri(2, i+1, 1, j-1, m, n, i, j) +
                        cal_tri(2, i-1, 1, j+1, m, n, i, j) + cal_tri(2, i+1, 1, j+1, m, n, i, j);
            }else if (crt_map[i][j] == 'o'-'a'){
                ans +=  cal_tri(0, i-1, 2, j-1, m, n, i, j) + cal_tri(0, i+1, 2, j-1, m, n, i, j) +
                        cal_tri(0, i-1, 2, j+1, m, n, i, j) + cal_tri(0, i+1, 2, j+1, m, n, i, j);

                ans +=  cal_tri(2, i-1, 0, j-1, m, n, i, j) + cal_tri(2, i+1, 0, j-1, m, n, i, j) +
                        cal_tri(2, i-1, 0, j+1, m, n, i, j) + cal_tri(2, i+1, 0, j+1, m, n, i, j);

            }else if (crt_map[i][j] == 'u'-'a'){
                ans +=  cal_tri(0, i-1, 1, j-1, m, n, i, j) + cal_tri(0, i+1, 1, j-1, m, n, i, j) +
                        cal_tri(0, i-1, 1, j+1, m, n, i, j) + cal_tri(0, i+1, 1, j+1, m, n, i, j);

                ans +=  cal_tri(1, i-1, 0, j-1, m, n, i, j) + cal_tri(1, i+1, 0, j-1, m, n, i, j) +
                        cal_tri(1, i-1, 0, j+1, m, n, i, j) + cal_tri(1, i+1, 0, j+1, m, n, i, j);

            }
        }
    }

    cout << ans << endl;

    return 0;
}