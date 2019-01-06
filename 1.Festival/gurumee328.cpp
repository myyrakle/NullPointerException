#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <vector>

using namespace std;

int main(void) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin >> T;
  for (int tc = 1; tc <= T; tc++) {
    int N, L;
    cin >> N >> L;

    vector<double> costs;
    int buf;
    for (int i = 0; i < N; i++) {
      cin >> buf;
      costs.push_back(buf);
    }

    vector<vector<double>> arr(costs.size() + 1,
                               vector<double>(costs.size() + 1, 1e5));
    for (int i = 0; i < costs.size(); i++) {
      arr[1][i + 1] = costs[i];
    }

    for (int i = 2; i <= costs.size(); i++) {
      for (int j = i; j <= costs.size(); j++) {
        arr[i][j] = arr[1][j - i + 1] + arr[i - 1][j];
      }
    }

    double ret = 1e10;
    for (int i = L; i <= costs.size(); i++) {
      sort(arr[i].begin(), arr[i].end());
      ret = min(ret, arr[i][0] / i);
    }
    cout << fixed;
    cout.precision(8);
    cout << ret << endl;
  }

  return 0;
}
