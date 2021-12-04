// 문제 4949 균형잡힌세상
// "("는 ")"와만 짝을 이룬다, "["는 "]" 와만 짝을 이룬다
// 문자열이 주어졌을 때 균형잡힌 문자열인지 아닌지 판단

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void) {
	string s;
	while (1) {
		getline(cin, s);                   // 문자열을 한줄씩 받아옴

		if (s == ".")                        // 문자열이 . 이면 멈춤
			break;

		stack<char> st;                 // 괄호를 담기 위한 스택
		bool flag = 0;                     // 예외 문장 방지용
		for (int i = 0; i < s.size(); i++) {         // 문자열 길이 만큼 반복
			if (s[i] == '(' || s[i] == '[')          // 여는 괄호면 
				st.push(s[i]);                        // 스택에 push
			else if (s[i] == ')') {                    // 닫는 소괄호 일때
				if (!st.empty() && st.top() == '(')       // 스택이 비지않고, top이 여는 소괄호이면
					st.pop();                             // pop
				else {                                   
					flag = 1;
					break;                               
				}
			}
			else if (s[i] == ']') {                    // 닫는 대괄호 일때
				if (!st.empty() && st.top() == '[')       // 스택이 비지않고, top이 여는 대괄호이면
					st.pop();                             // pop
				else {
					flag = 1;
					break;
				}
			}
		}
		if (flag == 0 && st.empty())          
			cout << "yes" << '\n';
		else
			cout << "no" << '\n';
	}
}
