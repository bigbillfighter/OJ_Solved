#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> rst;
    void Insert(int num) {
        rst.push_back(num);
        for(int i=0; i<rst.size()-1; i++){
            if(num < rst[i]){
                for(int j=rst.size()-1; j>=i; j--){
                    rst[j+1] = rst[j];
                }
                rst[i]=num;
                break;
            }
        }
    }

    double GetMedian() { 
        double up = 0.0;
        if(rst.size()%2){
            up = rst[rst.size()/2];
        }else{
            up = (up + rst[rst.size()/2 - 1] + rst[rst.size()/2]) / 2;
        }
        return up;
    }

};

int main(){
    // improve is speed
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    Solution solu;

    int length;
    cin >> length;
    vector<int> arr;
    
    int arr_data;
    for(int i=0; i<length; i++){
        cin>>arr_data;
        arr.push_back(arr_data);
    }

    double med;
    for(int i=0; i<length; i++){
        solu.Insert(arr[i]);
        med = solu.GetMedian();
        printf("%.2f\n", med);
    }
    return 0;
}