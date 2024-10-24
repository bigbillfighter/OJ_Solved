#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k, q;
    cin >> n >> m >> k >> q;
    map<int, vector<int> > row, col;
    map<int, pair<int, int> > points;
    int x, y;
    for(int i=0; i<k; i++){
        cin >> x >> y;
        if(row.count(x-1)) row[x-1].push_back(y-1);
        else{
            vector<int> crt = {y-1};
            row[x-1] = crt;
        }

        if(col.count(y-1)) col[y-1].push_back(x-1);
        else{
            vector<int> crt = {x-1};
            row[y-1] = crt;
        }
        points[i] = make_pair(x-1, y-1);
    }

    for(map<int, vector<int>>::iterator p = row.begin(); p!=row.end(); p++){
        sort(p->second.begin(), p->second.end());
    }

    for(map<int, vector<int>>::iterator p = col.begin(); p!=col.end(); p++){
        sort(p->second.begin(), p->second.end());
    }

    int idx; string direc;
    
    int crt_x, crt_y;
    int pos, new_x, new_y;
    int crt_vec;
    for(int i=0; i<q; i++){
        cin >> idx >> direc;
        idx -= 1;
        crt_x = points[idx].first;
        crt_y = points[idx].second;

        if(direc[0] == 'L'){
            pos  = lower_bound(row[crt_x].begin(), row[crt_x].end(), crt_y) - row[crt_x].begin();
            if(pos == 0){
                row[crt_x][pos] = 0;
                points[idx].second = 0;
            }else{
                row[crt_x][pos] = row[crt_x][pos-1] + 1;
                points[idx].second = row[crt_x][pos-1] + 1;
            }

            pos = lower_bound(col[crt_y].begin(), col[crt_y].end(), crt_x) - col[crt_y].begin();
            col[crt_y].erase(col[crt_y].begin() + pos);
            if(col[crt_y].size() == 0) col.erase(crt_y);

            new_y = row[crt_x][pos];
            if(!col.count(new_y)){
                vector<int> crt = {crt_x};
                col[new_y] = crt;
            }else{
                pos = lower_bound(col[new_y].begin(), col[new_y].end(), crt_x) - col[new_y].begin();
                col[new_y].insert(col[new_y].begin() + pos, crt_x);
            }


        }else if(direc[0] == 'R'){
            pos  = lower_bound(row[crt_x].begin(), row[crt_x].end(), crt_y) - row[crt_x].begin();
            if(pos == row[crt_x].size() - 1){
                row[crt_x][pos] = n-1;
                points[idx].second = n-1;
            }else{
                row[crt_x][pos] = row[crt_x][pos+1] - 1;
                points[idx].second = row[crt_x][pos+1] - 1;
            }

            pos = lower_bound(col[crt_y].begin(), col[crt_y].end(), crt_x) - col[crt_y].begin();
            col[crt_y].erase(col[crt_y].begin() + pos);
            if(col[crt_y].size() == 0) col.erase(crt_y);

            new_y = row[crt_x][pos];
            if(!col.count(new_y)){
                vector<int> crt = {crt_x};
                col[new_y] = crt;
            }else{
                pos = lower_bound(col[new_y].begin(), col[new_y].end(), crt_x) - col[new_y].begin();
                col[new_y].insert(col[new_y].begin() + pos, crt_x);
            }



        }else if(direc[0] == 'U'){
            pos  = lower_bound(col[crt_y].begin(), col[crt_y].end(), crt_x) - col[crt_y].begin();
            if(pos == col[crt_y].size() - 1){
                col[crt_y][pos] = col[crt_y].size() - 1;
                points[idx].first = col[crt_y].size() - 1;
            }else{
                col[crt_y][pos] = col[crt_y][pos+1] - 1;
                points[idx].first = col[crt_y][pos+1] - 1;
            }

            pos = lower_bound(row[crt_x].begin(), row[crt_x].end(), crt_y) - row[crt_x].begin();
            row[crt_x].erase(row[crt_x].begin() + pos);
            if(row[crt_x].size() == 0) row.erase(crt_x);

            new_x = col[crt_y][pos];
            if(!row.count(new_x)){
                vector<int> crt = {crt_y};
                row[new_x] = crt;
            }else{
                pos = lower_bound(row[new_x].begin(), row[new_x].end(), crt_y) - row[new_x].begin();
                row[new_x].insert(row[new_x].begin() + pos, crt_y);
            }


        }else if(direc[0] == 'D'){
        
            pos  = lower_bound(col[crt_y].begin(), col[crt_y].end(), crt_x) - col[crt_y].begin();
            if(pos == m-1){
                col[crt_y][pos] = 0;
                points[idx].first = 0;
            }else{
                col[crt_y][pos] = col[crt_y][pos-1] + 1;
                points[idx].first = col[crt_y][pos-1] + 1;
            }

            pos = lower_bound(row[crt_x].begin(), row[crt_x].end(), crt_y) - row[crt_x].begin();
            row[crt_x].erase(row[crt_x].begin() + pos);
            if(row[crt_x].size() == 0) row.erase(crt_x);

            new_x = col[crt_y][pos];
            if(!row.count(new_x)){
                vector<int> crt = {crt_y};
                row[new_x] = crt;
            }else{
                pos = lower_bound(row[new_x].begin(), row[new_x].end(), crt_y) - row[new_x].begin();
                row[new_x].insert(row[new_x].begin() + pos, crt_y);
            }


        }
    }

    for(int i=0; i< k ; i++){
        cout << points[i].first << " " << points[i].second << endl;
    }


    return 0;
}