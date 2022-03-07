// ���� 12865�� ����� �賶
// ���࿡ �ʿ��ϴٰ� �����ϴ� N���� ����
// �� ������ ���� W�� ��ġ V�� �����µ�, �ش� ������ �賶�� �־ ���� V��ŭ ��� �� ����
// �ִ� K��ŭ�� ���Ը��� ���� �� �ִ� ������ ��� �ٴ� �� �ִ�.
// �ִ��� ��ſ� ������ �ϱ� ���� �賶�� ���� �� �ִ� ���ǵ��� ��ġ�� �ִ��� ���ϴ� ���α׷�

#include <iostream>
using namespace std;

int n, k;
int dp[101][100001];
int w[101];
int v[101];

// ��ȭ�� max(dp[i-1][j], dp[i-1][j-w[i]];

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