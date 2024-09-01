#include<bits/stdc++.h>
using namespace std;

const int max_n = 2e5+5;
int a[max_n];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q; cin >> n >> q;
    for(int i=0; i<n; i++) cin >> a[i];
    char c; int x;
    map<int, bool> occur;

    int left = 0, right = n-1;
    for(int i=0; i<q; i++){
        cin >> c; cin >> x;
        occur.clear();
        
        int nbr = 0;
        if(c == 'L'){
            while(x--){
                if(!occur.count(a[left])){
                    occur[a[left]] = true;
                    nbr ++ ;
                }
                left = (left+1) % n;
            }
        }else{
            while(x--){
                if(!occur.count(a[right])){
                    occur[a[right]] = true;
                    nbr ++ ;
                }
                right = (right-1+n) % n;
            }
        }

        cout << nbr << endl;

    }


    return 0;
}