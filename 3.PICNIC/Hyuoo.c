#include <stdio.h>
#include <string.h>
#define bit(n) (1<<(n))
short able[10];

int pairing(short flag, int start, int end) {
	//n까지 flag가 모두 1일때 완전종료
	if (bit(end)-1==flag) return 1;
	int count=0, i, j;
	for (i = start; i < end; i++) {
		for (j = i+1; j < end; j++) {
			if (!(flag&bit(i)) && !(flag&bit(j)) && (able[i] & bit(j)) ) {
				flag |= bit(i) | bit(j);
				count += pairing(flag, i + 1, end);
				flag &= ~(bit(i) | bit(j));
			}
		}
	}
	return count;
}
int main() {
	int C, n, m;
	int tmp1, tmp2;
	scanf("%d", &C);
	while (C--) {
		scanf("%d %d", &n, &m);
		memset(able, 0, sizeof(able));
		while (m--) {
			scanf("%d %d", &tmp1, &tmp2);
			able[tmp1] |= bit(tmp2);
			able[tmp2] |= bit(tmp1);
		}
		printf("%d\n", pairing(0, 0, n));
	}
}
