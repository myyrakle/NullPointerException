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

        vector<vector<double>> arr(N + 1, vector<double>(N + 1, 1e5));

        for (int i = 0; i < N; i++) {
            cin >> arr[1][i + 1];
        }

        for (int i = 2; i <= N; i++) {
            for (int j = i; j <= N; j++) {
                arr[i][j] = arr[1][j - i + 1] + arr[i - 1][j];
            }
        }

        double ret = 1e10;
        for (int i = L; i <= N; i++) {
            sort(arr[i].begin(), arr[i].begin() + N + 1);
            ret = min(ret, arr[i][0] / i);
        }

        cout << fixed;
        cout.precision(8);
        cout << ret << endl;
    }

    return 0;
}