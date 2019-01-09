#include <stdio.h>
#include <string.h>
#define true 1
#define false 0
int bod[5][5], dp[5][5][11];
char word[11];

int hasWord(int x, int y, int idx) {
	if (x < 0 || x>4 || y < 0 || y>4) return false;
	int *ret = &dp[x][y][idx];

	if (*ret != -1)return *ret;

	if (word[idx] != bod[x][y])return *ret = false;
	idx++;
	if (idx >= strlen(word))return *ret = true;
	
	return *ret = (hasWord(x-1, y-1, idx) || hasWord(x-1, y, idx) || hasWord(x-1, y+1, idx) || hasWord(x, y-1, idx) || hasWord(x, y+1, idx) || hasWord(x+1, y-1, idx) || hasWord(x+1, y,  idx) || hasWord(x+1, y+1, idx));
}

int main() {
	int C, N, c;
	int i,j;
	
	scanf("%d", &C);
	while (C--) {
		for (i = 0; i < 5; i++) {
			for (j = 0; j < 5; j++) {
				((c = getchar()) == '\n') ? j-- : (bod[i][j] = c);
			}
		}
		scanf("%d ", &N);
		while (N--) {
			i=0;
			memset(word, 0, sizeof(word));
			memset(dp, -1, sizeof(dp));
			while (((c = getchar()) == '\n') ? 0 : printf("%c",(word[i++] = c)));
			for (i = 0; i < 5; i++) {
				for (j = 0; j < 5; j++) {
					if (hasWord(i, j, 0)==true)goto YES;
				}
			}
			printf(" NO\n");
			goto END;
		YES:;
			printf(" YES\n");
		END:;
		}
	}
}
