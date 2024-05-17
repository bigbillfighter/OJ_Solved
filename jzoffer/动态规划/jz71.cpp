#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param number int整型 
     * @return int整型
     */

    int jumpFloorII(int number) {
        return 1<<(number-1);
    }
};


int main(){
    // improve is speed
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    Solution solu;

    int number;
    cin>>number;
    int rst = solu.jumpFloorII(number);
    cout << rst << endl;
    return 0;
}