#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s, a, b;
    cin >> s >> a >> b;
    char c = a[0] - 'A' + 'a';
    a =  c + a.substr(1, a.size()-1);
    c = b[0] - 'A' + 'a';
    b = c + b.substr(1, b.size()-1);
    map<char, int> ctimes, actimes, bctimes;
    for(int i=0; i<s.size(); i++){
        if(ctimes.count(s[i])) ctimes[s[i]] ++;
        else ctimes[s[i]] = 1;
    }
    for(int i=0; i<a.size(); i++){
        if(actimes.count(a[i])) actimes[a[i]] ++;
        else actimes[a[i]] = 1;
    }
    for(int i=0; i<b.size(); i++){
        if(bctimes.count(b[i])) bctimes[b[i]] ++;
        else bctimes[b[i]] = 1;
    } 

    int ans = 0;
    int amax_times = 0x3f3f3f3f, bmax_times;
    for(map<char, int>::iterator p = actimes.begin(); p!=actimes.end(); p++){
        char key = p->first;
        int ktime = p->second;

        if(ctimes.count(key)){
            amax_times = min(amax_times, ctimes[key] / ktime);
        }else{  
            amax_times = 0;
            break;
        }
    }

    for(int i=0; i<=amax_times; i++){
        bmax_times = 0x3f3f3f3f;
        for(map<char, int>::iterator p = bctimes.begin(); p!=bctimes.end(); p++){
            char key = p->first;
            int ktime = p->second;

            if(ctimes.count(key)){
                if(actimes.count(key)){
                    bmax_times = min(bmax_times, (ctimes[key] - i * actimes[key]) / ktime);
                }else{
                    bmax_times = min(bmax_times, ctimes[key] / ktime);
                }

            }else{
                bmax_times = 0;
                break;
            }
        }
        ans = max(ans, i+bmax_times);
    }

    cout << ans;
    return 0;
}