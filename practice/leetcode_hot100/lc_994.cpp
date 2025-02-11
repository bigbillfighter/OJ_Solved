#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int time = 0;
        int row = grid.size(), col = grid[0].size();
        int nbr = 0;
        vector<pair<int, int> > rot_orange;
        int idx = 0;
        int rot_nbr_last;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] == 1 || grid[i][j] == 2) nbr ++;
                if(grid[i][j] == 2) rot_orange.push_back(make_pair(i, j));
            }
        }
        if(rot_orange.size() == nbr) return 0;
        if(rot_orange.size() == 0) return -1;
        int crt_x, crt_y;
        do{
            rot_nbr_last = rot_orange.size();
            for(int i=idx; i<rot_nbr_last; i++){
                crt_x = rot_orange[i].first;
                crt_y = rot_orange[i].second;
                if(crt_x > 0){
                    if(grid[crt_x-1][crt_y] == 1){
                        grid[crt_x-1][crt_y] = 2;
                        rot_orange.push_back(make_pair(crt_x-1, crt_y));
                    } 
                }
                if(crt_y > 0){
                    if(grid[crt_x][crt_y-1] == 1){
                        grid[crt_x][crt_y-1] = 2;
                        rot_orange.push_back(make_pair(crt_x, crt_y-1));
                    } 
                }
                if(crt_x < row-1){
                    if(grid[crt_x+1][crt_y] == 1){
                        grid[crt_x+1][crt_y] = 2;
                        rot_orange.push_back(make_pair(crt_x+1, crt_y));
                    } 
                }
                if(crt_y < col-1){
                    if(grid[crt_x][crt_y+1] == 1){
                        grid[crt_x][crt_y+1] = 2;
                        rot_orange.push_back(make_pair(crt_x, crt_y+1));
                    } 
                }
            }
            idx = rot_nbr_last;
            time ++;
        }while(rot_orange.size() < nbr && rot_nbr_last != rot_orange.size());

        if(rot_orange.size() != nbr){
            return -1;
        }else{
            return time;
        }
    }
};