// ���� 11279�� �ִ� ��
// �ִ� ���� �̿��Ͽ� ������ ���� ������ �����ϴ� ���α׷�
// 1. �迭�� �ڿ��� x�� �ִ´�. 2. �迭���� ���� ū ���� ����ϰ�, �� ���� �迭���� �����Ѵ�.

#include <iostream>
#include <queue>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);        // �ð��� ���̱� ����
	cin.tie(0);
	cout.tie(0);

	int n;
	priority_queue<int> pq;

	cin >> n;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (pq.empty()) {              // ť�� ����� ��
			if (x == 0) {                 // x == 0 �̸� 0 ���
				cout << 0 << '\n';
			}
			else                          // 0 �� �ƴϸ� push
				pq.push(x);
		}
		else {                           // ť�� ���� �ʾ��� ��
			if (x == 0) {                // x == 0 �̸� ���� ū �� ��� �� pop
				cout << pq.top() << '\n';
				pq.pop();
			}
			else                        // 0�� �ƴϸ� push
				pq.push(x);
		}

	}
}