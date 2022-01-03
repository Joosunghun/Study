// 문제 9184번 신나는 함수 실행
// 재귀 함수가 주어지고 값이 주어졌을때 함수값을 출력하는 프로그램
#include <iostream>
#include <vector>
using namespace std;

int dp[21][21][21];

int w(int a, int b, int c) {           // 문제에서 주어진 함수
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;
	else if (a > 20 || b > 20 || c > 20)
		return w(20, 20, 20);
	else if (a < b && b < c) {
		if (dp[a][b][c] != 0)          // 값이 저장되어있으면 dp 출력
			return dp[a][b][c];
		else 
			return dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	}

	else {
		if (dp[a][b][c] != 0)
			return dp[a][b][c];
		else
			return dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int a, b, c;

	while (true) {         
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)
			break;
		cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << '\n';
	}
	return 0;
}