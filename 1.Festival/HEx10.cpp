#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);

	int n, days, team, d;
	double ans = 0;
	cin >> n;
	while (n--) {
		ans = 0;
		cin >> days >> team;
		vector<int> v(days, 0);
		for (auto &i : v) { cin >> d;  i = d; }

		for (double i = team; i <= days; i++) { //i is the range

			double start = 0, end = start + i - 1;
			double acc = 0;
			for (int k = start; k <= end; k++) acc += v[k];

			if (i == team || ans > acc / i) ans = acc / i;

			for (++start, ++end; end < v.size(); start++, end++) {
				acc = acc - v[start - 1] + v[end];
				if ((acc / i) < ans) ans = acc / i;

			} //pos
		} //days
		printf("%.12lf\n", ans);
	} //while
}