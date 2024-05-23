#include<bits/stdc++.h>
using namespace std;

const int max_n = 1e9+5;
char arr[max_n];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    char c;
    int length, query;
    cin >> length >> query;
    for(int i=0; i<length; i++){
        cin >> c;
        arr[i] = c;
    }

    int front, end;
    int copy_len;
    for(int i=0; i< query; i++){
        cin >> front >> end;
        front --;

        copy_len = end - front;
        for(int j=length-1; j>=end; j--){
            arr[j+copy_len] = arr[j];
        }

        for(int j=end-1; j>=front; j--){
            arr[j+copy_len] = arr[j];
            arr[j+copy_len-1] = arr[j];
            copy_len --;
        }
        length += end - front;
    }

    arr[length] = '\n';
    cout << arr;
    return 0;
}