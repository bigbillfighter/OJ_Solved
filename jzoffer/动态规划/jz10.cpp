#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param n int整型 
     * @return int整型
     */
    int Fibonacci(int n) {
        // write code here
        int f1=1, f2=1;
        if (n==1){
            return 1;
        }else if (n==2){
            return 1;
        }else{
            for(int i=0; i<n-2; i++){
                int rst = f1 + f2;
                f1 = f2;
                f2 = rst;
            }
            return f2;
        }

    }
};


int main(){
    // improve is speed
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    Solution solu;
    int n;
    cin >> n;
    int rst = solu.Fibonacci(n);
    cout << rst << endl;
    return 0;
}