// 문제 1152번 단어의 개수
// 영어 대소문자와 공백으로 이루어진 문자열이 주어진다.
// 이 문자열에 주어진 단어의 개수를 구하는 프로그램
// 한 단어가 여러 번 등장하면 등장한 횟수만큼 모두 셈

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string s;
	int cnt = 1;

	getline(cin, s);             // 띄어쓰기를 포함한 문자열을 받을 때는 cin이 아닌 getline으로 받아온다.

	for (int i = 0; i < s.size(); i++) {       // 띄어쓰기 하나당 +1
		if (s[i] == ' ')
			cnt++;
	}

	if (s[0] == ' ')             // 첫줄이 띄워져 있으면 -1
		cnt--;
	if (s[s.size() - 1] == ' ')       // 마지막 줄에 띄어쓰기가 있으면 -1
		cnt--;

	cout << cnt  << '\n';
}