// 문제 2293번 동전 1
// n가지 종류의 동전, 각각의 동전이 나타내는 가치는 다르다.
// 이 동전을 적당히 사용해서, 그 가치의 합이 k원이 되도록 하고 싶다.
// 그 경우의 수를 구하시오, 각각의 동전은 몇개라도 사용할 수 있다.

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