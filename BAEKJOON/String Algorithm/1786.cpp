// 문제 1786번 찾기
// 워드프로세서 등을 사용하는 도중에 찾기 기능을 이용해 본 일이 있을 것이다. 이를 직접 구현해보자
// 두 개의 문자열 P와 T에 대해, 문자열 P가 문자열 T 중간에 몇 번, 어느 위치에서 나타나는지 알아내는 문제를 '문자열 매칭'이라고 한다.
// T의 i번 문자에서 시작하는 매칭을 검사하던중 T[i+j-1] != P[j]임을 발견했다고하자, 이렇게 P의 j번 문자에서 매칭이 실패한 경우, T의 i+j-1 번째 문자와 P의 K+1번 문자부터 비교를 계속해 나가면된다.
// 이 최대의 K를 j에 대한 함수라고 생각하고, 1~m까지의 각 j값에 대해 최대의 k를 미리 계산해 놓으면 편리할 것이다. 이를 전처리 과정이라고 부르며, O(m)에 완료할 수 있다.
// 이를 이용하여, T와 P가 주어졌을 때, 문자열 매칭 문제를 해결하는 프로그램

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> Fail(string pattern) {
	int m = pattern.length();
	vector<int> pi(m);

	int begin = 1;
	int matched = 0;
	pi[0] = 0;
	while (begin + matched < m) {
		if (pattern[begin + matched] == pattern[matched]) {
			matched++;
			pi[begin + matched - 1] = matched;
		}
		else {
			if (matched == 0)
				begin++;
			else {
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return pi;
}

vector<int> KMP(string pattern, string text) {
	int m = pattern.length();
	int n = text.length();
	vector<int> pos;
	vector<int> pi = Fail(pattern);

	int begin = 0;
	int matched = 0;
	while (begin + m <= n) {
		if (matched < m && text[begin + matched] == pattern[matched]) {
			matched++;

			if (matched == m)
				pos.push_back(begin + 1);
		}
		else {
			if (matched == 0)
				begin++;
			else {
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return pos;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string text;
	getline(cin, text);
	string pattern;
	getline(cin, pattern);

	vector<int> ans = KMP(pattern, text);
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << ' ';
	}
}