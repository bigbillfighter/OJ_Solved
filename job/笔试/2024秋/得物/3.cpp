#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<pair<int, int>> pre;
    vector<pair<int, int>> card;
    int a, b, c, d;
    for(int i=0; i<n; i++){
        cin >> a >> b >> c >> d;
        pair<int, int> p(a, b), cd(c, d);
        pre.push_back(p);
        card.push_back(cd);
    }

    int k = 1;
    do{
        vector<int> idxes;
        for(int i=0; i<n; i++){
            idxes.push_back(i);
        }

        do{
            bool flag = true;
            for(int i=0; i<n; i++){
                if(pre[i].first > k * card[idxes[i]].first || pre[i].second > k * card[idxes[i]].second){
                    flag = false;
                    break;
                }
            }

            if(flag){
                cout << k << endl;
                return 0;
            }

        }while(next_permutation(idxes.begin(), idxes.end()));

    }while(++k);

    return 0;
}