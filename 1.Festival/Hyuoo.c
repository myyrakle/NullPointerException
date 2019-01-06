#include <stdio.h>

int main() {
	int C, N, L, cost[1000] = { 0 };
	int n, i,j;
	float min, sum;
	//C<=100, 1<=L<=N<=1000, cost<=100
  
	scanf_s("%d", &C);
  
	while (C--) {
		scanf_s("%d %d",&N, &L);
		for (n = 0; n < N; n++)
			scanf_s("%d", &cost[n]);
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
