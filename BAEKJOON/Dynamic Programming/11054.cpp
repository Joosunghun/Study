// ���� 11054�� ���� �� ������� �κ� ����
// ���� S�� � �� Sk�� �������� S1 < S2 < ... Sk-1 < Sk > Sk+1 > ... SN-1 > SN�� �����Ѵٸ�, �� ������ ������� �����̶�� �Ѵ�.
// ���� A�� �־����� ��, �� ������ �κ� ���� �� ������� �����̸鼭 ���� �� ������ ���̸� ���ϴ� ���α׷�

#include <iostream>
using namespace std;

int main(void) {
	int n;
	int a[1001];
	int dp[2][1001];

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i <= n; i++) {             // ó������ ����
		dp[0][i] = 1;
		for (int j = 1; j < i; j++) {
			if (a[i] > a[j] && dp[0][i] < dp[0][j] + 1)
				dp[0][i] = dp[0][j] + 1;
		}
	}

	for (int i = n; i >= 1; i--) {            // ������ ���� ����
		dp[1][i] = 1;
		for (int j = n; j > i; j--) {
			if (a[i] > a[j] && dp[1][i] < dp[1][j] + 1)
				dp[1][i] = dp[1][j] + 1;
		}
	}

	int max = 0;
	for (int i = 1; i <= n; i++) {
		if (max < dp[0][i] + dp[1][i] - 1)
			max = dp[0][i] + dp[1][i] - 1;
	}

	cout << max << '\n';

	return 0;
}