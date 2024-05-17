#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
 
const int MAXN=25005;
int n,t;
 
struct node{
    int s,e;
};
node cows[MAXN];
 
bool Cmp(const node a,const node b){
    if(a.s!=b.s) return a.s<b.s;
    else return a.e>=b.e;
}
 
int Cal(int ans)
{
    if(cows[0].s!=1) return -1;
    if(n==1){
        if(cows[0].s==1&&cows[0].e==t) return 1;
        else return -1;
    }
    int i=1,maxE=cows[0].e,maxNextE=cows[0].e;
    while(i<n){
        if(maxE==t) return ans;
        bool flag=false;
        if(cows[i].s<=maxE+1){
            while(i<n&&cows[i].s<=maxE+1){
                if(cows[i].e>maxNextE){
                    maxNextE=cows[i].e;
                    flag=true;
                }
                i++;
            }
            if(flag){
                maxE=maxNextE;
                ans++;
            }
        }
        else
            return -1;
    }
    if(maxE==t) return ans;
    else return -1;
}
 
int main()
{
    while(scanf("%d%d",&n,&t)==2)
    {
        for(int i=0;i<n;i++)
            scanf("%d%d",&cows[i].s,&cows[i].e);
        sort(cows,cows+n,Cmp);
        cout<<Cal(1)<<endl;
    }
 
    return 0;
}
