// ���� 10866 ��
// ������ �����ϴ� ���� ������ ����, �Է����� �־����� ����� ó���ϴ� ���α׷� �ۼ�

#include <iostream>
#include <deque>
using namespace std;

int main(void) {
	int n, x;
	deque<int> dq;
	string s;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		
		if (s == "push_front") {
			cin >> x;
			dq.push_front(x);
		}

		else if (s == "push_back") {
			cin >> x;
			dq.push_back(x);
		}

		else if (s == "pop_front") {
			if (!dq.empty()) {
				cout << dq.front() << '\n';
				dq.pop_front();
			}
			else
				cout << -1 << '\n';
		}

		else if (s == "pop_back") {
			if (!dq.empty()) {
				cout << dq.back() << '\n';
				dq.pop_back();
			}
			else
				cout << -1 << '\n';
		}

		else if (s == "size")
			cout << dq.size() << '\n';
		
		else if (s == "empty") {
			if (dq.empty())
				cout << '1' << '\n';
			else
				cout << '0' << '\n';
		}

		else if (s == "front") {
			if (!dq.empty()) 
				cout << dq.front() << '\n';
			else
				cout << -1 << '\n';
		}

		else if (s == "back") {
			if (!dq.empty())
				cout << dq.back() << '\n';
			else
				cout << -1 << '\n';
		}
	}
	return 0;
}