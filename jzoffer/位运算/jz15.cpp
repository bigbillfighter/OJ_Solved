#include <bits/stdc++.h>
using namespace std;

int main(){
    int nbr;
    cin >> nbr;
    // write code here
    int check = 1<<31;
    int rst = (check & nbr) != 0 ? 1 : 0;

    while(nbr<<1){
        nbr = nbr<<1;
        rst += (check & nbr) != 0 ? 1 : 0;
    }

    cout << rst << endl;
    return 0;
}