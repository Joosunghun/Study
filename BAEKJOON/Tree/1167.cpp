// 문제 1167번 트리의 지름
// 트리의 지름이란, 트리의 임의의 두 점 사이의 거리 중 가잔 긴 것을 말한다.
// 트리의 지름을 구하는 프로그램

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 100000 + 1;

int v;
bool visited[MAX];
vector<pair<int, int>> graph[MAX];

int diameter = 0;
int farthestNode = 0;

void dfs(int node, int cost) {
	if (visited[node])            // 이미 방문한 곳
		return;

	visited[node] = true;

	if (diameter < cost) {       // 지름 업데이트
		diameter = cost;
		farthestNode = node;
	}

	for (int i = 0; i < graph[node].size(); i++) {
		dfs(graph[node][i].first, cost + graph[node][i].second);
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> v;

	for (int i = 0; i < v; i++) {
		int node;
		cin >> node;

		while (true) {
			int node2, cost;
			cin >> node2;
			if (node2 == -1)
				break;

			cin >> cost;
			graph[node].push_back({ node2,cost });
		}
	}

	memset(visited, false, sizeof(visited));              // memset : 메모리의 내용을 원하는 크기만큼 특정 값으로 세팅할 수 있는 함수
	dfs(1, 0);          // 루트에서 가장 먼점 찾기
	memset(visited, false, sizeof(visited));       // 해당 정점에서 가장 먼정점까지의 거리가 트리 지름
	diameter = 0;
	dfs(farthestNode, 0);
				
	cout << diameter << '\n';
	return 0;
}