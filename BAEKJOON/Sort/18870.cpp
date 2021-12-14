// ���� 18870 ��ǥ ����
// ������ ���� N���� ��ǥ�� �ִ�. �� ��ǥ�� �����Ϸ��� �Ѵ�.
// ��ǥ�� ������ ����� Xi > Xj�� �����ϴ� ���� �ٸ� ��ǥ�� ������ ���ƾ� �Ѵ�.
// ��ǥ ������ ������ ����� ����ϴ� ���α׷�

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int n;
	vector<pair<int,int>> num;        // ��ǥ ���� �� ���� ��ȣ�� ��� ����
	vector<int> ans(1000001);         // ���� ���� ����
	cin >> n;
	

	for (int i = 0; i < n; i++) {          // ��ǥ���� ��,index�� vecotr pair ���·� ����
		int x;
		cin >> x;
		num.push_back({ x,i });
	}

	sort(num.begin(), num.end());       // ���� �������� �������� ����
	int pivot = num[0].first;                  // ���ذ��� ���� ���� ����
	int cnt = 0;
	ans[num[0].second] = 0;             // ���� ���� ���Ҹ� �����ϸ� 0

	for (int i = 0; i < n; i++) {              // ���ĵ� ���¿��� ���� ans�� �ߺ��� ����Ͽ� ����
		if (pivot == num[i].first)            // ���� ���� ���Ҹ� 0
			ans[num[i].second] = cnt;
		else {                                   // ���� ���� Ŀ���� ����
			ans[num[i].second] = ++cnt;  // cnt ������Ű�� ans�� �־���
			pivot = num[i].first;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i] << ' ';
	}
}