#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int arr[9];
    vector<string> crt;
    vector<vector<string> > ans;
public:
    string genLine(int idx, int len){
        string rst(len, '.');
        rst[idx] = 'Q';
        return rst;
    }

    void check_queen(int idx, int len){
        if(idx >= len){
            ans.push_back(crt);
            return;
        }

        unordered_set<int> not_choose;
        for(int i=0; i<idx; i++){
            not_choose.insert(arr[i]);

            if(arr[i] + idx - i < len) not_choose.insert(arr[i] + idx - i);
            if(arr[i] + i - idx >= 0) not_choose.insert(arr[i] + i - idx);
        }

        for(int i=0; i<len; i++){
            if(not_choose.find(i) != not_choose.end()){
            }else{
                arr[idx] = i;
                crt.push_back(genLine(i, len));
                check_queen(idx+1, len);
                crt.pop_back();
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        for(int i=0; i<n; i++){
            crt.clear();
            arr[0] = i;
            crt.push_back(genLine(i, n));
            check_queen(1, n);
        }
        return ans;
    }
};