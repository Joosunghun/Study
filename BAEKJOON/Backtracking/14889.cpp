// 문제 14889번 스타트와 링크
// N명이서 축구를 해보려고 한다. N/2명으로 이루어진 스타트 팀과 링크 팀으로 사람들을 나눔
// 번호를 1부터 N까지 배정했고, 능력치를 조사. 능력치 Sij는 i와 j가 같은 팀에 속했을 때 팀에 더해지는 능력치다. 
// 두 팀의 능력치 차이의 최솟값을 출력하는 프로그램

#include <iostream>
#include <math.h>
using namespace std;

int stats[21][21];
bool check[22];
int n;
int ans = 100000000;

void dfs(int x, int pos) {             // x는 카운트, pos는 다음 값
	if (x == n / 2) {
		int start, link;
		start = 0;
		link = 0;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (check[i] == true && check[j] == true)
					start += stats[i][j];
				if (check[i] == false && check[j] == false)
					link += stats[i][j];
			}
		}

		int tmp = abs(start - link);
		if (ans > tmp)
			ans = tmp;

		return;
	}       

	for (int i = pos; i < n; i++) {
		check[i] = true;
		dfs(x + 1, i + 1);
		check[i] = false;
	}
}

int main(void) {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> stats[i][j];
		}
	}

	dfs(0, 1);        // 카운트는 0, 숫자는 1부터 시작

	cout << ans << '\n';
}