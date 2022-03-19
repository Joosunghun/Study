//  문제 4354번 문자열 제곱
// 알파벳 소문자로 이루어진 두 문자열 a와 b가 주어졌을 때, a*b는 두 문자열을 이어붙이는 것을 뜻함
// 이러한 이어 붙이는  것을 곱셈으로 생각한다면, 음이 아닌 정수의 제곱도 정의할 수 있다.
// 문자열 s가 주어졌을 때, 어떤 문자열 a에 대해서 s=a^n을 만족하는 가장 큰 n을 찾는 프로그램

#include <iostream>
#include <cstring>
using namespace std;

int fail[1000000];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s;
	int slen;

	while (1) {
		cin >> s;
		if (s == ".") break;
		slen = s.size();
		memset(fail, 0, sizeof(fail));

		for (int i = 1, j = 0; i < slen; ++i) {
			while (j && s[i] != s[j]) j = fail[j - 1];
			if (s[i] == s[j]) fail[i] = ++j;
		}

		if(slen % (slen- fail[slen-1]))
			cout << 1 << '\n';
		else
			cout << slen/(slen-fail[slen-1]) << '\n';
	}

	return 0;
}