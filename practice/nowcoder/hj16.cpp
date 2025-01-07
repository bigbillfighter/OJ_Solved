#include <bits/stdc++.h>
using namespace std;


const int max_n = 62;

int father[max_n] = {0};
int importance[max_n] = {0};
int value[max_n] = {0};

const int max_v = 32005;
int dp[max_v] = {0};

int find_best(int crt){
    if(crt==0) return dp[0] = 0;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, nbr;
    cin >> n >> nbr;

    int _value, _importance, _father;
    for(int i=0; i<nbr; i++){
        cin >> _value >> _importance >> _father;
        father[i] = _father;
        importance[i] = _importance;
        value[i] = _value;
    }

    cout << find_best(n/10*10) << endl;
    return 0;
}