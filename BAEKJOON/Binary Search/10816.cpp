// ���� 10816 ���� ī�� 2
// N���� ����ī��
// M���� ������ �־����� ��, �� ���� �����ִ� ���� ī�带 �� �� ������ �ִ��� ���ϴ� ���α׷�

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	int n, m;
	vector<int> arr;

	cin >> n;
	for (int i = 0; i < n; i++) {        // n���� ����ī�� �Է�
		int x;
		cin >> x;
		arr.push_back(x);
	}

	sort(arr.begin(), arr.end());   // ����ī�� ������������ ����

	cin >> m;
	for (int i = 0; i < m; i++) {        // m���� ���� �Է� ��
		int x;
		cin >> x;
		auto upper = upper_bound(arr.begin(), arr.end(), x);       // x ������ �̻��� ó�� ��Ÿ���� ��ġ, auto = Ÿ���߷�, ������ ������ �ڵ����� ������
		auto lower = lower_bound(arr.begin(), arr.end(), x);       // x ������ �ʰ����� ó�� ��Ÿ���� ��ġ

		cout << upper - lower << ' ';         // �� ��ġ�� ���ָ� x���� ����
	}

	return 0;
}