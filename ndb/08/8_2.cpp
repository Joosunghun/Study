// 8_2 1�� �����
// X�� 5�� ������ ��������, 5�� ����
// X�� 3���� ������ ��������, 3���� ����
// X�� 2�� ������ ��������, 2�� ����
// X���� 1�� ��
// 4���� ������ ����ؼ� 1�� �����, �ּ� ����

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
	int x;
	cin >> x;
	int dp[30001];

	dp[1] = 0;
	for (int i = 2; i <= x; i++) {
		dp[i] = dp[i - 1] + 1;                       // 1�� ���� ���
		if (i % 5 == 0)
			dp[i] = min(dp[i], dp[i / 5] + 1);  // 5�� ������ ���� ���
		if (i % 3 == 0)
			dp[i] = min(dp[i], dp[i / 3] + 1);  // 3���� ������ ���� ���
		if (i % 2 == 0)
			dp[i] = min(dp[i], dp[i / 2] + 1);  // 2�� ������ ���� ���
	}
	cout << dp[x] << endl;      // dp �� ����� �� ���
}