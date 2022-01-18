// ���� 1927�� �ּ� ��
// �ּ� ���� �̿��Ͽ� ������ ���� ������ �����ϴ� ���α׷�
// 1. �迭�� �ڿ��� x�� �ִ´�. 2. �迭���� ���� ���� ���� ����ϰ�, �� ���� �迭���� �����Ѵ�.

#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	
	priority_queue<int, vector<int>, greater<int>> pq;        // greater : �켱���� ť�� ������������ ����
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		if (pq.empty()) {
			if (x == 0)
				cout << 0 << '\n';
			else
				pq.push(x);
		}
		else {
			if (x == 0) {
				cout << pq.top() << '\n';
				pq.pop();
			}
			else
				pq.push(x);
		}
	}
	return 0;
}
	int n;