#include <bits/stdc++.h>
#include <iomanip>

typedef long long ll;
using namespace std;

int n;
// const int maxstr=1e3;
// char str[maxstr];


void calcu(string s, string& sum, int base, int mk){
	int s_len = s.length(), sum_len = sum.length();
	ll sum1=0, sum2=0, sum3=0;

	for(int i=4; i<s_len; i++){
		if(s[i]>='0' && s[i]<='9')
			sum1 = sum1*base+s[i]-'0';
		else sum1 = sum1*base+s[i]-'A'+10;
	}
	//cout<<"sum1:"<<sum1<<endl;

	for(int i=0; i<sum_len; i++){
		if(sum[i]>='0' && sum[i]<='9')
			sum2 = sum2*base+sum[i]-'0';
		else sum2 = sum2*base + sum[i]-'A'+10;
	}

	if(mk==-1) sum3 = sum1;
	else if(mk==1) sum3 = sum2+sum1;
	else if(mk==2) sum3 = sum2-sum1;
	else if(mk==3) sum3 = sum2*sum1;
	else if(mk==4) sum3 = sum2/sum1;
	else sum3 = sum2%sum1;

	//cout<<"sum3: "<<sum3<<endl;
	int m=0;
	sum="";
	while(sum3){
		m = sum3%base;
		if (m>=0 && m<=9)	sum = char('0'+m)+sum;
		else sum = char(m-10+'A')+sum;
		sum3 /= base;
	}

	if(sum=="") sum = "0"+sum;
	//cout<<"sum:"<<sum<<endl;
}

int main(){
	string s, sum="";
	int mk=-1, base=10;

	scanf("%d", &n);
	getchar();
	while(n--){
		getline(cin, s);
		//cout<<s<<endl;
		if(s=="CLEAR") sum= "0"+ sum, mk=-1;
		else if(s=="EQUAL") cout<<sum<<endl;
		else if(s.find("NUM")!=s.npos) calcu(s, sum, base, mk);
		else if(s=="ADD") mk=1;
		else if(s=="SUB") mk=2;
		else if(s=="MUL") mk=3;
		else if(s=="DIV") mk=4;
		else if(s=="MOD") mk=5;
		else if(s.find("CHANGE")!=s.npos){
			
			int sum_len = sum.length();
			ll sum2=0;
			for(int i=0; i<sum_len; i++){
				if(sum[i]>='0' && sum[i]<='9') sum2 = sum2*base+sum[i]-'0';
				else sum2 = sum2*base+sum[i]-'A'+10;
			}
			//cout<<"sum2: "<<sum2<<endl;

			int s_len = s.length();
			base=0;
			for(int i=7; i<s_len; i++){
				base = base*10 +s[i]-'0';
			}
			//cout<<"Base: "<<base<<endl;
			sum="";
			int m=0;
			while(sum2){
				m = sum2 % base;
				if (m>=0 && m<=9) sum = char('0'+m) + sum;
				else sum = char(m-10+'A')+sum;
				sum2 /= base;
			}
			if(sum=="") sum = "0"+sum;
			//cout<<"sum:"<<sum<<endl;

		}
	}
	return 0;
}