#include <stdio.h>

int main()
{
	int i, j, k, n, N, L, ar[1001], s = 0;
	double m=100,M;
	scanf("%d", &n);
	for (i = 0; i < n; i++,m=100)
	{
		scanf("%d%d", &N, &L);
		for (j = 0; j < N; scanf("%d", ar + j),s+=ar[j++]);
		for (j = L; j <= N; j++)
		{
			for (s = 0, k = 0; k < j; s += ar[k++]);
			M = (double)s / j;
			if (m > M)m = M;
			for (k = 0; k < N - j; k++)
			{
				M = M - (double)ar[k] / j + (double)ar[j + k] / j;
				if (m > M)m = M;
			}
		}
		printf("%.11lf\n", m);
	}
}
