// ���� 2580�� ������
// ���� ���� �� ������ �ǿ� ���� �ִ� ���ڵ��� ������ �־��� �� ��� �� ĭ�� ä���� ���� ����� ����ϴ� ���α׷�

#include <iostream>
using namespace std;

int board[9][9];

bool check(int y, int x, int n) {             // (y, x) ��ǥ�� n�� �� �� �ִ��� Ȯ���ϴ� �Լ�
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

	if (board[y][x] != 0) {            // �̹� ä���� ������ ���� ĭ
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