//ת��Ϊ��������
 
#include <iostream>
#include <cstdio>
using namespace std;

const int mod = 1e9;
const int Maxn = 1e6+5;

int n;
int w[Maxn];
int cnt=0;
int dp[Maxn];

int main(){
    scanf("%d",&n);
    for(int i=0;(1<<i)<=n;i++)//����������Ʒ
        w[cnt++]=(1<<i);
    dp[0]=1;
    for(int i=0;i<cnt;i++)
        for(int j=w[i];j<=n;j++)
            dp[j]=(dp[j]+dp[j-w[i]])%mod;//ȡ��

    printf("%d\n",dp[n]);
    return 0;
}
