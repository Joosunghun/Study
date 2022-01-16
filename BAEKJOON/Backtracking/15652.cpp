// 문제 15652번 N과 M(4)
// 자연수 N과 M이 주어졌을 때, 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램
// 조건1. 1부터 N까지 자연수 중에서 M개를 고른 수열, 조건2. 같은 수를 여러번 골라도 됨 조건3. 고른 수열은 비내림차순

#include <iostream>
using namespace std;

int n, m;
int arr[9];
bool visited[9];

void dfs(int v, int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
	}
	else {
		for (int i = v; i <= n; i++) {
				visited[i] = true;
				arr[cnt] = i;
				dfs(i, cnt + 1);    
				visited[i] = false;
		}
	}
}

int main(void) {
	cin >> n >> m;
	dfs(1, 0);
}