// 9_2 �̷�����
// ù° �ٿ� ȸ�� ���� N, ��� ���� M
// ��° �� ���� M+1 ��° �ٱ��� ����� �� ȸ���� ��ȣ
// M+2 ��° �ٿ��� X�� K�� �־���
// A�� 1 ���� ����ؼ� K�� ȸ�縦 ���� X�� ȸ��� ���� �ּ� �̵��ð�
// X�� ȸ�翡 ������ �� ������ -1 ���

#include <iostream>
#include <algorithm>
#define INF 1e9                                       // ������ �ǹ��ϴ� �� ����

using namespace std;

int main(void) {
	int n, m;                                             // ����� ������ ������ ����
	int graph[101][101];                            // 2���� �迭 �����

	cin >> n >> m;
	for (int i = 0; i < 101; i++) {                    // �ڱ� �ڽſ��� �ڱ� �ڽ����� ���� ��δ� 0���� �ʱ�ȭ
		fill(graph[i], graph[i] + 101, INF);
	}

	for (int i = 0; i < m; i++) {                       // �� ������ ������ �Է� �޾� �� ������ �ʱ�ȭ
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;                             // A�� B�� ���ο��� ���� ����� 1�̶�� ����
		graph[b][a] = 1;
	}

	int x, k;                                              // ���İ� ��� x�� ���� ������ k �Է� 
	cin >> x >> k;

	for (int k = 1; k <= n; k++) {                   // �÷��̵� ���� �˰��� ����
		for (int a = 1; a <= n; a++) {
			for (int b = 1; b <= n; b++) {
				graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b]);
			}
		}
	}
	
	int distance = graph[1][k] + graph[k][x];         // ����� ��� ���

	if (distance >= INF) {
		cout << -1 << endl;
	}
	else {
		cout << distance << endl;
	}
}

