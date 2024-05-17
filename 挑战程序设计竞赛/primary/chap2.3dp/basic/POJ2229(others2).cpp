/*
����Ķ����ݺ�����, �������������һ������
dp[i]:�����ݻ�����
iΪ��������ʱ��ֻ����dp[i-1]��ÿһ������ǰ���һ��1������dp[i] = dp[i-1]
iΪż������ʱ��������ȫ������1�Ļ��֣����Կ�����dp[i-1]+dp[i/2], dp[i-1]��ζ�Ž�i-1�Ļ���ǰ���һ��1���͵õ�dp[i]����1
�Ļ��֣���dp[i/2]�Ļ��ֶ�����2�õ�dp[i]����1�Ļ��� 
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
