#include <iostream>
#include <cstdio>

using namespace std;

#define loop(I,N) for(size_t I=0;I!=N;++I)
#define rloop(I,N) for(size_t I=N;I--;)
#define mloop(N) while(N--)
#define beloop(I,B,E) for(size_t I=B;I!=E;++I)

int main()
{
	size_t T,N,L;
	size_t sum[1001] = { 0 },min,min_len;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> T;
	mloop(T) {
		cin >> N >> L;
		min = 1000000000;
		min_len = 1;
		cin >> sum[1]; // 배열을 1부터 사용, sum[i] = (순서대로 합 i개)
		// i에서 앞으로 k개 합 -> sum[i] - sum[i-k]
		// sum[0]이 0이기 때문에 따로 처리를 하지 않음
		// 최적화 여지: rloop 사용가능 but 가독성--;
		beloop(i,2,N+1) { // 2 .. N까지 합 저장, 총 N개
			cin >> sum[i];
			sum[i] += sum[i-1];
		}
		beloop(i,L,N + 1)
		{ // 개수가 L .. N인 집합
			beloop(j,i,N + 1)
			{ // 개수가 i일때 i번째 인덱스 부터 존재(0없음), 
				if(min_len*(sum[j] - sum[j - i]) < i * min) { // (sum[j]-sum[j-i])/i < min/min_len 과 동치 실수 연산 제거
					min = sum[j] - sum[j - i];
					min_len = i;
				}
			}
		}
		printf("%.12lf\n",(double)min / min_len);
	}
}
