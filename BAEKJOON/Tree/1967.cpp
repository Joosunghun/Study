// ���� 1967�� Ʈ���� ����
// ���� 1167���� ���� ����
// ��Ʈ�� �ִ� Ʈ���� ����ġ�� �ִ� ������� �� ��, Ʈ���� ������ ���ؼ� ����ϴ� ���α׷�

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<pair<int, int>> node[10002];
bool visited[10002] = { false, };
int result = 0;
int endPoint = 0;

void dfs(int start, int len) {
	if (visited[start])          // �̹� �湮�� ��
		return;

	visited[start] = true;          // ���� ������Ʈ
	if (result < len) {
		result = len;
		endPoint = start;
	}

	for (int i = 0; i < node[start].size(); i++) {
		dfs(node[start][i].first, len + node[start][i].second);
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	
	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		node[a].push_back({ b,c });
		node[b].push_back({ a,c });
	}

	dfs(1, 0);           //���� �ָ��ִ� �� ���ϱ�
	result = 0;
	memset(visited, false, sizeof(visited));

	dfs(endPoint, 0);          // ���� ���ϱ�
	cout << result << '\n';
}