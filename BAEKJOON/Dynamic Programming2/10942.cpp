// ���� 10942�� �Ӹ����?
// �ڿ��� N���� M���� ����
// �� ���� S�� E�� ��Ÿ����, S��° ������ E��° ������ ���� �Ӹ��� ���� �̷���� �����, �� ������ �´� �Ǵ� �ƴϴٷ� ���
// �ڿ��� N���� ���� M���� ��� �־��� ��, ����� ���ϴ� ���α׷�

#include <iostream>
using namespace std;

int arr[2001];
bool dp[2001][2001] = { false, };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	for (int i = 1; i <= n - 1; i++) {
		if (arr[i] == arr[i + 1])
			dp[i][i + 1] = true;
	}
	
	for (int i = 1; i <= n; i++)
		dp[i][i] = true;

	for (int i = n - 1; i >= 1; i--) {
		for (int j = i + 2; j <= n; j++) {
			if (arr[i] == arr[j] && dp[i + 1][j - 1] == true)
				dp[i][j] = true;
		}
	}

	int m, s, e;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> s >> e;
		cout << dp[s][e] << '\n';
	}

	return 0;
}