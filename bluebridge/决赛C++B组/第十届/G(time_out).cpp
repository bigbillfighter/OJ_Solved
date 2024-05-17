#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[501];

void init(int n) {
	for (int i = 1; i <= n; i++) {
		a[i] = i;
	}
}

int main() {
	cin >> n >> k;
	int sum = 0;
	init(n);
	do {
		int cnt = 0;
		for (int i = 2; i <= n-1; i++) {
			if ((a[i] > a[i + 1] && a[i] > a[i - 1]) || (a[i] < a[i + 1] && a[i] < a[i - 1])) {
				cnt++;
			}
		}
		if (cnt+1 == k) {
			sum++;
			if(sum>=123456) sum = sum%123456;
		}

	} while (next_permutation(a + 1, a + 1 + n));
	cout << sum;
	return 0;
}
