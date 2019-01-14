#include <cstdio>

bool v[10][10];

int check(int lv, int n)
{
	static bool rowcnt[10]{};
	static bool colcnt[10]{};
	int ret = 0;
	
	if (lv + 1 == n) return 1;
	if (rowcnt[lv]) return check(lv + 1, n);
	
	for (int i = lv + 1; i < n; ++i)
	{
		if (v[lv][i] && !colcnt[i])
		{
			rowcnt[i] = colcnt[i] = 1;
			ret += check(lv + 1, n);
			rowcnt[i] = colcnt[i] = 0;
		}
	}
  
	return ret;
}
int main()
{
	int C;
	scanf("%d", &C);
	
	int n, m, a, b;
	while (C--)
	{
		scanf("%d %d", &n, &m);
		
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				v[i][j] = 0;
		
		while (m--)
		{
			scanf("%d %d", &a, &b);
			v[a][b] = v[b][a] = 1;
		}
	  
		printf("%d\n", check(0, n));
	}
	
	return 0;
}
