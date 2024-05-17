#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

string s;
int a, b, c;
bool judge[3]={true, true, true};
int day[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool if_spc(int year){
    if((year%4==0 && year%100!=0) || year%400==0) return true;
    return false;
}

void j_one(){
    if(b==0||c==0){
        judge[0]=false;
        return;
    }
    if(b>12){
        judge[0]=false;
        return;
    }
    int year;
    if(a<=59){
        year = 2000+a;
    }else{
        year = 1900+a;
    }
    if(if_spc(year)){
        if(b==2){
            if(c>29){
                judge[0]=false;
                return;
            }
        }
    }else{
        if(c>day[b-1]){
            judge[0]=false;
            return;
        }
    }
}

void j_two(){
    if(a==0||b==0){
        judge[1]= false;
        return;
    }
    if(a>12){
        judge[1]=false;
        return;
    }
    int year;
    if(c<=59){
        year = 2000+c;
    }else{
        year = 1900+c;
    }
    if(if_spc(year)){
        if(a==2){
            if(b>29){
                judge[1]=false;
                return;
            }
        }
    }else{
        if(b>day[a-1]){
            judge[1]=false;
            return;
        }
    }
}

void j_three(){
    if(a==0||b==0){
        judge[2]=false;
        return;
    }
    if(b>12){
        judge[2]=false;
        return;
    }
    int year;
    if(c<=59){
        year = 2000+c;
    }else{
        year = 1900+c;
    }
    if(if_spc(year)){
        if(b==2){
            if(a>29){
                judge[2]=false;
                return;
            }
        }
    }else{
        if(a>day[b-1]){
            judge[2]=false;
            return;
        }
    }
}

void pt(){
    int dg1=0, dg2=0, dg3=0;
    if(judge[0]){
        if(a<=59){
            dg1 = (2000+a)*1e4+b*100+c;
        }else{
            dg1 = (1900+a)*1e4+b*100+c;
        }
    }
    if(judge[1]){
        if(c<=59){
            dg2 = (2000+c)*1e4+a*100+b;
        }else{
            dg2 = (1900+c)*1e4+a*100+b;
        }
    }
    if(judge[2]){
        if(c<=59){
            dg3=(2000+c)*1e4+b*100+a;
        }else{
            dg3 = (1900+c)*1e4+b*100+a;
        }
    }

    int dgts[3]={dg1, dg2, dg3};
    sort(dgts, dgts+3);
    for(int i=0; i<3; i++){
        if(i==1&&dgts[i]==dgts[i-1]) continue;
        if(i==2&&dgts[i]==dgts[i-1]) continue;
        if(dgts[i]>0){
            int yy = dgts[i]/1e4;
            int mm = (dgts[i]-1e4*yy)/1e2;
            int dd = (dgts[i]-1e4*yy-1e2*mm);
            stringstream is1;
            stringstream is2;
            stringstream is3;
            is1<<yy;
            is2<<mm;
            is3<<dd;
//            char *intStr1 = itos(yy);
//            char *intStr2 = itos(mm);
//            char *intStr3 = itos(dd);
//            string str = string(intStr);

            string ts1=is1.str();
            string ts2=is2.str();
            string ts3=is3.str();
            string result = ts1+'-';
            if(ts2.length()<2) result+='0'+ts2+'-';
            else result+=ts2+'-';
            if(ts3.length()<2) result+='0'+ts3;
            else result+=ts3;
            cout<<result<<endl;
        }
    }
}

void solve(){
    cin>>s;
    a = (s[0]-'0')*10+s[1]-'0';
    b = (s[3]-'0')*10+s[4]-'0';
    c = (s[6]-'0')*10+s[7]-'0';
//    printf("%d %d %d\n", a, b, c);
    j_one();
    j_two();
    j_three();
    pt();

}

int main() {
    solve();
    return 0;
}

