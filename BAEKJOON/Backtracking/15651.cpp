// 문제 15651번 N과 M(3)
// 자연수 N과 M이 주어졌을 때, 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램
// 조건1. 1부터 N까지 자연수 중에서 M개를 고른 수열, 조건2. 같은 수를 여러번 골라도 됨

#include <iostream>
using namespace std;

int n, m;
int arr[9];
bool visited[9];

void dfs(int v) {
	if (v == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
	}
	else {
		for (int i = 1; i <= n; i++) {       // 방문했던곳을 뽑히지 않게했던 if문을 제거하여 뽑힌 수가 또 뽑힘
			visited[i] = true;
			arr[v] = i;
			dfs(v + 1);
			visited[i] = false;
		}
	}
}

int main(void) {
	cin >> n >> m;
	dfs(0);
}