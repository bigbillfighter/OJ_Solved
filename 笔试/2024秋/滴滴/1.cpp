#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    int n, m;
    vector<int> rst;
    for(int i=0; i<T; i++){
        cin >> n >> m;
        if(n == 1){
            rst.push_back(0);
        }else if(n==2){
            rst.push_back(m); 
        }else{
            rst.push_back(m*2);
        }
    }
    for(int i=0; i<T; i++){
        cout << rst[i] << " ";
    }
    cout << endl;

    return 0;
}