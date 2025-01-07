/*
经典的二次幂和问题, 整数划分问题的一个变种
dp[i]:二次幂划分数
i为奇数，这时，只能是dp[i-1]的每一个划分前面加一个1，所以dp[i] = dp[i-1]
i为偶数，这时，可以有全部不含1的划分，所以可以是dp[i-1]+dp[i/2], dp[i-1]意味着将i-1的划分前面加一个1，就得到dp[i]含有1
的划分，将dp[i/2]的划分都乘以2得到dp[i]不含1的划分 
*/

#include <cstdio>
#include <iostream>


using namespace std;
typedef  long long LL;
const int maxn = 1e6+5;
const int mod = 1e9;

int dp[maxn], n;

int main(){
    cin >> n;
    dp[1] = dp[0] = 1;
    
    for(int i = 2; i <= n; ++i){
        if(i%2==1)
            dp[i] = dp[i-1];
        else
            dp[i] = (dp[i-2]+dp[i/2])%mod;
    }
    cout << dp[n] << endl;
	return 0;
}
