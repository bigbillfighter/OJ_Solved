#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const double Pi = acos(-1);
namespace {
  template <typename T> inline void read(T &x) {
    x = 0; T f = 1;char s = getchar();
    for(; !isdigit(s); s = getchar()) if(s == '-') f = -1;
    for(;  isdigit(s); s = getchar()) x = (x << 3) + (x << 1) + (s ^ 48);
    x *= f;
  }
}
#define fio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define _for(n,m,i) for (register int i = (n); i <  (m); ++i)
#define _rep(n,m,i) for (register int i = (n); i <= (m); ++i)
#define _srep(n,m,i)for (register int i = (n); i >= (m); i--)
#define _sfor(n,m,i)for (register int i = (n); i >  (m); i--)
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
#define lowbit(x) x & (-x)
#define pii pair<int,int>
#define fi first
#define se second
const int N = 1e6+5;
LL a[N];
LL ans[N];
bool vis[N];
LL Abs(LL x) {
  return x < 0 ? -x : x;
}
int main() {
  int t; scanf("%d", &t);
  while(t--) {
    int n; scanf("%d", &n);
    a[0] = 0;
    _rep(1, n, i) {
      scanf("%lld", a + i);
      a[i] += a[i-1];
    }
    LL a0 = 0, an = a[n], Max = 0;
    int A0, AN;
    sort(a, a + n + 1);
    memset(vis, 0, sizeof vis);
    if(a0 > an) swap(a0, an);
    _rep(0, n, i) if(a0 == a[i]) {A0 = i; break;}
    _rep(0, n, i) if(an == a[i]) {AN = i; break;}
    int l = 0, r = n;
    for(int i = A0; i >= 0; i-=2) ans[l++] = a[i], vis[i] = 1;
    for(int i = AN; i <= n; i+=2) ans[r--] = a[i], vis[i] = 1;
    _rep(0, n, i) if(!vis[i]) ans[l++] = a[i];
    _rep(1, n, i) Max = max(Max, Abs(ans[i] - ans[i-1]));
    printf("%lld\n", Max);  
  }
}
