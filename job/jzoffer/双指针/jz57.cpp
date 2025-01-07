#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        map<int, int> count_map;
        vector<int> rst;
        for(int i=0; i<array.size(); i++){
            if(count_map.count(sum-array[i])){
                rst.push_back(sum-array[i]);
                rst.push_back(array[i]);
                return rst;
            }else{
                count_map[array[i]] = 1;
            }
        }
        return rst;
    }
};


int main(){
    // improve is speed
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    Solution solu;

    int length;
    cin >> length;
    vector<int> array;
    int sum;
    cin >> sum;
    
    int array_data;
    for(int i=0; i<length; i++){
        cin>>array_data;
        array.push_back(array_data);
    }

    vector<int> rst = solu.FindNumbersWithSum(array, sum);
    for(int i=0; i<rst.size(); i++){
        cout << rst[i] << " ";
    }
    cout << endl;

    return 0;
}