// 문제 15650번 N과 M (2)
// 자연수 N과 M이 주어졌을 때, 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램
// 조건 1 : 1부터 N까지 자연수 중에서 중복없이 M개를 고른 수열
// 조건 2 : 고른 수열은 오름차순

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
	for (int i = v; i <= n; i++) {
		if (visited[i] == false) {
			visited[i] = true;
			arr[cnt] = i;
			dfs(i + 1, cnt + 1);         // for문에 index값을 재귀함수의 인자로 넘겨주어 이미 찾은 조합 다시 뽑지 않게하기
			visited[i] = false;
		}
	}
}

int main(void) {
	cin >> n >> m;
	dfs(1, 0);
}