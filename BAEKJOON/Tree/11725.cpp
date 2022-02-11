// ���� 11725�� Ʈ���� �θ� ã��
// ��Ʈ ���� Ʈ���� �־�����. �̶�, Ʈ���� ��Ʈ�� 1�̶�� ������ ��, �� ����� �θ� ���ϴ� ���α׷�

#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100000 + 1;

int n;
bool visited[MAX];
int parent[MAX];
vector<int> tree[MAX];

void findParent(int node) {
	visited[node] = true;        // �湮�� ��� ǥ��

	for (int i = 0; i < tree[node].size(); i++) {            // DFS
		int next = tree[node][i];

		if (!visited[next]) {
			parent[next] = node;         // next�� parent�� node
			findParent(next);
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n - 1; i++) {            // ��� �Է� �� Ʈ���� �ֱ�
		int node1, node2;
		cin >> node1 >> node2;

		tree[node1].push_back(node2);
		tree[node2].push_back(node1);
	}

	findParent(1);           // ��Ʈ���� Ž��

	for (int i = 2; i <= n; i++) 
		cout << parent[i] << '\n';
	

	return 0;
}