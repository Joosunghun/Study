// ���� 10828�� ����
// ������ �����ϴ� ������ ������ ����, �Է����� �־����� ����� ó���ϴ� ���α׷��� �ۼ�

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void) {
	int n, x;
	stack<int> st;
	string s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s == "push") {
			cin >> x;
			st.push(x);
		}

		if (s == "pop") {
			if (!st.empty()) {
				cout << st.top() << '\n';
				st.pop();
			}
			else
				cout << -1 << '\n';
		}
		
		if (s == "size") {
			cout << st.size() << '\n';
		}

		if (s == "empty") {
			if (!st.empty())
				cout << 0 << '\n';
			else
				cout << 1 << '\n';
		}

		if (s == "top") {
			if (!st.empty())
				cout << st.top() << '\n';
			else
				cout << -1 << '\n';
		}
	}
	return 0;
}