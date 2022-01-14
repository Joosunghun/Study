// ���� 15650�� N�� M (2)
// �ڿ��� N�� M�� �־����� ��, ������ �����ϴ� ���̰� M�� ������ ��� ���ϴ� ���α׷�
// ���� 1 : 1���� N���� �ڿ��� �߿��� �ߺ����� M���� �� ����
// ���� 2 : �� ������ ��������

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
	for (int i = v; i <= n; i++) {
		if (visited[i] == false) {
			visited[i] = true;
			arr[cnt] = i;
			dfs(i + 1, cnt + 1);         // for���� index���� ����Լ��� ���ڷ� �Ѱ��־� �̹� ã�� ���� �ٽ� ���� �ʰ��ϱ�
			visited[i] = false;
		}
	}
}

int main(void) {
	cin >> n >> m;
	dfs(1, 0);
}