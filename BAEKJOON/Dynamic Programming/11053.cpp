// ���� 11053�� ���� �� �����ϴ� ����
// ���� A�� �־����� ��, ���� �� �����ϴ� �κ� ������ ���ϴ� ���α׷�

#include <iostream>
#include <vector>
using namespace std;

int n;
int arr[1001];
vector<int> dp(1001, 1);

int main(void) {

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j])
				dp[i] = max(dp[j] + 1, dp[i]);
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = max(ans, dp[i]);

	cout << ans << '\n';
}