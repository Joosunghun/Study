// 문제 11725번 트리의 부모 찾기
// 루트 없는 트리가 주어진다. 이때, 트리의 루트를 1이라고 정했을 때, 각 노드의 부모를 구하는 프로그램

#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100000 + 1;

int n;
bool visited[MAX];
int parent[MAX];
vector<int> tree[MAX];

void findParent(int node) {
	visited[node] = true;        // 방문한 노드 표시

	for (int i = 0; i < tree[node].size(); i++) {            // DFS
		int next = tree[node][i];

		if (!visited[next]) {
			parent[next] = node;         // next의 parent는 node
			findParent(next);
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n - 1; i++) {            // 노드 입력 후 트리에 넣기
		int node1, node2;
		cin >> node1 >> node2;

		tree[node1].push_back(node2);
		tree[node2].push_back(node1);
	}

	findParent(1);           // 루트부터 탐색

	for (int i = 2; i <= n; i++) 
		cout << parent[i] << '\n';
	

	return 0;
}