#include<cstdio>
#include <bits/stdc++.h>
// solved 5/8
using namespace std;

const int MAX_N=1e5+5;
const int INF=0x3f3f3f3f;
int M, N;
struct node{
    int w, h, lt;
    int lh, mh;
};
node img[MAX_N];
int ht[MAX_N]; // 0 -i height
int changed_ht[MAX_N];

int max_height, last_height;
int LFT;

void cal_ht(int i, int a[]){
    int w, h;
    float ratio;
    img[i].lt = LFT;
    img[i].lh = last_height;
    img[i].mh = max_height;
    if(img[i].w >= LFT){
        ratio = (float)LFT/img[i].w;
        h = img[i].h * ratio - 1e-3;
        h++;
        if(h>max_height) a[i] = h+last_height;
        else a[i] = max_height+last_height;
        last_height = a[i];
        max_height = 0;
        LFT = M;
    }else{
        if(img[i].h>max_height){
            max_height = img[i].h;
            a[i] = img[i].h+last_height;
        }else{
            a[i] = max_height+last_height;
        }
        LFT = LFT-img[i].w;
    }
}

void new_cal_ht(int i, int a[]){
    int w, h;
    float ratio;
    if(img[i].w >= LFT){
        ratio = (float)LFT/img[i].w;
        h = img[i].h * ratio - 1e-3;
        h++;
        if(h>max_height) a[i] = h+last_height;
        else a[i] = max_height+last_height;
        last_height = a[i];
        max_height = 0;
        LFT = M;
    }else{
        if(img[i].h>max_height){
            max_height = img[i].h;
            a[i] = img[i].h+last_height;
        }else{
            a[i] = max_height+last_height;
        }
        LFT = LFT-img[i].w;
    }
}

int new_ht(int i){
    fill(changed_ht, changed_ht+N, 0);
    int j;
    while(j<i){
        changed_ht[j] = ht[j];
        j++;
    }
    last_height = img[i].lh;
    LFT = img[i].lt;
    max_height = img[i].mh;
    if(i<N&&i!=0){
        if(img[i].h < max_height) return -1;
    }
    for(j=i+1; j<N; j++){
        new_cal_ht(j, changed_ht);
    }
    if(i!=N-1) return changed_ht[N-1];
    else return ht[N-2];
}

void solve(){
    scanf("%d %d", &M, &N);
    int w_, h_;
    int i;
    LFT = M; //the remaining length of the line
    for(i=0; i<N; i++){
        scanf("%d %d", &img[i].w, &img[i].h);
        cal_ht(i, ht);
    }
//    for(i=0; i<N; i++){
//        printf("w, h, lh, mh, lt:%d %d %d %d %d\n", img[i].w, img[i].h, img[i].lh, img[i].mh, img[i].lt);
//    }


    int mam = INF;
    int rlt;
    for(i=0; i<N; i++){
        rlt = new_ht(i);
//        printf("rlt : %dth %d\n", i, rlt);
        if(rlt < 0) continue;
        if(rlt < mam) mam = rlt;
    }
    printf("%d\n", mam);
}

int main(){
    solve();
    return 0;
}
