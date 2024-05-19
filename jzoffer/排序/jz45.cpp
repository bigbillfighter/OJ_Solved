#include <bits/stdc++.h>
using namespace std;

const int max_len = 102;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param numbers int整型vector 
     * @return string字符串
     */
    int rst[max_len] = {-1};

    string v2s(int arr_size){
        stringstream sstream;
        for(int i=0; i<arr_size; i++){
            sstream << rst[i]; 
        }
        string ss = sstream.str();
        return ss;
    }

    void find_best(int number, int length){
        int place = -1;
        for(int i = 0; i<length-1; i++){
            if (to_string(number) + to_string(rst[i]) <= to_string(rst[i]) + to_string(number)){
                place = i;
                break;
            }
        }
        if(place==-1){
            place = length-1;
        }

        for(int i=length-1; i>place; i--){
            rst[i] = rst[i-1];
        }
        rst[place] = number;
    }

    string PrintMinNumber(vector<int>& numbers) {
        // write code here
        if(numbers.size() == 0) return "";

        sort(numbers.begin(), numbers.end());
        rst[0] = numbers[0];
        
        for(int i=1; i<numbers.size(); i++){
            find_best(numbers[i], i+1);
        }
        return v2s(numbers.size());
    }
};


int main(){
    // improve is speed
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    Solution solu;
    int n;
    int ndata;
    cin >> n;
    vector<int > numbers;
    
    for(int i=0; i<n; i++){
        cin >> ndata;
        numbers.push_back(ndata);
    }

    string rst = solu.PrintMinNumber(numbers);
    cout << rst << endl;
    return 0;
}