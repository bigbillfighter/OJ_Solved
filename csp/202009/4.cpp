#include <bits/stdc++.h>
using namespace std;

int n, m;
const int MAXN = 105, MAXM = 2e3+5;
double r;
double ctr[MAXN];
double p[MAXM][MAXN], dts[MAXM][MAXM];


double dis(int i, int j){
	double ca = 0, cb = 0, ab = 0;
	for(int k=1; k<=n; k++){
		ca += (p[i][k]-ctr[k]) * (p[i][k]-ctr[k]);
		cb += (p[j][k]-ctr[k]) * (p[j][k]-ctr[k]);
		ab += (p[i][k]-p[j][k]) * (p[i][k]-p[j][k]);
	}
	ca = sqrt(ca); cb = sqrt(cb); ab = sqrt(ab);
	
	double p = (ca+cb+ab)/2;
	double h = sqrt(p*(p-ca)*(p-cb)*(p-ab)) *2 /ab;
	if(h>r || ab*ab+ca*ca<cb*cb || ab*ab+cb*cb < ca*ca) return ab;
	double the_acb = acos((ca*ca+cb*cb-ab*ab)/(2*ca*cb));
	double the_caa1 = acos(r/ca);
	double the_cbb1 = acos(r/cb);
	return r*(the_acb-the_caa1-the_cbb1) + ca*sin(the_caa1)+cb*sin(the_cbb1);  
}

int main(){
	cin>>n>>m;
	cin>>r;
	for(int i=1; i<=n; i++) cin>>ctr[i];
	for(int i=1; i<=m; i++)
		for(int j=1; j<=n; j++)
			scanf("%lf", &p[i][j]);
	
	for(int i=1; i<m; i++){
		for(int j=i+1; j<=m; j++){
			dts[i][j] = dts[j][i] = dis(i, j);
		}
	}
	
	for(int i=1; i<=m; i++){
		double total = 0;
		for(int j=1; j<i; j++)
			total += dts[i][j];
		for(int j=i+1; j<=m; j++)
			total += dts[i][j];
		printf("%.14f\n", total);
	}
	return 0;
} 
