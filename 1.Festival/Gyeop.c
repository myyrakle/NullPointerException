#include<stdio.h>

typedef int testcase;
typedef int numofteam;
typedef int availabledates;

typedef struct {
	numofteam L;
	availabledates N;
	int pricebydates[1000];
}Data;

double movingarray(Data data) {

	double temp = 0;
	double min = 100000.0;

	for (; data.L <= data.N; data.L++) {
		for (int i = 0; i < (data.N - data.L + 1); i++) {
			temp = 0;
			for (int j = 0; j < data.L; j++)
				temp += (data.pricebydates)[i+j];
			min = (min > (double)(temp / data.L)) ? (double)(temp / data.L) : min;
		}
	}

	return min;

}

int main(void)
{

	testcase C;
	Data data[100];

	scanf("%d", &C);

	for (int i = 0; i < C; i++) {

		scanf("%d %d", &(data[i].N), &(data[i].L));

		for (int j = 0; j < data[i].N; j++) {

			scanf("%d", &(data[i].pricebydates[j]));

		}

	}

	for (int i = 0; i < C; i++) {
		printf("%.11f \n", movingarray(data[i]));
	}

	return 0;

}