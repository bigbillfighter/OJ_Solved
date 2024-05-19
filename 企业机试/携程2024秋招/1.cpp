#include<bits/stdc++.h>
using namespace std;


const int max_n = 12;
int prime[8] = {2, 3, 5, 7, 11, 13, 17, 19};
int arr[max_n] = {0};

bool check_arr(int length){
    for(int i=0; i<length-1; i++){
        for(int j=0; j<8; j++){
            if (arr[i] + arr[i+1] == prime[j]){
                return false;
            }
        }
    }
    return true;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int number;
    cin >> number;


    for(int i=0; i<number; i++){
        arr[i] = i+1;
    }

    int ans = 0;

    do{
        if(check_arr(number)){ ans++; }
    }while(next_permutation(arr, arr+number));

    cout << ans <<endl;

    return 0;
}