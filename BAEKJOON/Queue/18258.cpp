// ���� 18258 ť2
// ������ �����ϴ� ť�� ������ ����, �Է����� �־����� ����� ó���ϴ� ���α׷� �ۼ�

#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);        // �ð��ʰ� ������ �ذ��ϱ� ���� ���
	cin.tie(NULL);
	cout.tie(NULL);
	int n, x;
	string s;
	queue<int> q;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s == "push") {
			cin >> x;
			q.push(x);
		}

		if (s == "pop") {
			if (!q.empty()) {
				cout << q.front() << '\n';
				q.pop();
			}
			else
				cout << -1 << '\n';
		}

		if (s == "size")
			cout << q.size() << '\n';

		if (s == "empty") {
			if (!q.empty())
				cout << 0 << '\n';
			else
				cout << 1 << '\n';
		}

		if (s == "front") {
			if (!q.empty())
				cout << q.front() << '\n';
			else
				cout << -1 << '\n';
		}
		
		if (s == "back") {
			if (!q.empty())
				cout << q.back() << '\n';
			else
				cout << -1 << '\n';
		}
	}
	return 0;
}