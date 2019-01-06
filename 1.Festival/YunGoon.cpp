#include <cstdio>

inline double min(double a, double b)
{
	return a > b ? b : a;
}
int main()
{
	int C;
	scanf("%d", &C);
	
	while (C--)
	{
		double ans = 1e5;
		for (int i = L; i <= N; ++i)
			for (int j = 0; j <= i-L; ++j)
				ans = min(ans, (double)(arr[i] - arr[j]) / (i - j));
		
		printf("%.10f\n", ans);
	}
	
	return 0;
}
