// ���� 2293�� ���� 1
// n���� ������ ����, ������ ������ ��Ÿ���� ��ġ�� �ٸ���.
// �� ������ ������ ����ؼ�, �� ��ġ�� ���� k���� �ǵ��� �ϰ� �ʹ�.
// �� ����� ���� ���Ͻÿ�, ������ ������ ��� ����� �� �ִ�.

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	vector<int> dp(k + 1);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = arr[i]; j <= k; j++)
			dp[j] += dp[j - arr[i]];
	}	

	cout << dp[k] << '\n';
	return 0;
}