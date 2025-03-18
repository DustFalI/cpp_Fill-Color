#include <bits/stdc++.h>
using namespace std;
struct location//创建struct便于管理
{
	int x, y;
};
queue<location> q;
int n, arr[35][35] = {0}, mark[35][35] = {0}, tmp;
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};//偏移变量
int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			cin >> tmp;//根据题目灵活调整
			if(tmp) arr[i][j] = 1;
		}
	}
	arr[0][0] = 1;//标记起点
	q.push(location{0,0});//将起点按入队列
	while(!q.empty())//非空（必进）
	{
		location p = q.front();//提出队首
		q.pop();//出队
		for(int i = 0; i < 4; i++)//循环遍历四个方向
		{
			int x = p.x + dx[i] , y = p.y + dy[i];//直接赋值，方便
			if(x < 0 || y < 0 || x > n+1 || y > n+1) continue;//边界
			if(arr[x][y] == 0 && mark[x][y] == 0)//判定
			{
				mark[x][y] = 1;//标记
				q.push(location{x,y});//符合条件的位置按入队列
			}
		}
	}
	for(int i = 1; i <= n; i++)//输出遍历
	{
		for(int j = 1; j <= n; j++)
		{
			if(arr[i][j] == 0 && mark[i][j] == 0)//判定
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
