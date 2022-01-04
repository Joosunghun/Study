// ���� 1904�� 01Ÿ��
// 0 �Ǵ� 1�θ� �̷���� Ÿ��
// 1 �ϳ��� �ִ� 1Ÿ�ϰ� 0 �ΰ��ִ� 00 Ÿ�ϸ� �����Ѵ�
// N�� �־����� �� ���� �� �ִ� �� �������� ���ϴ� ���α׷�

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	vector<int> dp = {0,1,2};      // ���� �����ϱ� ���� ����
	int tmp = 0;

	for (int i = 3; i <= n; i++) {
		tmp = (dp[i - 1] + dp[i - 2]) % 15746;          // ��ȭ���� �������� 0, 1, 2, 3, 5, 8, 13 ... ������ �Ǻ���ġ ����
		dp.push_back(tmp);
	}

	cout << dp[n] << '\n';
	return 0;
}