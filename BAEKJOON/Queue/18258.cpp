// 문제 18258 큐2
// 정수를 저장하는 큐를 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램 작성

#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);        // 시간초과 문제를 해결하기 위해 사용
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