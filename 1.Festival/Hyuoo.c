#include <stdio.h>

int main() {
	int C, N, L, cost[1000] = { 0 };
	int n, i,j;
	double min, sum;
	//C<=100, 1<=L<=N<=1000, cost<=100
	scanf("%d", &C);
	while (C--) {
		scanf("%d %d",&N, &L);
		for (n = 0; n < N; n++)
			scanf("%d", &cost[n]);
		//입력끝
		min = 100000;
		for (i = L; i <= N; i++) {
			for (j = 0; j <= (N - i); j++) {
				for (sum=0,n = 0; n < i; n++)
					sum += cost[j+n];
				sum = sum / i;
				min = (min > sum) ? sum : min;
			}
		}
		printf("%.10f\n", min);
	}
}
