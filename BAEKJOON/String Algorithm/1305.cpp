// 문제 1305번 광고
// 크기가 L인 전광판, 한번에 L개의 문자 표시 가능
// 길이가 N인 광고를 무한히 붙여서 광고한다.
// 시간이 1초가 지날때 마다, 문자는 한칸씩 옆으로 이동
// 어느 순간 전광판을 쳐다봤을 때, 그 때 쓰여있는 문자가 입력으로 주어졌을 때, 가능한 광고의 길이중 가장 짧은 것을 출력하는 프로그램

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int L;
string S;

vector<int> getPartialMatch(const string& N) {          // N에서 자기 자신을 찾으면서 나타나는 부분 일치를 이용해 pi[] 계산
	int M = N.size();
	vector<int> pi(M, 0);

	int begin = 1;
	int matched = 0;
	while (begin + matched < M) {            // 비교할 문자가 N끝에 도달할 때까지 찾으면서 부분 일치를 모두 기록
		if (N[begin + matched] == N[matched]) {
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

int main(void) {
	cin >> L;
	cin >> S;

	vector<int> pi = getPartialMatch(S);

	cout << L - pi[L - 1] << '\n';
	return 0;
}