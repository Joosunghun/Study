// 문제 12865번 평범한 배낭
// 여행에 필요하다고 생각하는 N개의 물건
// 각 물건은 무게 W와 가치 V를 가지는데, 해당 물건을 배낭에 넣어서 가면 V만큼 즐길 수 있음
// 최대 K만큼의 무게만을 넣을 수 있는 베낭만 들고 다닐 수 있다.
// 최대한 즐거운 여행을 하기 위해 배낭에 넣을 수 있는 물건들의 가치의 최댓값을 구하는 프로그램

#include <iostream>
using namespace std;

int n, k;
int dp[101][100001];
int w[101];
int v[101];

// 점화식 max(dp[i-1][j], dp[i-1][j-w[i]];

int main(void) {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> w[i] >> v[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j - w[i] >= 0)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	cout << dp[n][k];

}