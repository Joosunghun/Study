// 문제 9012 괄호
// 첫번째줄에 T개의 테스트 데이터
// 괄호가 VPS면 YES, VPS가 아니면 NO를 출력하는 함수

#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool check(string s) {
	stack<char> str;          // char 타입을 받는 stack 선언

	for (int i = 0; i < s.size(); i++) {        // 문자열 길이만큼 반복
		if (s[i] == '(') {                          // 문자가 여는 괄호면
			str.push(s[i]);                       // 스택에 push
		}
		else {                                       // 닫는 괄호면
			if (!str.empty())                       // 스택이 비지 않았다면
				str.pop();                          // pop
			else
				return false;                        // 비어있으면 false
		}
	}
	return str.empty();                            // 반복문이 끝나고 스택에 괄호가 남아있으면 false
}

int main(void) {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		
		if (check(s))
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
	return 0;
}