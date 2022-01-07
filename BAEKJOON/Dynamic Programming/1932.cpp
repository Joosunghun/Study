// 문제 1932번 정수 삼각형
// 맨 위층 부터 시작해서 아래에 있는 수 중 하나를 선택하여 아래로 내려 올때, 이제 까지 선택된 수의 합이 최대가 되는 경로를 구하는 프로그램
// 아래층에 있는 수는 현재 층에서 선택된 수의 대각선 왼쪽 또는 오른쪽에 있는 것 중에서만 선택할 수 있다.

#include <iostream>
#include <algorithm>
using namespace std;
int arr[501][501];
int dp[501][501] = { 0 };       // 한 줄 이동할대마다 합을 담기 위한 dp

int main(void) {
	int n;

	cin >> n;
	for (int i = 1; i <= n; i++) {         // arr에 각 위치의 값 담기
		for (int j = 1; j <= i; j++) {
			cin >> arr[i][j];
		}
	}

	dp[1][1] = arr[1][1];             // 첫 값은 같다
	for (int i = 2; i <= n; i++) {        // arr 값에 양 쪽 값을 비교하여 더 큰값 더해주기
		for (int j = 1; j <= i; j++) {
			dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + arr[i][j];
		}
	}

	int total = 0;
	for (int i = 1; i <= n; i++) {
		if (total < dp[n][i])        // dp 값중 제일 큰 값 출력
			total = dp[n][i];
	}

	cout << total << '\n';
}