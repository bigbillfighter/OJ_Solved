#include<bits/stdc++.h>
using namespace std;

const int max_n = 1e3+5;

string rk;
map<char, int> char_rank;
string ss[max_n];

bool my_cmp(const string& s1, const string& s2){
    int s1_len = s1.size(), s2_len = s2.size();
    if(s1_len == 0) return true;
    if(s2_len == 0) return false;

    int min_len = min(s1_len, s2_len);
    for(int i=0; i<min_len; i++){
        if(char_rank[s1[i]] < char_rank[s2[i]]) return true;
        if(char_rank[s1[i]] > char_rank[s2[i]]) return false; 
    }

    if(s1_len <= s2_len) return true;
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> rk;
    for(int i=0; i<rk.size(); i++){
        char_rank[rk[i]] = i;
    }

    int n; cin >> n;
    for(int i=0; i<n; i++){
        cin >> ss[i];
    }

    sort(ss, ss+n, my_cmp);
    for(int i=0; i<n; i++){
        cout << ss[i] << endl;
    }

    return 0;
}