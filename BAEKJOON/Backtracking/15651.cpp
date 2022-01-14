// ���� 15651�� N�� M(3)
// �ڿ��� N�� M�� �־����� ��, ������ �����ϴ� ���̰� M�� ������ ��� ���ϴ� ���α׷�
// ����1. 1���� N���� �ڿ��� �߿��� M���� �� ����, ����2. ���� ���� ������ ��� ��

#include <iostream>
using namespace std;

int n, m;
int arr[9];
bool visited[9];

void dfs(int v) {
	if (v == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
	}
	else {
		for (int i = 1; i <= n; i++) {       // �湮�ߴ����� ������ �ʰ��ߴ� if���� �����Ͽ� ���� ���� �� ����
			visited[i] = true;
			arr[v] = i;
			dfs(v + 1);
			visited[i] = false;
		}
	}
}

int main(void) {
	cin >> n >> m;
	dfs(0);
}