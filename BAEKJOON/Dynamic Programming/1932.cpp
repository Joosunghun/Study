// ���� 1932�� ���� �ﰢ��
// �� ���� ���� �����ؼ� �Ʒ��� �ִ� �� �� �ϳ��� �����Ͽ� �Ʒ��� ���� �ö�, ���� ���� ���õ� ���� ���� �ִ밡 �Ǵ� ��θ� ���ϴ� ���α׷�
// �Ʒ����� �ִ� ���� ���� ������ ���õ� ���� �밢�� ���� �Ǵ� �����ʿ� �ִ� �� �߿����� ������ �� �ִ�.

#include <iostream>
#include <algorithm>
using namespace std;
int arr[501][501];
int dp[501][501] = { 0 };       // �� �� �̵��Ҵ븶�� ���� ��� ���� dp

int main(void) {
	int n;

	cin >> n;
	for (int i = 1; i <= n; i++) {         // arr�� �� ��ġ�� �� ���
		for (int j = 1; j <= i; j++) {
			cin >> arr[i][j];
		}
	}

	dp[1][1] = arr[1][1];             // ù ���� ����
	for (int i = 2; i <= n; i++) {        // arr ���� �� �� ���� ���Ͽ� �� ū�� �����ֱ�
		for (int j = 1; j <= i; j++) {
			dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + arr[i][j];
		}
	}

	int total = 0;
	for (int i = 1; i <= n; i++) {
		if (total < dp[n][i])        // dp ���� ���� ū �� ���
			total = dp[n][i];
	}

	cout << total << '\n';
}