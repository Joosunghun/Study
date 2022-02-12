// ���� 1167�� Ʈ���� ����
// Ʈ���� �����̶�, Ʈ���� ������ �� �� ������ �Ÿ� �� ���� �� ���� ���Ѵ�.
// Ʈ���� ������ ���ϴ� ���α׷�

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
	if (visited[node])            // �̹� �湮�� ��
		return;

	visited[node] = true;

	if (diameter < cost) {       // ���� ������Ʈ
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

	memset(visited, false, sizeof(visited));              // memset : �޸��� ������ ���ϴ� ũ�⸸ŭ Ư�� ������ ������ �� �ִ� �Լ�
	dfs(1, 0);          // ��Ʈ���� ���� ���� ã��
	memset(visited, false, sizeof(visited));       // �ش� �������� ���� ������������ �Ÿ��� Ʈ�� ����
	diameter = 0;
	dfs(farthestNode, 0);
				
	cout << diameter << '\n';
	return 0;
}