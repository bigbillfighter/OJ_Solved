#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxSales(vector<int>& sales) {
        int max_val = -200;
        for(int i=0; i<sales.size(); i++){
            if(sales[i] > max_val) max_val = sales[i];
        }
        if(max_val < 0) return max_val;

        for(int i=0; i<sales.size(); i++){
            int tmp=sales[i];
            if(tmp<0) continue;
            for(int j=i+1; j<sales.size(); j++){
                tmp = tmp + sales[j];
                if(tmp < 0){
                    i = j;
                    break;
                }else{
                    max_val = max(max_val, tmp);
                }
            }
        }
        return max_val;
    }
};


int main(){
    // improve is speed
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    Solution solu;
    vector<int> sales;
    int days;
    cin>>days;
    int sale;
    for(int i=0; i<days; i++){
        cin >> sale;
        sales.push_back(sale);
    }

    int rst = solu.maxSales(sales);
    cout << rst << endl;
    return 0;
}