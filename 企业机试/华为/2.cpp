#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    set<int> set_data;
    int rd;
    for(int i=0; i<n; i++){
        cin >> rd;
        set_data.insert(rd);
    }
    vector<int> rst;
    for(set<int>::iterator p=set_data.begin(); p!=set_data.end(); p++){
        rst.push_back(*p);
    }

    sort(rst.begin(), rst.end());
    for(int i=0; i<rst.size(); i++){
        cout << rst[i] << endl;
        
    }

    return 0;
}