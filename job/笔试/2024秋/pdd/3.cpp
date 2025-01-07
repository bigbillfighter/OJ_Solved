#include<bits/stdc++.h>
using namespace std;

int a[12];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    int n;
    while(t--){
        cin >> n;
        int dict_size = 0;
        map<int, int> times;

        for(int i=0; i<n; i++){
            cin >> a[i];
            if(times.count(a[i])){
                times[a[i]] ++;
            }else{
                dict_size ++;
                times[a[i]] = 1;
            }
        } 

        if(n==1){
            if(a[0] == 0) cout << "yes" << endl;
            else cout << "no" << endl;
        }else{
            if(dict_size < n){
                cout << "yes" << endl;
            }else{
                if(times.count(0)){
                    cout << "yes" << endl;
                }else{
                    int flag = false;
                    for(int i=0; i<n-1; i++){
                        for(int j=i+1; j<n; j++){
                            if(times.count(a[i] - a[j]) || times.count(a[j] - a[i])){
                                flag = true;
                                break;
                            }
                        }
                    }
                    if(flag){
                        cout << "yes" << endl;
                    }else{
                        cout << "no" << endl;
                    }   
                }


            }
        }
    }

    return 0;
}