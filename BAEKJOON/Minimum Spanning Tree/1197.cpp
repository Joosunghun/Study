// 문제 1197번 최소 스패닝 트리
// 그래프가 주어졌을 때, 그 그래프의 최소 스패닝 트리를 구하는 프로그램
// 최소 스패닝 트리란, 주어진 그래프의 모든 정점을 연결하는 부분 중에서 가중치 합이 최소인 트리를 말함

#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

int V, E, A, B, C;
int u, v, w;
int parent[10001];
long long ans;
bool check;
vector<tuple<int, int, int>> graph;

int find_parent(int x) {        // 부모 노드 찾기
	if (parent[x] == x)
		return x;
	else
		return parent[x] = find_parent(parent[x]);
}

void union_node(int u, int v) {          // 노드 결합하기
	check = false;

	u = find_parent(u);
	v = find_parent(v);

	if (u == v)
		return;
	else {
		parent[u] = v;
		check = true;
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> V >> E;

	for (int i = 1; i <= V; i++)
		parent[i] = i;

	for (int i = 0; i < E; i++) {
		cin >> A >> B >> C;
		graph.push_back(make_tuple(C, A, B));
	}

	sort(graph.begin(), graph.end());       // 가중치가 작은 것부터 오름차순 정렬

	for (int i = 0; i < E; i++) {         // MST 찾기
		union_node(get<1>(graph[i]), get<2>(graph[i]));

		if (check)
			ans += get<0>(graph[i]);       // 가중치 더하기
	}

	cout << ans << '\n';

}