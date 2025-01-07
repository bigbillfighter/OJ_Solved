#include<bits/stdc++.h>
using namespace std;

bool cmp_pair(const pair<int, int>& p1, const pair<int, int>& p2){
    return (p1.second) < (p2.second);
}

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param s string字符串 
     * @param k int整型 
     * @return int整型
     */
    int compressString(string s, int k) {
        // write code here
        int size = s.size();
        if(size == 0) return 0;        
        
        map<int, int> ccounts;
        int start_key = 0;
        ccounts[start_key] = 1;
        for(int i=1; i<size; i++){
            if(s[i] == s[i-1]){
                ccounts[start_key] ++ ;
            }else{
                ccounts[++start_key] = 1;
            }
        }
        vector<pair<int, int> > times;
        for(map<int, int>::iterator p = ccounts.begin(); p!=ccounts.end(); p++){
            times.push_back(make_pair(p->first, p->second));
        }
        sort(times.begin(), times.end(), cmp_pair);
        
        // for(int i=0; i<times.size(); i++){
        //     cout << times[i].first << " " << times[i].second << endl;
        // }

        for(int i=0; i<times.size(); i++){
            if(k > times[i].second) {
                k -= times[i].second;
                times[i].second = 0;
            }else{
                times[i].second -= k;
                k = 0;
            }
        }

        int len = 0;
        for(int i=0; i<times.size(); i++){
            if(times[i].second > 0){
                if(times[i].second == 1){
                    len += 1;
                }else if(times[i].second < 10){
                    len += 2;
                }else if(times[i].second < 100){
                    len += 3;
                }else{
                    len += 4;
                }
            }
        }
        cout << len << endl;
        return len;

    }
};

int main(){

    string s;
    int k;
    Solution solu;
    cin >> s;
    cin >> k;
    solu.compressString(s, k);
    return 0;
}