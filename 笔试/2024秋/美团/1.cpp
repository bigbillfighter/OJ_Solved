#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, a, b, c;
    cin >> n >> a >> b >> c;

    int cont = max(max(a, b), c);
    cout << (n-1) / cont + 1 << endl;

    return 0;
}