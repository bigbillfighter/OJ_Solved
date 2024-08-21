#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > rst;
        vector<vector<string> > outputs;
        for(int i=0; i<strs.size(); i++){
            string ss = strs[i];
            sort(ss.begin(), ss.end());
            rst[ss].push_back(strs[i]);
        }
        for(unordered_map<string, vector<string> >::iterator it=rst.begin(); it != rst.end(); it++){
            outputs.push_back(it->second);
        }
        return outputs;
    }
};


int main(){
    // improve io speed
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    Solution solu;

    int m;
    cin >> m;
    vector<string> strs;
    for(int i=0; i<m; i++){
        string ss;
        cin >> ss;
        strs.push_back(ss);
    }

    vector<vector<string> > rst = solu.groupAnagrams(strs);
    for(int i=0; i<rst.size(); i++){
        for(int j=0; j<rst[i].size(); j++){
            cout << rst[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}