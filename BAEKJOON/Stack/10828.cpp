// 문제 10828번 스택
// 정수를 저장하는 스택을 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성

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