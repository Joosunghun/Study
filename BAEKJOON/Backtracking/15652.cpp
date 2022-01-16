// ���� 15652�� N�� M(4)
// �ڿ��� N�� M�� �־����� ��, ������ �����ϴ� ���̰� M�� ������ ��� ���ϴ� ���α׷�
// ����1. 1���� N���� �ڿ��� �߿��� M���� �� ����, ����2. ���� ���� ������ ��� �� ����3. �� ������ �񳻸�����

#include <iostream>
using namespace std;

int n, m;
int arr[9];
bool visited[9];

void dfs(int v, int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
	}
	else {
		for (int i = v; i <= n; i++) {
				visited[i] = true;
				arr[cnt] = i;
				dfs(i, cnt + 1);    
				visited[i] = false;
		}
	}
}

int main(void) {
	cin >> n >> m;
	dfs(1, 0);
}