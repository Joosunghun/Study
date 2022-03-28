// 문제 10942번 팰린드롬?
// 자연수 N개와 M번의 질문
// 두 정수 S와 E로 나타내며, S번째 수부터 E번째 까지의 수가 팰린드 롬을 이루는지 물어보며, 각 질문에 맞다 또는 아니다로 대답
// 자연수 N개와 질문 M개가 모두 주어질 떄, 대답을 구하는 프로그램

#include <iostream>
using namespace std;

int arr[2001];
bool dp[2001][2001] = { false, };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	for (int i = 1; i <= n - 1; i++) {
		if (arr[i] == arr[i + 1])
			dp[i][i + 1] = true;
	}
	
	for (int i = 1; i <= n; i++)
		dp[i][i] = true;

	for (int i = n - 1; i >= 1; i--) {
		for (int j = i + 2; j <= n; j++) {
			if (arr[i] == arr[j] && dp[i + 1][j - 1] == true)
				dp[i][j] = true;
		}
	}

	int m, s, e;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> s >> e;
		cout << dp[s][e] << '\n';
	}

	return 0;
}