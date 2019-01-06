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
		int N, L;
		scanf("%d %d", &N, &L);
		
		int arr[1001]{};
		for (int i = 1; i <= N; ++i)
		{
			scanf("%d", arr + i);
			arr[i] += arr[i-1];
		}
		
		double ans = 1e5;
		for (int i = L; i <= N; ++i)
			for (int j = 0; j <= i-L; ++j)
				ans = min(ans, (double)(arr[i] - arr[j]) / (i - j));
		
		printf("%.10f\n", ans);
	}
	
	return 0;
}
