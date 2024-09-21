#include<bits/stdc++.h>
using namespace std;

const int max_n = 1e5+5;
vector<int> grid[max_n];
typedef long long LL;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    int first, second;

    int min_nbr = 0x3f3f3f3f;
    for(int i=0; i<n-1; i++){
        cin >> first >> second;
        min_nbr = min(min_nbr, first);
        min_nbr = min(min_nbr, second);
        if(first < second){
            grid[first].push_back(second);
        }else{
            grid[second].push_back(first);
        }
    }

    int fg=0, sg=0;
    queue<int> qe;
    qe.push(min_nbr);
    fg ++;
    int cur = 1;

    while(!qe.empty()){
        int cur_size = qe.size();
        for(int i=0; i<cur_size; i++){
            int key = qe.front();
            qe.pop();

            if(cur%2==1){
                if(grid[key].size() > 0){
                    sg += grid[key].size();
                    for(int j=0; j<grid[key].size(); j++){
                        qe.push(grid[key][j]);
                    }
                }
            }else{
                if(grid[key].size() > 0){
                    fg += grid[key].size();
                    for(int j=0; j<grid[key].size(); j++){
                        qe.push(grid[key][j]);
                    }
                }
            }
        }

        cur ++;

    }
    LL ans = (LL)fg * (LL)sg - n + 1;
    cout <<  ans << endl;
    return 0;
}