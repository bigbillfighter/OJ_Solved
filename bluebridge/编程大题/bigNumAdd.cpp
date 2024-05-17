#include <iostream>
using namespace std;

char a_arr[102], b_arr[102], aa[102],bb[102];
char c_arr[103];

int main(){
	cin>>a_arr;
	cin>>b_arr;
	int a_len=0, b_len=0;
	for(; a_arr[a_len]!='\0'; a_len++);
	for(; b_arr[b_len]!='\0'; b_len++);
	for(int i=a_len; i<101; i++){ a_arr[i]='0';aa[i]='0';}
	for(int i=b_len; i<101; i++){ b_arr[i]='0';bb[i]='0';}
	for(int i=a_len-1; i>=0; i--){
		aa[a_len-1-i] = a_arr[i];
	}

	for(int i=b_len-1; i>=0; i--){
		bb[b_len-1-i] = b_arr[i];
	}
	int c_len = a_len>b_len?a_len:b_len;
	//cout<<a_len<<" "<<b_len<<" "<<c_len<<endl;
	int c=0;
	int sum=0;
	for(int i=0; i<c_len; i++){
		sum = aa[i]-'0'+bb[i]-'0'+c;
		c_arr[i] = sum%10 +'0';
		c = sum/10;
	}
	if(c!=0){
		c_arr[c_len] = '0'+c; 
		for(int i=c_len; i>=0; i--){
			cout<<c_arr[i];
		}
	}
	else{
		for(int i=c_len-1; i>=0; i--){
			cout<<c_arr[i];
		}
	}
	return 0;
}