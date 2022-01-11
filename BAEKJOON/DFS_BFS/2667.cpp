// ���� 2667�� �ݵ��ȣ���̱�
// ���簢�� ����� ����, 1�� ���� �ִ°�, 0�� ���� ���� ��
// ����� ���� ������ ������ �����ϰ�, ������ ��ȣ�� ���δ�.
// �밢���� �ִ� ���� ����� ���� �ƴ�
// ������ �Է��Ͽ� �������� ����ϰ�, �� ������ ���ϴ� ���� ���� ������������ �����Ͽ� ����ϴ� ���α׷��� �ۼ�

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n;
int map[26][26];
bool visited[26][26];
vector<int> v;
int cnt = 0;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

void dfs(int x, int y) {
	visited[x][y] = true;
	cnt++;
	map[x][y] = 1;
	for (int i = 0; i < 4; i++) {      // 4�������� �̵��ϸ� Ž��
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= n || ny >= n)
			continue;

		if (map[nx][ny] == 1 && visited[nx][ny] == false)
			dfs(nx, ny);
	}
}

int main(void) {	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;            // ���簢���� ũ��

	for (int i = 0; i < n; i++) {            // �ʿ� 1, 0�ֱ�
		string input;
		cin >> input;

		for (int j = 0; j < n; j++) {
			map[i][j] = input.at(j) - '0';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == false && map[i][j] == 1) {
				dfs(i, j);
				v.push_back(cnt);         // ����Ǿ��ִ� ����Ʈ push
				cnt = 0;
			}
		}
	}

	cout << v.size() << '\n';          // ������ ����
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}
	return 0;
}