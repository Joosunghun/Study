// ���� 1003 �Ǻ���ġ �Լ�
// �Ǻ���ġ �Լ����� 0�� 1�� ���� ��� �߷µǴ��� ���ϴ� ���α׷�
// BUTTOM-UP  ��� ���

#include <iostream>
using namespace std;

int main(void) {
	int T, N;
	int dp[41] = {0,1};          // Ƚ���� ���� ���� �����ϴ� dp

	cin >> T;
	
	for (int n = 2; n <= 40; n++) {         // �Ǻ���ġ ���� ����
		dp[n] = dp[n - 1] + dp[n - 2];
	}

	for (int i = 0; i < T; i++) {         // ǥ�� ���� Ȯ���ϸ� 0�� ������ ���� 1�� ������ ���� ���� �Ǻ���ġ ���� n-1�� n�� ����
		cin >> N;
		if (N == 0)
			cout << "1 0\n";
		else
			cout << dp[N - 1] << ' ' << dp[N] << '\n';
	}
	return 0;
}