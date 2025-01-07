#include <iostream>
using namespace std;

int main(){
    int b = 0x3f3f3f3f;
    int a = -b;
	cout<<a<<" "<<b<<endl;
	for(int i=a; i<=b; i++){
		if(!i) cout<<i<<" "<<"OK!"<<endl;
	} 
    return 0;
}
