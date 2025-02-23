#include <bits/stdc++.h>
using namespace std;
const int inf= 0x3f3f3f3f;
char mp[31][31][31];
int sig[31][31][31];
int l, r, c;
int sx, sy,sz;
int ax, ay, az;
int nz, nx, ny;
int dz[6] = { 1,-1, 0,0,0,0 };
int dx[6] = { 0, 0,-1,0,1,0 };
int dy[6] = { 0, 0 ,0,1,0,-1 };
class P {
public:
	P(int z = 0, int x = 0, int y = 0) :_z(z), _x(x), _y(y) {};
	int _z;
	int _x;
	int _y;
};
int  BFS()
{
	queue<P>que;
	que.push(P(sz,sx,sy));
	sig[sz][sx][sy] = 0;
	while (que.size())
	{
		P p = que.front();
		que.pop();
		if (p._z == az && p._x == ax && p._y == ay)
		{
			break;
		}

		for (int i = 0; i < 6; i++)
		{
			nz = dz[i] + p._z;
			nx = dx[i] + p._x;
			ny = dy[i] + p._y;
			if (mp[nz][nx][ny] != '#' && nz >= 0 && nx >= 0 && ny >= 0 && nz < l && nx < r && ny < c&& sig[nz][nx][ny]==inf)
			{
				que.push(P(nz, nx, ny));
				sig[nz][nx][ny] = sig[p._z][p._x][p._y] + 1;
			}
		}
	}
	return sig[az][ax][ay];
}
void input()
{
	for (int i = 0; i < l; i++)
	{
		for (int j = 0; j < r; j++)
		{
			for (int k = 0; k < c; k++)
			{
				cin >> mp[i][j][k];
				if (mp[i][j][k] == 'S')
				{
					sz = i;
					sx = j;
					sy = k;
				}
				else if (mp[i][j][k] == 'E')
				{
					az = i; ax = j; ay = k;
				}
			}
		}
	}
}
int main()
{
	while (cin >> l >> r >> c)
	{
		if (l == 0 && r == 0 && c == 0)return 0;
		input();
		memset(sig, inf, sizeof sig);
		//  r  c  
		int ans = BFS();
		if (ans == inf)
			cout << "Trapped!" << endl;
		else
			printf("Escaped in %d minute(s).\n", ans);
	}
	return 0;
}
