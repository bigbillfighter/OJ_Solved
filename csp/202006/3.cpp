#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
int w; 

bool isblank(string s){
	for(int i=0; i<s.length(); i++){
		if(s[i]!=' ') return false;
	}
	return true;
}

string standard(string s){
	int st, ed;
	for(st=0; st<s.length(); st++){
		if(s[st]!=' ') break;	
	}
	for(ed = s.length()-1; ed>=0; ed--){
		if(s[ed]!=' ') break;
	}
	return s.substr(st, ed-st+1);
}

struct Markdown{
	int type; string s;
};

vector<Markdown> article;
int ans;

int main(){
	ios::sync_with_stdio(false);
	cin>>w;
	string str;
	 
	while(getline(cin, str)){ 
		if(!isblank(str)) break;	
	}
	
	article.push_back({1, standard(str)}); 
	bool newpara = false;
	
	while(getline(cin, str)){
		if(isblank(str)){
			newpara = true;
			continue;
		}
		if(newpara){
			article.push_back({1, standard(str)}); 
			newpara = false;
		}else{
			Markdown& m = article.back();
			m.s += " ";
			m.s += standard(str);
		}
	}

	for(int i=0; i<article.size(); i++){
		string& s = article[i].s;
		ans++;
		for(int j=0; j<s.length(); j+=w){
			while(s[j]==' ') j++;
			ans++;
		}
		
	}
	
	cout<<ans-1<<endl;
	return 0;
} 


/*
csp

csp is
a real realrealrealrealreal 
     competition.

   
Come   and   join   us   


*/
/*
csp

csp is a r
eal realre
alrealreal
real compe
tition.

Come   and
join   us
*/

/*
* csp
    
*   csp is
  * a real  
    competition.
* 
  * come!   and   join.
*tel:
* 12345
* 

*/
