#include <cstdio>
#include <iostream>
#include <string>
#include <stack>
using namespace std;

string ss;
//int ans;

void solve(){
    cin>>ss;
    int i, j, k;
    while(true){
        int len = ss.length();
        int st, ed;
        bool flag = false;
        bool front_flag=false;
        for(i=0; i<len; i++){
            if(ss[i]=='(') {
            	front_flag=true;
            	st=i;
			}
            if(ss[i]==')'&&front_flag){
                ed = i;
                flag=true;
                break;
            }
        }
        if(!flag){
//        	bool res = false; 
			string stmp; //防止有多余的'('或')' 
			
			for(i=0; i<ss.length(); i++){
				if(ss[i]==')'||ss[i]=='(') continue;
				stmp+=ss[i];
			}
        	int max=0, mcrt=0;
            for(k=0; k<len; k++){
                if(stmp[k]=='|'||k==len-1){
                	if(k==len-1) mcrt++;
                	if(mcrt>max) max=mcrt;
					mcrt=0;	
				}else{
					mcrt++;
				}
            }
            
            printf("%d\n", max);
            break;
        }else{
            string pt1, pt2;
            for(i=0; i<st; i++) pt1+=ss[i];
            for(i=ed+1; i<len; i++) pt2+=ss[i];
            
            int max=0, mcrt=0;
            for(k=st+1; k<ed; k++){
                if(ss[k]=='|'|| k==ed-1){
                	if(k==ed-1) mcrt++;
                	if(mcrt>max) max=mcrt;
                	mcrt=0;
				}else mcrt++; 
            }
//            int gl1 = k-st-1, gl2 = ed-k-1;
//            int tp = max;
            string pt3;
//            cout<<"max"<<max<<endl;
            while(max--){
                pt3+='x';
            }
            ss = pt1+pt3+pt2;
//            cout<<ss<<endl;
        }
    }
}

int main(){
    solve();
    return 0;
}
