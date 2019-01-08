#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <bitset>
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

int ans;
void solve(multimap<int, int> &mmap, bitset<10> bits,
           multimap<int, int>::iterator iter) {
  if (!bits.any()) {
    ans++;
    return;
  }
  if (iter == mmap.end()) {
    return;
  }

  auto titer = iter;
  titer++;
  solve(mmap, bits, titer);

  if (!bits.test(iter->first)) return;
  bits.set(iter->first, false);

  if (!bits.test(iter->second)) return;
  bits.set(iter->second, false);

  solve(mmap, bits, titer);
}

int main(void) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin >> T;
  for (int tc = 1; tc <= T; tc++) {
    int N, M;
    cin >> N >> M;

    int a, b;
    multimap<int, int> mmap;
    for (int i = 0; i < M; i++) {
      cin >> a >> b;
      mmap.insert({a, b});
    }

    ans = 0;
    bitset<10> bits;
    bits.reset();
    for (int i = 0; i < N; i++) {
      bits.set(i);
    }
    solve(mmap, bits, mmap.begin());
    cout << ans << endl;
  }

  return 0;
}
