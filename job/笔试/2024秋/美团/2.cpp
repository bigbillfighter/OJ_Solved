#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string str; cin >> str;
    vector<int> vlen[3];

    int cur;
    int n = str.size();
    for(int i=0; i<n; i++){
        if(str[i] == 'R'){
            cur = i-1;
            while(cur>=0){
                if(str[cur] == '#') break;
                else{
                    if(str[cur] == 'B' || str[cur] == 'G'){
                        vlen[0].push_back(i-cur);
                        break;
                    }
                }
                cur --;
            }

            cur = i+1;
            while(cur<n){
                if(str[cur] == '#') break;
                else{
                    if(str[cur] == 'B' || str[cur] == 'G'){
                        vlen[0].push_back(cur-i);
                        break;
                    }
                }
                cur ++;
            }


        }else if(str[i] == 'B'){

            cur = i-1;
            while(cur>=0){
                if(str[cur] == '#') break;
                else{
                    if(str[cur] == 'R' || str[cur] == 'G'){
                        vlen[1].push_back(i-cur);
                        break;
                    }
                }
                cur --;
            }

            cur = i+1;
            while(cur<n){
                if(str[cur] == '#') break;
                else{
                    if(str[cur] == 'R' || str[cur] == 'G'){
                        vlen[1].push_back(cur-i);
                        break;
                    }
                }
                cur ++;
            }


        }else if(str[i] == 'G'){

            cur = i-1;
            while(cur>=0){
                if(str[cur] == '#') break;
                else{
                    if(str[cur] == 'B' || str[cur] == 'R'){
                        vlen[2].push_back(i-cur);
                        break;
                    }
                }
                cur --;
            }

            cur = i+1;
            while(cur<n){
                if(str[cur] == '#') break;
                else{
                    if(str[cur] == 'B' || str[cur] == 'R'){
                        vlen[2].push_back(cur-i);
                        break;
                    }
                }
                cur ++;
            }

        }
    }

    if(vlen[0].size() > 0){
        int min_len = vlen[0][0];
        for(int i=1; i<vlen[0].size(); i++){
            min_len = min(min_len, vlen[0][i]);
        }
        cout << min_len << " ";
    }else{
        cout << -1 << " ";
    }

    if(vlen[1].size() > 0){
        int min_len = vlen[1][0];
        for(int i=1; i<vlen[1].size(); i++){
            min_len = min(min_len, vlen[1][i]);
        }
        cout << min_len << " ";
    }else{
        cout << -1 << " ";
    }

    if(vlen[2].size() > 0){
        int min_len = vlen[2][0];
        for(int i=1; i<vlen[2].size(); i++){
            min_len = min(min_len, vlen[2][i]);
        }
        cout << min_len << endl;
    }else{
        cout << -1 << endl;
    }

    return 0;
}