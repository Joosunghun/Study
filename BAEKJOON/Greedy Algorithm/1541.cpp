// 문제 1541 잃어버린 괄호
// 0~9 , 그리고 +, - 만 있는 식에서 적절히 괄호를 쳐 이 식의 값을 최소로 만드는 프로그램

#include <iostream>
#include <string>
using namespace std;

string s;
string temp = "";

int main(void) {
	int result = 0;

	cin >> s;

	bool minus = false;
	for (int i = 0; i <= s.size(); i++) {
		if (s[i] == '+' || s[i] == '-' || s[i] == '\0') {           // 연산자일 경우
			if (minus)
				result -= stoi(temp);
			else
				result += stoi(temp);
			temp = " ";            // 초기화
			if (s[i] == '-')       // 괄호를 뺄셈 이후에 치면 최소값
				minus = true;
			continue;	
		}
		temp += s[i];           // 피연산자일 경우 temp에 더해줌
	}
	cout << result << '\n';
}