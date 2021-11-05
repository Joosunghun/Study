// 5_3 ����� ����Ա�
// N X M ����Ʋ, ������ �Ը� ���� 0, ĭ���̰� �����ϴ� �κ��� 1
// ������ �ո� �κ��� ��, ��, ��, ��� �پ� �ִ� ��� ���� ���� �Ǿ�����
// ù ��° �ٿ� ����Ʋ�� ���� ���̿� ���� ���̰� �־�����
// �� ���� ���� �� �ִ� ���̽�ũ�� ���� ���

#include <iostream>

using namespace std;

int n, m;
int graph[1000][1000];

bool dfs(int x, int y) {                                             // DFS�� Ư�� ��带 �湮�ϰ� ����� ��� ���鵵 �湮
	if (x <= -1 || x >= n || y <= -1 || y >= m) {              // �־��� ������ ����� ��� ��� ����
		return false;
	}
	if (graph[x][y] == 0) {                                         // ���� ��带 �湮���� �ʾҴٸ�
		graph[x][y] = 1;                                           // �ش� ��� �湮 ó��
		dfs(x - 1, y);                                                // ��, �� , ��, ���� ��ġ�鵵 ��� ��������� ȣ��
		dfs(x, y - 1);
		dfs(x + 1, y);
		dfs(x, y + 1);
		return true;
	}
	return false;
}

int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {                                   // 2���� ����Ʈ�� �� ���� �Է� �ޱ�
		for (int j = 0; j < m; j++) {
			scanf_s("%1d", &graph[i][j]);
		}
	}

	int result = 0;               
	for (int i = 0; i < n; i++) {                                   // ��� ��忡 ���Ͽ� ����� ä���
		for (int j = 0; j < m; j++) {
			if (dfs(i, j)) {                                           // ���� ��ġ���� DFS ����
				result += 1;
			}
		}
	}
	cout << result << endl;
}