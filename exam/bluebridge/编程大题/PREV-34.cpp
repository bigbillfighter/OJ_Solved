/* 
令1-正面，0-反面 
要求(a, b)是否为反面，只要看到(a, b)为止翻转了多少次。因为当x>a, y>b
时,(x,y)不会翻转(a,b)
如(12, 16), 12会在1,2,3,4,6,12处，16会在1,2,4,8,16处翻转
所以总共6*5=30次
注意到会使12和16翻转的行和列是其约数，总共的次数即为两个约数的乘积
注意到只有该数为平方数(1, 4, 9, 16...)时，约数为奇数 
而要使翻得次数为奇数次，即乘积为奇数，需要两个都是奇数
所以问题的解为[1, n]中的平方数个数 * [1, m]中的平方数个数

首先对大数n和m求其平方根(取整),再相乘
*/
#include<cstdio>
#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

string StrMul(string a, string b){
	int len_a = a.length(), len_b = b.length();
	int nbr[2002]={0};
    int i, j;
	for(i=0; i<len_a; i++){
	    for(j=0; j<len_b; j++){
	        nbr[i+j+1] += (a[i]-'0') * (b[j]-'0');
	    }
	}
    int up=0;
	string c;
	for(i=len_a+len_b-1; i>=0; i--){
	    nbr[i]+=up;
	    up = nbr[i] / 10;
	    nbr[i] = nbr[i]%10;
	}
	for(i=0; i<len_a+len_b; i++){
	    if(!i) if(!nbr[i]) continue;
	    c+= nbr[i]+'0';
	}

	return c;
}

int StrCmp(string a, string b){
    if(a.length()>b.length()) return 1;
    else if(a.length()<b.length()) return -1;
    else{
        if(a>b) return 1;
        if(a==b) return 0;
        return -1;
    }
}

string StrSqrt(string a){
    int len_a = a.length();
    int pt_len = (len_a+1) / 2;
    string tgt;
    int i, j;
    for(i=0; i<pt_len; i++) tgt+='0';
    for(i=0; i<pt_len; i++){
        for(j=0; j<9; j++) {
            tgt[i]++;
            if(StrCmp(StrMul(tgt, tgt), a)==0) return tgt;
            else if(StrCmp(StrMul(tgt, tgt), a)>0) {
                tgt[i]--;
                break;
            }
        }
    }
    return tgt;
}

void solve(){
	string a, b;
	cin>>a; cin>>b;
	string ss1 = StrSqrt(a), ss2=StrSqrt(b);
	cout<<StrMul(ss1, ss2)<<endl;
}

int main(){
	solve();
	return 0;
}
