// 8_3 ���� ����
// ������ �� â��, �� ĭ �̻� ������ �ķ�â�� ��Ż�ؾ� ��
// �ִ�� ��Ż�� �� �ִ� ����� ��

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	vector<int> arr;
	int dp[100];

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr.push_back(x);
	}

	dp[0] = arr[0];                                  // ù ���� dp�� ù ��° �ķ��� ����
	dp[1] = max(arr[0], arr[1]);                // dp1���� ���� �ķ� �߿� �� ���� �ķ� ���ϱ�
	for (int i = 2; i < n; i++) {
		dp[i] = max(dp[i - 1], dp[i - 2] + arr[i]);              
	}

	cout << dp[n - 1] << endl;
}
