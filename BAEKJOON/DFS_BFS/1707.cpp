// 문제 170번 이분 그래프
// 그래프의 정점의 집합을 둘로 분할하여, 각 집합에 속한 정점끼리 서로 인접하지 않도록 분할할 수 있을 때, 그러한 그래프를 특별히 이분 그래프라고 부른다.
// 그래프가 입력으로 주어졌을 때, 이 그래프가 이분 그래프인지 판별하는 프로그램

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 20000 + 1;

int k, v, e;
vector<int> graph[MAX];
int nodeColor[MAX];

void dfs(int nodeNum, int color) {          // color : 0 아직 방문 x, 1, 2는 각각 색깔
	nodeColor[nodeNum] = color;
	
	for (int i = 0; i < graph[nodeNum].size(); i++) {
		int next = graph[nodeNum][i];
		if (!nodeColor[next])
			dfs(next, 3 - color);
	}
}

bool isBipartiteGraph(void) {         // 서로 ㄱ연결된 노드끼리 같은 색깔이면 이분그래프 x
	for (int i = 1; i <= v; i++) {
		for (int j = 0; j < graph[i].size(); j++) {
			int next = graph[i][j];
			if (nodeColor[i] == nodeColor[next])
				return false;
		}
	}
	return true;
}

int main(void) {
	cin >> k;
	
	for (int i = 0; i < k; i++) {
		for (int j = 1; j < MAX; j++) {
			graph[j].clear();
		}
		memset(nodeColor, 0, sizeof(nodeColor));

		cin >> v >> e;

		for (int j = 0; j < e; j++) {
			int node1, node2;
			cin >> node1 >> node2;

			graph[node1].push_back(node2);
			graph[node2].push_back(node1);
		}

		for (int j = 1; j <= v; j++) {
			if (nodeColor[j] == 0)
				dfs(j, 1);        // 1번 색깔부터 시작
		}

		if (isBipartiteGraph())
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
	return 0;
}