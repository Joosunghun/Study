// 문제 1157번 단어 공부
// 알파벳 대소문자로 된 단어가 주어지면, 이 단어에서 가장 많이 사용된 알파벳이 무엇인지 알아내는 프로그램
// 대문자와 소문자는 구분하지 않음

#include <iostream>
#include <string>
using namespace std;

int alpha[26], cnt = 0;
string input;
// 아스키 코드 : 대문자 65~90, 소문자 97~122

int main(void) {

	cin >> input;

	for (int i = 0; i < input.size(); i++) {         // 빈도수 체크
		if (input[i] < 97)           // 대문자
			alpha[input[i] - 65]++;
		else                           // 소문자
			alpha[input[i] - 97]++;
	}

	int max = 0, max_indx = 0;

	for (int i = 0; i < 26; i++) {
		if (max < alpha[i]) {
			max = alpha[i];
			max_indx = i;
		}
	}

	for (int i = 0; i < 26; i++) {            // 가장 많이 사용된 알파벳이 여러개인지 확인
		if (max == alpha[i])
			cnt++;
	}

	if (cnt > 1)             // 여러개라면 ? 출력 아니라면 대문자로 출력
		cout << '?' << '\n';
	else
		cout << (char)(max_indx + 65) << '\n';
}