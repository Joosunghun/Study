// ���� 15649�� N�� M(1)
// �ڿ��� N�� M�� �־����� ��, 1���� N���� �ڿ��� �߿��� �ߺ� ���� M���� �� ������ ��� ���ϴ� ���α׷�

#include <iostream>
using namespace std;

int n, m;
int arr[9];
bool visited[9];

void dfs(int v) {
	if (v == m) {
		for (int i = 0; i < m; i++)         // arr�� ������ �� �߷�
			cout << arr[i] << ' ';
		cout << '\n';
	}
	else {
		for (int i = 1; i <= n; i++) {
			if (visited[i] == false) {
				visited[i] = true;
				arr[v] = i;            // �迭�� i�� ����
				dfs(v + 1);           // v���� 1�� ���ϸ� ���
				visited[i] = false;
			}
		}
	}
}

int main(void) {
	cin >> n >> m;
	dfs(0);
}