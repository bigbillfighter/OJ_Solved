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
    int jumpFloor(int number) {
        // write code here
        if(number == 1){
            return 1;
        }else if (number == 2){
            return 2;
        }else return jumpFloor(number-1) + jumpFloor(number-2);
    }
};


int main(){
    // improve is speed
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    Solution solu;
    int n;
    cin >> n;
    int rst = solu.jumpFloor(n);
    cout << rst << endl;
    return 0;
}