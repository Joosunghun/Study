// ���� 11049�� ��� ���� ����
// ũ�Ⱑ N x M�� ��� A�� M x K�� B�� ���� �� �ʿ��� ���� ������ ���� N x M x K ���̴�. ��� N���� ���ϴµ� �ʿ��� ���� ���� �� ���� ����� ���ϴ� ������ ���� �޶����� �ȴ�.
// ���� ����������, ������ �ϴ� ������ ���� ������ ���� �޶�����.
// ��� N���� ũ�Ⱑ �־����� ��, ��� ����� ���ϴµ� �ʿ��� ���� ���� Ƚ���� �ּڰ��� ���ϴ� ���α׷�

#include <iostream>
#include <algorithm>

#define INF 1000000000;

using namespace std;

int n, r, c;
int sum[501], matrix[501][2], dp[501][501];

int main(void) {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> r >> c;
		matrix[i][0] = r;
		matrix[i][1] = c;
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; i + j <= n; j++) {
			dp[j][i + j] = INF;
			for (int k = j; k <= i + j; k++)
				dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + matrix[j][0] * matrix[k][1] * matrix[i + j][1]);
		}
	}

	cout << dp[1][n] << '\n';
}