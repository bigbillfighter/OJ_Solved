#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param firstList int整型vector<vector<>> 
     * @param secondList int整型vector<vector<>> 
     * @return int整型vector<vector<>>
     */
    vector<vector<int> > findIntersection(vector<vector<int> >& firstList, vector<vector<int> >& secondList) {
        // write code here
        vector<vector<int> > ans;

        int first_idx = 0, second_idx = 0;

        int first_len = firstList.size(), second_len = secondList.size();
        while(first_idx < first_len && second_idx < second_len){
            if(firstList[first_idx][1] <= secondList[second_idx][1]){
                if(firstList[first_idx][1] >= secondList[second_idx][0]){
                    vector<int> tmp;
                    tmp.push_back(max(firstList[first_idx][0], secondList[second_idx][0]));
                    tmp.push_back(firstList[first_idx][1]);
                    ans.push_back(tmp);
                }

                first_idx ++;

            }else{
                if(secondList[second_idx][1] >= firstList[first_idx][0]){
                    vector<int> tmp;
                    tmp.push_back(max(firstList[first_idx][0], secondList[second_idx][0]));
                    tmp.push_back(secondList[second_idx][1]);
                    ans.push_back(tmp);

                }
                second_idx ++;

            }

        }

        return ans;


    }
};