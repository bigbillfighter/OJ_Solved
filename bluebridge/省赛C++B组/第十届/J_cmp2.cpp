#include<iostream> 
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
typedef long long ll;
const int maxn = 3e5+10;
ll s[maxn]; 
ll a[maxn];
bool vis[maxn];
int main(){
    int t;scanf("%d",&t);
    while(t--){
        memset(s,0,sizeof(s));
        memset(vis,0,sizeof(vis));
        int n;scanf("%d",&n);
        for(int i = 1;i<=n;i++){
            scanf("%lld",&s[i]);
            s[i]+=s[i-1];// 计算总和
        }
        ll s0 = s[0],sn=s[n];
        if(s0>sn) swap(s0,sn);
        sort(s,s+n+1);// 排序记得0
        for(int i = 0;i<=n;i++){
            if(s[i]==s0){
                s0=i;
                break;
            }
        }
        for(int i = n;i>=0;i--){
            if(s[i]==sn){
                sn = i;
                break;
            }
        }
        
        int l = 0,r = n;
        for(int i = s0;i>=0;i-=2){
            a[l++]=s[i];
            vis[i]=1;
        }
        for(int i = sn;i<=n;i+=2){
            a[r--]=s[i];
            vis[i]=1;
        }
        
        for(int i = 0;i<=n;i++){
            if(!vis[i]){
                a[l++]=s[i];
            }
        }
        
        ll ans = 0;
        for(int i = 1;i<=n;i++){
            ans = max(ans,abs(a[i]-a[i-1]));
        }
        printf("%lld\n",ans);
    }
    return 0;
}
