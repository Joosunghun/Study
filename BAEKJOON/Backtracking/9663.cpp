// 문제 9663번 N-Queen
// N-Queen 문제는 크기가 N x N인 체스판 위에 퀸 N개를 서로 공격할 수 없게 만드는 문제
// N이 주어졌을 때, 퀸을 놓을 방법의 수를 구하는 프로그램

#include <iostream>
#include <vector>
using namespace std;

int n;
int ans = 0;

vector<int> visited(15);           // 체스판 배열

bool Check(int x) {
	for (int i = 0; i < x; i++) {
		if (visited[x] == visited[i] || x - i == abs(visited[x] - visited[i]))            // 퀸들이 서로 공격할 수 있다면 0
			return 0;
	}

	return 1;          // 퀸이 배치가 되면 1
}

void Queen(int x) {
	if (x == n) {              // 현재 배치한 퀸의 갯수가 입력값과 같다면 탈출
		ans++;
		return;
	}

	for (int j = 0; j < n; j++) {         
		visited[x] = j;              // [x, j]에 퀸을 배치해보고 배치할 수 있다면 퀸의 행을 +1하고 다음 퀸을 배치한다

		if (Check(x))
			Queen(x + 1);
	}
}

int main(void) {
	cin >> n;
	Queen(0);
	cout << ans;
}