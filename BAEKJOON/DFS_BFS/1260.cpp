// ���� 1260�� DFS�� BFS
// �׷����� DFS Ž���� ����� BFS�� Ž���� ����� ����ϴ� ���α׷�
// �湮�� �� �ִ� ������ ���� ���� ��� ��ȣ�� ���� �� ���� �湮

#include <iostream>
#include <queue>
using namespace std;

int n, m, v;
int map[1001][1001];        // ���� ��� �׷���
bool visited[1001];   // ���� �湮 ����
queue<int> q;

void reset() {                // ��ġ�� �ʱ�ȭ �ϱ� ���� �Լ�
	for (int i = 1; i <= n; i++) {
		visited[i] = 0;
	}
}

void dfs(int v) {
	visited[v] = true;
	cout << v << ' ';

	for (int i = 1; i <= n; i++) {                // ���� ������ ����Ǿ� �ְ� �湮���� �ʾ�����
		if (map[v][i] == 1 && visited[i] == 0)
			dfs(i);
	}
}

void bfs(int v) {
	q.push(v);
	visited[v] = true;
	cout << v << ' ';
	while (!q.empty()) {
		v = q.front();
		q.pop();

		for (int i = 1; i <= n; i++) {
			if (map[v][i] == 1 && visited[i] == 0) {   // ���� ������ ����Ǿ� �ְ� �湮���� �ʾ�����
				q.push(i);
				visited[i] = true;
				cout << i << ' ';
			}
		}
	}
}

int main(void) {
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}

	reset();
	dfs(v);

	cout << '\n';

	reset();
	bfs(v);

	return 0;
}