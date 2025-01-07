#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;

int n;
int a[10];
const int INF = 1e6;


int sm_diff(int k){
    sort(a, a+k);
    int hf = k/2;
    int num1=0, num2=0;
    int odd = k%2;
    int i, j;
    int mim = INF;
    if(odd==1){
        if(a[0]!=0){
            for(i=0; i<=hf; i++){
                num1 = num1*10 + a[i];
            }
            for(i=k-1; i>hf; i--){
                num2 = num2*10 + a[i];
            }
            return num1-num2;
        }else{
            num1 = a[1]*10;
            for(i=2; i<=hf; i++){
                num1 = num1*10+a[i];
            }
            for(i=k-1; i>hf; i--){
                num2 = num2*10 + a[i];
            }
            return num1-num2;
        }
    }else{
        int tims;
        if(a[0]!=0){
            for(i=0; i<k-1; i++){
                num1 = a[i];
                num2 = a[i+1];
                tims = 0;
                for(j=k-1; j>=0; j--){
                    if(j==i || j==(i+1)) continue;
                    else{
                        tims++;
                        num1 = num1*10+a[j];
                    }
                    if(tims>=hf-1) break;
                }
                tims = 0;
                for(j=0; j<k; j++){
                    if(j==i||j==(i+1)) continue;
                    else{
                        tims++;
                        num2 = num2*10+a[j];
                    }
                    if(tims>=hf-1) break;
                }
                mim = ((num2-num1)<mim)?(num2-num1):mim;
            }
            return mim;
        }else{
        	if(k==2) return a[1]-a[0];
            for(i=1; i<k-1; i++){
                num1 = a[i];
                num2 = a[i+1]*10;
                tims = 0;
                for(j=k-1; j>=1; j--){
                    if(j==i || j==(i+1)) continue;
                    else{
                        tims++;
                        num1 = num1*10+a[j];
                    }
                    if(tims>=hf-1) break;
                }
                tims = 0;
                for(j=1; j<k; j++){
                    if(j==i||j==(i+1)) continue;
                    else{
                        tims++;
                        num2 = num2*10+a[j];
                    }
                    if(tims>=hf-2) break;
                }
                mim = ((num2-num1)<mim)?(num2-num1):mim;
            }
            return mim;
        }
    }
}

void solve(){
    scanf("%d", &n);
    char cc;
    int k;
    cc = getchar();
    while(n--){
        k=0;
        do{
            cc = getchar();
            if(cc-'0'>=0&&cc-'0'<=9){
                a[k] = cc-'0';
                k++;
            }
            else if(cc==' ') continue;
        }while(cc!='\n');
        printf("%d\n", sm_diff(k));
    }
}

int main() {
    solve();
    return 0;
}
