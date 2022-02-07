// 문제 8958번 OX 퀴즈
// O는 맞고 X는 틀린 것, 문제를 맞은 경우, 그 문제의 점수는 그 문제까지 연속된 O의 개수
// OX 퀴즈의 결과가 주어졌을 때, 점수를 구하는 프로그램

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int n;
	string s;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s;
		int sum = 0, cnt = 0;
		for(int j = 0; j < s.length(); j++){
			if (s[j] == 'O')           // 문제를 맞추면 카운트 한개씩 증가
				cnt++;
			else
				cnt = 0;
			sum += cnt;               // 나온 카운트들 모두 더해주기
		}

		cout << sum << '\n';

	}

}