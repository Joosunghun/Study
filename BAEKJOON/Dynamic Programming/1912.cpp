// ���� 1912�� ������
// n���� ������ �̷���� ������ ����
// �� �� ���ӵ� �� ���� ���� �����ؼ� ���� �� �ִ� �� �� ���� ū ���� ���ϴ� ���α׷�
// �� ���� �� �� �̻� �����ؾ� �Ѵ�

#include <iostream>
using namespace std;

int main(void) {
	int n;
	int arr[100001];
	int dp[100001];
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	dp[0] = arr[0];
	int sum = dp[0];
	for (int i = 1; i < n; i++) {
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
		sum = max(sum, dp[i]);
	}

	cout << sum << '\n';
}