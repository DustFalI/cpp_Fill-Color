#include <bits/stdc++.h>
using namespace std;
struct location
{
	int x, y;
};
queue<location> q;
int n, arr[35][35] = {0}, mark[35][35] = {0}, tmp;
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			cin >> tmp;
			if(tmp) arr[i][j] = 1;
		}
	}
	arr[0][0] = 1;
	q.push(location{0,0});
	while(!q.empty())
	{
		location p = q.front();
		q.pop();
		for(int i = 0; i < 4; i++)
		{
			int x = p.x + dx[i] , y = p.y + dy[i];
			if(x < 0 || y < 0 || x > n+1 || y > n+1) continue;
			if(arr[x][y] == 0 && mark[x][y] == 0)
			{
				mark[x][y] = 1;
				q.push(location{x,y});
			}
		}
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(arr[i][j] == 0 && mark[i][j] == 0)
			{
				cout << 2 << " ";
			}
			else if(arr[i][j] == 1)
			{
				cout << 1 << " ";
			}
			else
			{
				cout << 0 << " ";
			}
		}
		cout << endl;
	}
	return 0;
}
