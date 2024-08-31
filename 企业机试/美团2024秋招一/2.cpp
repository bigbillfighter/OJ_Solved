#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    string passwd; cin >> passwd;

    int len = passwd.size();
    string first;
    int min_times=0, max_times = 0;
    map<string, bool> tried;
    for(int i=0; i<n; i++){
        cin >> first;
        if(!tried.count(first)){
            tried[first] = true;
            if(first.size() < len){
                min_times++; max_times++;
            }else if(first.size() == len){
                max_times++;
            }
        }
    }
    min_times++;
    cout << min_times << " " << max_times << endl;
    

    return 0;
}