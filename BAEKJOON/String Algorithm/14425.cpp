// 문제 11425번 문자열집합
// 총 N개의 문자열로 이러우진 집합 S가 주어진다.
// 입력으로 주어진 M개의 문자열 중에서 집합 S에 포함되어 있는 것이 총 몇개인지 구하는 프로그램

#include <iostream>
#include <map>
using namespace std;

int n, m, ans;
string s;
map<string, bool> str;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> s;
		str[s] = true;
	}

	for (int i = 0; i < m; i++) {
		cin >> s;
		if (str[s])
			ans++;
	}

	cout << ans << '\n';
}