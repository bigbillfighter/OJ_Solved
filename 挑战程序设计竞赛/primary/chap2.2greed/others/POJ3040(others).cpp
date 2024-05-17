#include <iostream>
#include <functional>
#include <algorithm>
#include <limits>
using namespace std;
 
typedef pair<int, int> Coin;	// Ӳ�� ��ֵ������
Coin coin[20];
int need[20];
 
///////////////////////////SubMain//////////////////////////////////
int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
	int N, C;
	cin >> N >> C;
	for (int i = 0; i < N; ++i)
	{
		cin >> coin[i].first >> coin[i].second;
	}
	int week = 0;
	// ��С��C��һ������֧��һ��
	for (int i = 0; i < N; ++i)
	{
		if (coin[i].first >= C)
		{
			week += coin[i].second;
			coin[i].second = 0;
		}
	}
	sort(coin, coin + N, greater<Coin>());
	while(true)
	{
		int sum = C; // �ȴ������sum
		memset(need, 0, sizeof(need));
		// �Ӵ�С
		for (int i = 0; i < N; ++i)
		{
			if (sum > 0 && coin[i].second > 0)
			{
				int can_use = min(coin[i].second, 
								  sum / coin[i].first);
				if (can_use > 0)
				{
					sum -= can_use * coin[i].first;
					need[i] = can_use;
				}
			}
		}
		// ��С����
		for (int i = N - 1; i >= 0; --i)
		{
			if (sum > 0 && coin[i].second > 0)
			{
				int can_use = min(coin[i].second - need[i],                   // �ϸ�loop�õ���һЩ
								  (sum + coin[i].first - 1) / coin[i].first); // ������������һ����ֵ�Ľ��
				if (can_use > 0)
				{
					sum -= can_use * coin[i].first;
					need[i] += can_use;
				}
			}
		}
 
		if(sum > 0)
		{
			break;
		}
 
		int add_up = numeric_limits<int>::max(); // ��������week��
		// add_up���ٸ����ŵ�week ������ ÿ����ֵ���������Ž��µ�����������ٴ�
		for (int i = 0; i < N; ++i)
		{
			if (need[i] == 0)
			{
				continue;
			}
			add_up = min(add_up, coin[i].second / need[i]);
		}
		week += add_up;
		// ���Ž���Ч������ʣ��Ӳ������
		for (int i = 0; i < N; ++i)
		{
			if (need[i] == 0)
			{
				continue;
			}
			coin[i].second -= add_up * need[i];
		}
	}
	cout << week << endl;
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    system("out.txt");
#endif
    return 0;
}
