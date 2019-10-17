#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <sstream>
#include <queue>
#include <map>
#include <stack>
#include <set>
#include <bitset>
#include <time.h>
#include <random>

using namespace std;
using Board = vector<vector<bool>>;

const int di[][2] = { {1,0},{1,0},{1,1},{1,1} };
const int dj[][2] = { {0,-1},{0,1},{0,-1},{0,1} };

struct Block {
	bool check(Board &board,const int &i,const int &j,const int &type){
		return board[i][j] && 
			board[i + di[type][0]][j + dj[type][0]] &&
			board[i + di[type][1]][j + dj[type][1]];
	}
	void set(Board &board,const int &i,int &j,const int &type) {
		board[i][j] = false;
		board[i + di[type][0]][j + dj[type][0]] = false;
		board[i + di[type][1]][j + dj[type][1]] = false;
	}
	void unset(Board &board,const int &i,int &j,const int &type) {
		board[i][j] = true;
		board[i + di[type][0]][j + dj[type][0]] = true;
		board[i + di[type][1]][j + dj[type][1]] = true;
	}
};

int ans = 0;
Block block;
vector<bool> find_next(Board &board,int &i,int &j) {
	static int ii, jj;
	for (ii = i; ii < board.size()-2; ii++) {
		for (jj = j+1; jj < board[ii].size()-2; jj++) {
			if (board[ii][jj]) {
				vector<bool> ret(4, false);
				bool flag = false;
				for(int type=0;type<4;type++) if (block.check(board, ii, jj,type)) ret[type] = flag = true;
				if (flag) { i = ii; j = jj; return move(ret); }
			}
		}
		j = 1;
	}
	return move(vector<bool>(4, false));
}

bool board_check(Board &board,int ii,int jj) {
	for (int i = 2; i <=ii; i++) {
		for (int j = 2; j < board[i].size() - 2; j++) {
			if (board[i][j] && (i < ii || i == ii && j < jj)) return false;
		}
	}
	return true;
}

void solve(Board &board, int i, int j,int remain) {
	if (remain <= 0) {
		ans += (remain == 0 ? 1 : 0);
		return;
	}
	if (board_check(board,i,j) == false) return;

	auto isPossible = find_next(board,i,j);
	bool isContinue = false;
	for (int type = 0; type < 4; type++) {
		if (isPossible[type]) {
			block.set(board, i, j,type);
			solve(board, i, j, remain - 3);
			block.unset(board, i, j,type);
			isContinue = true && remain != 3;
		}
	}
	if(isContinue) solve(board, i, j,remain);
}

int main(void) {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	int H, W;
	int dot_count;
	cin >> N;

	while (N--) {
		ans = 0;
		dot_count = 0;

		cin >> H >> W;
		Board board(H + 4, vector<bool>(W + 4, false));

		char buf;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> buf;
				board[i+2][j+2] = (buf == '#' ? false : true);
				if (board[i+2][j+2]) dot_count++;
			}
		}
		if (dot_count % 3 == 0) {
			int i = 1, j = 1;
			find_next(board, i, j);
			solve(board, i, j-1, dot_count);
		}
		cout << ans << endl;
	}

	return 0;
}
