// 문제 2580번 스도쿠
// 게임 시작 전 스도쿠 판에 쓰여 있는 숫자들의 정보가 주어질 때 모든 빈 칸이 채워진 최종 모습을 출력하는 프로그램

#include <iostream>
using namespace std;

int board[9][9];

bool check(int y, int x, int n) {             // (y, x) 좌표에 n이 들어갈 수 있는지 확인하는 함수
	for (int i = 0; i < 9; i++) {
		if (board[y][i] == n)
			return false;
		if (board[i][x] == n)
			return false;
	}

	for (int i = (y / 3) * 3; i < (y / 3) * 3 + 3; i++) {
		for (int j = (x / 3) * 3; j < (x / 3) * 3 + 3; j++) {
			if (board[i][j] == n)
				return false;
		}
	}

	return true;
}

void solve(int y, int x) {
	if (x == 9) {
		y++;
		x = 0;
	}

	if (y == 9) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << board[i][j] << " ";
			}
			cout << '\n';
		}
		exit(0);
	}

	if (board[y][x] != 0) {            // 이미 채워져 있으면 다음 칸
		solve(y, x + 1);
		return;
	}

	for (int i = 1; i <= 9; i++) {
		if (check(y, x, i)) {
			board[y][x] = i;
			solve(y, x + 1);
			board[y][x] = 0;
		}
	}
}

int main(void) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
					cin >> board[i][j];
	}

	solve(0, 0);

	return 0;
}