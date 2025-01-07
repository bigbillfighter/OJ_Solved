#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T; cin >> T;
    while(T--){
        string s, t;
        cin >> s; cin >> t;
        int len = s.size();

        bool flag = false;
        
        for(int i=0; i<len; i++){
            int start = 0;
            while(start < len && s[start] == t[(i+start) % len]) start ++;

            if(start == len){
                flag = true;
                break;
            }
        }
        
        if(flag){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }

    }
    
    return 0;
}

