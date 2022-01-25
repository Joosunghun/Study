// 문제 11720번 숫자의 합
// N개의 숫자가 공백 없이 스여있다. 이 숫자를 모두 합해서 출력하는 프로그램

#include <iostream>
#include <string>
using namespace std;


int main(void) {
	int n;
	string s;
	int result = 0;

	cin >> n;
	cin >> s;
	for (int i = 0; i < n; i++) {       // 문자열을 숫자로 받아와서 다 더하기
		int num;
		num = s[i] - '0';

		result += num;
	}

	cout << result << '\n';
}