// 문제 2675번 문자열 반복
// 문자열 S를 입력받은 후에, 각 문자를 R번 반복해 새 문자열 P를 만든 후 출력하는 프로그램

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int t, r;
	string s;

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> r >> s;
		for (int j = 0; j < s.length(); j++) {          // 문자열의 크기만큼 돌리면서 각 문자를 R번씩 출력함
			for (int k = 0; k < r; k++) {
				cout << s[j];
			}
		}
		cout << '\n';
	}
}