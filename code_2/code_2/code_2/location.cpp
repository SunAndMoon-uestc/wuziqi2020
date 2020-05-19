#include "location.h"
#include<algorithm>
using namespace std;
struct loca
{
	int x, y, point;
}Loca[400];
int totLoca;
int mx[8][2] = { {1,0},{-1,0},{0,1},{1,1},{-1,1},{0,-1},{-1,-1},{1,-1} };
int pointu[7] = { 0,1,10,100,1000,10000,100000 };
int ev(int x, int y,int map[][MAXN],int origal)
{
	int x1=x, y1=y;
	int ans = 1;
	int maxx = 1;
	int color = 0;
	for (int i = 0;i < 8;i++)
	{
		x1 = x, y1 = y;
		ans = 1;
		x1 = x1 + mx[i][0];
		y1 = y1 + mx[i][1];
		color = map[x1][y1];
		if (color == 0)  continue;
		while (1)
		{
			x1 = x1 + mx[i][0];
			y1 = y1 + mx[i][1];
			if (x1 >= 1 && y1 >= 1 && x1 < MAXN - 1 && y1 < MAXN - 1 && map[x1][y1] == color)  ans++;
			else  break;
		}
		if (color != origal)
		{
			if (ans >= 3)
				ans = 6;
		}
		if (color == origal)  ans++;
		if (ans > maxx)  maxx = ans;
	}
	return pointu[maxx];
}
int coo(struct loca x, struct loca y)
{
	if (x.point > y.point)  return 1;
	return 0;
}
void Getlocation(int map[][MAXN],int color)
{
	totLoca = 0;
	int x, y;
	for (int i = 1;i <= MAXN-2;i++)
	{
		for (int j = 1;j <= MAXN - 2;j++)
		{
			if (!map[i][j])
			{
				for (int p = 0;p < 8;p++)
				{
					x = i + mx[p][0];
					y = j + mx[p][1];
					if (x >= 1 && y >= 1 && x < MAXN - 1 && y < MAXN - 1 && map[x][y])
					{
						Loca[++totLoca].x = i;
						Loca[totLoca].y = j;
						Loca[totLoca].point = ev(i, j,map,color);
					}
				}
			}
		}
	}
	sort(Loca + 1, Loca + totLoca + 1, coo);
	int u;
	if (Loca[1].point) u=1;
}