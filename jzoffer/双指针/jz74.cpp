#include <bits/stdc++.h>
using namespace std;

const int max_n = 102;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param sum int整型 
     * @return int整型vector<vector<>>
     */
    vector<vector<int> > FindContinuousSequence(int sum) {
        // write code here
        vector<vector<int> > rst;
        int crt_sum = 0;
        int arr[max_n] = {0};
        for(int i=0; i<sum-1; i++){
            arr[i] = i+1;
        }

        int start_pt=0, end_pt=0;
        for(int i=0; i<sum-1; i++){
            crt_sum += i+1;
            end_pt += 1;
            if(crt_sum == sum){
                vector<int> rst_sample;
                for(int j=start_pt; j<end_pt; j++){
                    rst_sample.push_back(j+1);
                }
                rst.push_back(rst_sample);
            }else if(crt_sum > sum){
                while(crt_sum > sum && start_pt < end_pt){
                    crt_sum -= start_pt+1;
                    start_pt += 1;
                }
                if(start_pt < end_pt && crt_sum == sum){
                    vector<int> rst_sample;
                    for(int j=start_pt; j<end_pt; j++){
                        rst_sample.push_back(j+1);
                    }
                    rst.push_back(rst_sample);
                }
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

    int nbr;
    cin >> nbr;
    
    vector<vector<int> > rst = solu.FindContinuousSequence(nbr);

    for(int i=0; i<rst.size(); i++){
        for(int j=0; j<rst[i].size(); j++){
            cout << rst[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}