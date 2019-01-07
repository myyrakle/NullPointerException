#include <time.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        char buf;
        vector<vector<char>> mmap(5);
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                cin >> buf;
                mmap[i].push_back(buf);
            }
        }
        int N;
        cin >> N;

        vector<string> vstrs;    //출력을 순서대로 하라길래 만듬.
        map<string, bool> strs;  //마지막에 완성된 단어 검색용

        map<char, map<pair<char, int>, bool>> status;  // status 전이도
        // 접근관점은 현재상태에서 다음상태로 넘어갈 수 있는지 확인을 해야함.
        // 다음과 같이 상태전이도를 정의함
        // {현재글자,{{다음글자,현재문자열 길이},마지막 글자여부}}

        string str;  //입력 버퍼
        for (int i = 0; i < N; i++) {
            cin >> str;
            strs[str] = false;
            vstrs.push_back(str);
            int j = 0;
            for (; j < str.size() - 1; j++) {
                //중간글자는 true;
                status[str[j]][pair<char, int>(str[j + 1], j + 1)] = true;
            }
            //마지막 글자는 false;
            status[str[j - 1]][pair<char, int>(str[j], j)] = false;
        }

        queue<pair<pair<int, int>, string>> que;  //현재좌표,현재까지 완성된 단어
        set<pair<pair<int, int>, string>> memo;   //큐에 중복으로 들어가는지 검사용

        // 25개의 출발점 중에 상태전이도에 있는 글자들만 큐에 삽입
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (status.find(mmap[i][j]) != status.end()) {
                    string tmp;
                    tmp += mmap[i][j];
                    que.push({{i, j}, tmp});
                }
            }
        }

        int dj[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        int di[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int ti, tj;

        while (!que.empty()) {
            auto front = que.front();
            que.pop();

            //큐에 들어왔었는지 검사
            if (memo.find(front) != memo.end()) continue;
            memo.insert(front);

            auto iter1 = status[mmap[front.first.first][front.first.second]];
            for (int i = 0; i < 8; i++) {
                ti = front.first.first + di[i];
                tj = front.first.second + dj[i];
                if (ti >= 0 and tj >= 0 and ti < 5 and tj < 5) {
                    //현재글자에서 다음글자로 이동할 수 있는지 검사
                    auto iter2 = iter1.find({mmap[ti][tj], front.second.size()});
                    if (iter2 != iter1.end()) {
                        //다음글자로 이동할 수 있다면....
                        if (iter2->second) {
                            // 다음글자가 마지막 글자가 아닌경우
                            que.push({{ti, tj}, front.second + mmap[ti][tj]});
                            continue;
                        } else {
                            //다음글자가 마지막 글자인경우
                            auto ret = strs.find(front.second + mmap[ti][tj]);
                            if (ret != strs.end()) {
                                //마지막으로 완성된 단어를 최종적으로 검사
                                ret->second = true;
                            }
                            continue;
                        }
                    }
                }
            }
        }
        //입력이 들어온 순서대로 플래그를 확인하여 출력
        for (auto &iter : vstrs) {
            cout << iter << " " << (strs[iter] ? "YES" : "NO") << endl;
        }
    }

    return 0;
}