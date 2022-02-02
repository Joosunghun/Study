// 문제 1316번 그룹 단어 체커
// 그룹 단어란 단어에 존재하는 모든 문자에 대해서, 각 문자가 연속해서 나타나는 경우만을 말한다.
// 단어 N개를 입력받아 그룹 단어의 개수를 출력하는 프로그램

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	int cnt = 0;
	string s;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		int size = s.length();
		bool flag = true;

		for (int j = 0; j < size; j++) {
			for (int k = 0; k < j; k++) {
				if (s[j] != s[j - 1] && s[j] == s[k]) {
					flag = false;
					break;
				}
			}
		}
		if (flag)
			cnt++;
	}
	cout << cnt;

	return 0;

}