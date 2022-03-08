// ���� 2565�� ������
// �� ������ A�� B ���̿� �������� �߰��ϴ� ���� �������� ���� �����ϴ� ��찡 �߻�
// �ռ��� ������ �־� �̵� �� �� ���� �������� ���� �������� �������� �ʵ��� ������� �Ѵ�.
// �������� �����뿡 ����Ǵ� ��ġ�� ������ ���������� ���ʴ�� ��ȣ�� �Ű�����.
// �������� ������ �����ٵ��� �� �����뿡 ����Ǵ� ��ġ�� ��ȣ�� �־��� ��, ���� �ִ� ��� �������� ���� �������� �ʰ� �ϱ� ���� ���־� �ϴ� �������� �ּ� ������ ���ϴ� ���α׷�

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[102];

int main(void) {
	int n, a, b;
	int result = 0;
	cin >> n;
	
	vector<pair<int, int>> v;
	v.emplace_back(0, 0);       // emplace_back : vector�� ��� ���� ���Ҹ� �߰��ϴ� �Լ�, ���� ��ü�� �����Ͽ� ����
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.emplace_back(a, b);
	}
	sort(v.begin(), v.end());

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			if (v[i].second > v[j].second) {
				if (dp[j] >= dp[i])
					dp[i] = dp[j] + 1;
			}
		}
		result = max(result, dp[i]);
	}

	cout << n - result << '\n';
	return 0;
}