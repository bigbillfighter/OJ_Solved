#include <iostream>
#include <queue>
#include <string>
#include <cstdio>
#include <stack>
using namespace std;

const int MID=32;
const int MAX_N=65;
stack<char> status;
bool A_first = true;
queue<char> A, B;

void play(){
    int i;
    int place;
    bool same=false;
    char crt, idy;
    if(A_first){
        crt = A.front();
        A.pop();
        if(status.empty()){
            status.push(crt);
            A_first = false;
            return;
        }else{
            stack<char> tmp = status;
            place=0;
            while(!tmp.empty()){
                idy = tmp.top();
                tmp.pop();
                if(idy==crt){
                    same=true;
                    break;
                }
                place++;
            }
            if(same){
                A.push(crt);
                for(i=0; i<=place; i++){
                    crt = status.top();
                    status.pop();
                    A.push(crt);
                }
                A_first = true;
                return;
            }else{
                status.push(crt);
                A_first = false;
                return;
            }

        }
    }else{
        crt = B.front();
        B.pop();
        if(status.empty()){
            status.push(crt);
            A_first = true;
            return;
        }else{
            stack<char> tmp = status;
            place=0;
            while(!tmp.empty()){
                idy = tmp.top();
                tmp.pop();
                if(idy==crt){
                    same=true;
                    break;
                }
                place++;
            }
            if(same){
                B.push(crt);
                for(i=0; i<=place; i++){
                    crt = status.top();
                    status.pop();
                    B.push(crt);
                }
                A_first = false;
                return;
            }else{
                status.push(crt);
                A_first = true;
                return;
            }

        }

    }

}

void solve(){
    string as, bs;

    cin>>as; cin>>bs;
    int i;
    for(i=0; i<as.length(); i++){
        A.push(as[i]);
    }
    for(i=0; i<bs.length(); i++){
        B.push(bs[i]);
    }

    while(!A.empty() && !B.empty()){
        play();
    }
    if(A.empty()){
        int size = B.size();
        for(i=0; i<size; i++) {
            printf("%c", B.front());
            B.pop();
        }
    }
    if(B.empty()){
        int size = A.size();
        for(i=0; i<size; i++){
            printf("%c", A.front());
            A.pop();
        }
    }
}

int main() {
    solve();
    return 0;
}

