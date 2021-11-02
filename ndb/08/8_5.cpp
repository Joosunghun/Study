// 8_5 ȿ������ ȭ�� ����
// N ���� ������ ȭ��, ��ġ�� �� M
// ȭ�� ������ �ּ������� ����ϴ� ���
// ����� ���� ��� �Ұ��� �� ���� -1 �� ���

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
	int n, m;
	vector<int> arr;

	cin >> n >> m;                                        // ���� n,m �Է� �ޱ�
	for (int i = 0; i < n; i++) {                           // ȭ�� ���� �Է� �ޱ�
		int x;
		cin >> x ;
		arr.push_back(x);
	}
	
	vector<int> dp(m + 1, 10001);                    // ��� ����� ���� DP ���̺� 

	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = arr[i]; j <= m; j++) {
			if (dp[j - arr[i]] != 10001) {                             // (i - k) ���� ����� ����� �����ϴ� ���
				dp[j] = min(dp[j], dp[j - arr[i]] + 1);           // �ּڰ��� ����
			}
		}
	} 
	if (dp[m] == 10001)                                                // m���� ����� ����� ���� ���
		cout << -1 << endl;                                            // -1 ���
	else
		cout << dp[m] << endl;
}