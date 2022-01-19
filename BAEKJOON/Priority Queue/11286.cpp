// ���� 11286�� ���� ��
// ���� ������ �����ϴ� �ڷᱸ��
// 1. �迭�� ���� x �� �ִ´�. 2. �迭�� ������ ���� ���� ���� ����ϰ�, �� ���� �迭���� �����Ѵ�. ������ ���� ���� ���� ���� ���϶���, ���� ���� ���� ���

#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;            // �������� ����

	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x == 0) {
			if (!pq.empty()) {
				cout << pq.top().second << '\n';
				pq.pop();
			}
			else
				cout << 0 << '\n';
		}
		else
			pq.push({ abs(x),x });           // priority_queue�� ù��° ������ ���� �ι�° ������ ���� ���� ����
	}
	return 0;
}