#include<cstdio>
#include<algorithm>
int student[100001], visit[100001];
bool finish[100001];
void cycle(int x);
int count;
int main()
{
	int t, n;
	for (scanf("%d", &t); t--; count = 0)
	{
		std::fill_n(&student[0], 100001, 0);
		std::fill_n(&visit[0], 100001, 0);
		std::fill_n(&finish[0], 100001, 0);
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)
			scanf("%d", &student[i]);
		for (int i = 1; i <= n; ++i)
			if (visit[i] == 0)
				cycle(i);
		printf("%d\n", n-count);
	}
}
void cycle(int x)
{
	if (finish[x] == 1 || visit[x] == -1)
		return;
	if (visit[x] == 0)
		visit[x] = 1;
	else if(visit[x] == 1)
	{
		finish[x] = 1;
		++count;
	}
	cycle(student[x]);
	visit[x] = -1;
}
