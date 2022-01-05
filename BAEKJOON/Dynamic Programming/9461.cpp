// ���� 9461�� �ĵ��� ����
// ���� ������� �������ִ� �ﰢ�� ����
// ù �ﰢ���� ���ﰢ������ ���� ���̰� 1
// �������� ���� �� ���� ���̸� k�� ���� ��, �� ���� ���̰� k�� ���ﰢ�� �߰��� �ݺ�
// P(N)�� ������ �ִ� ���ﰢ���� ���� ����
// N�� �־�����  ��, P(N)�� ���ϴ� ���α׷� �ۼ�

#include <iostream>
using namespace std;
long long dp[101] = {0,1,1,};

long long P(int n) {           
	if (n < 3)
		return dp[n];
	else if (dp[n] == 0)
		dp[n] = P(n - 2) + P(n - 3);       // �ĵ��� �������� ã�� ��ȭ��
	return dp[n];
}

int main(void) {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		cout << P(n) << '\n';
	}
}