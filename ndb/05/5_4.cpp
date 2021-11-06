// 5_4 �̷� Ż��
// N X M ũ���� �̷� 
// ���� ��ġ (1,1), �ⱸ�� (N,M), �� ���� �� ĭ �̵� ����
// ������ �ִ� �κ� 0, ������ ���� �κ� 1
// Ż���ϱ� ���� �������� �ϴ� �ּ� ĭ�� ����
// �ִܰ�θ� ã�� ���ؼ��� BFS ����ϱ�

#include <iostream>
#include <queue>
using namespace std;

int n, m;
int graph[201][201];

int dx[] = { -1,1,0,0 };                                           // �̵��� 4���� ���� ���� (��, ��, ��, ��)
int dy[] = { 0,0,-1,1 };

int bfs(int x, int y) {                                               // BFS ����
	queue<pair<int, int>> q;                                     // ť ����
	q.push({ x, y });
	
	while (!q.empty()) {                                           // ť�� �������� �ݺ��ϱ�
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for (int i = 0; i < 4; i++) {                                 // ���� ��ġ���� 4���� ���������� ��ġ Ȯ��
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;       // ������ ����� ����
			if (graph[nx][ny] == 0) continue;                                 // ���� ��� ����
			if (graph[nx][ny] == 1) {                                            // �ش� ��带 ó�� �湮�ϸ� �ִܰŸ� ���
				graph[nx][ny] = graph[x][y] + 1;
				q.push({ nx, ny });
			}
		}
	}
	return graph[n - 1][m - 1];                                // ���� ������ �Ʒ������� �ִܰŸ� ��ȯ
}

int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf_s("%1d", &graph[i][j]);
		}
	}
	cout << bfs(0, 0) << endl;                                 // (0, 0) ���� ��� ������ BFS�� ������ ��� ���
	return 0;
}