// 문제 15649번 N과 M(1)
// 자연수 N과 M이 주어졌을 때, 1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열을 모두 구하는 프로그램

#include <iostream>
using namespace std;

int n, m;
int arr[9];
bool visited[9];

void dfs(int v) {
	if (v == m) {
		for (int i = 0; i < m; i++)         // arr에 저장한 값 추력
			cout << arr[i] << ' ';
		cout << '\n';
	}
	else {
		for (int i = 1; i <= n; i++) {
			if (visited[i] == false) {
				visited[i] = true;
				arr[v] = i;            // 배열에 i값 저장
				dfs(v + 1);           // v값에 1씩 더하며 재귀
				visited[i] = false;
			}
		}
	}
}

int main(void) {
	cin >> n >> m;
	dfs(0);
}