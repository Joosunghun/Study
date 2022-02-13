// 문제 1967번 트리의 지름
// 문제 1167번과 동일 내용
// 루트가 있는 트리를 가중치가 있는 간선들로 줄 때, 트리의 지름을 구해서 출력하는 프로그램

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<pair<int, int>> node[10002];
bool visited[10002] = { false, };
int result = 0;
int endPoint = 0;

void dfs(int start, int len) {
	if (visited[start])          // 이미 방문한 곳
		return;

	visited[start] = true;          // 지름 업데이트
	if (result < len) {
		result = len;
		endPoint = start;
	}

	for (int i = 0; i < node[start].size(); i++) {
		dfs(node[start][i].first, len + node[start][i].second);
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	
	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		node[a].push_back({ b,c });
		node[b].push_back({ a,c });
	}

	dfs(1, 0);           //가장 멀리있는 점 구하기
	result = 0;
	memset(visited, false, sizeof(visited));

	dfs(endPoint, 0);          // 지름 구하기
	cout << result << '\n';
}