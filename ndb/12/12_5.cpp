// 12_5 ��
// N x N ���簢 ���� ������ ����, ��� ĭ���� ����� ������ ����, �� �����¿쿣 ��, �� �Ǵ� �ڱ� �ڽ��� ���� �ε����� ������ ����
// ���� ���� ��ġ�� �� �� �� ����, ���� ���� 1, ó���� �������� ����
// �� �� �� �̵�, ��Ģ�� ����
// ������ �÷� �Ӹ��� ���� ĭ�� ��ġ
// �̵��� ĭ�� ����� �ִٸ�, ����� �������� �����ȿ�����
// ����� ���ٸ�, �����̸��ٿ� ������ ��ġ�� ĭ�� ����, �����̴� ������ ����
// ����� ��ġ�� ���� �̵���ΰ� �־��� �� ������ ���ʿ� ������ �� ����ϴ� ���α׷�

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, k, l;
int arr[101][101];                        // ���� ���� �迭
vector<pair<int, char>> info;         // ���� ȸ�� ����

int dx[] = { 0, 1, 0, -1 };               // ó������ �������� ���� ������, ��, ��, ��, ��
int dy[] = { 1, 0, -1, 0 };

int turn(int direction, char c) {
	if (c == 'L')
		direction = (direction == 0) ? 3 : direction - 1;
	else
		direction = (direction + 1) % 4;
	return direction;
}

int simulate() {
	int x = 1, y = 1;                       // ���� �Ӹ� ��ġ
	arr[x][y] = 2;                         // ���� �����ϴ� ��ġ�� 2�� ǥ��
	int direction = 0;                     // ó������ ������ ��������
	int time = 0;                           // ������ �ڿ� ���� '��' �ð�
	int index = 0;                         // ������ ȸ���� ����
	queue<pair<int, int>> q;         // ���� �����ϰ� �ִ� ��ġ ����(������ ����)
	q.push({ x,y });

	while (true) {
		int nx = x + dx[direction];
		int ny = y + dy[direction];
		if (1 <= nx && nx <= n && 1 <= y && ny <= n && arr[nx][ny] != 2) {          // �� ���� �ȿ� �ְ� ,���� ������ ������ġ���
			if (arr[nx][ny] == 0) {                                                                   // ����� ���ٸ� �̵� �Ŀ� ���� ����
				arr[nx][ny] = 2;
				q.push({ nx,ny });
				int px = q.front().first;
				int py = q.front().second;
				q.pop();
				arr[px][py] = 0;
			}
			if (arr[nx][ny] == 1) {                                                                  // ����� �ִٸ� �̵� �Ŀ� ���� �״�� �α�
				arr[nx][ny] = 2;
				q.push({ nx,ny });
			}
		}
		else {                                                                                            // ���̳� ���� ���� �� �΋H���ٸ�
			time += 1;
			break;
		}
		x = nx;                                                                                           // ���� ��ġ�� �Ӹ��� �̵�
		y = ny;
		time += 1;
		if (index < 1 && time == info[index].first) {                                          // ȸ���� �ð��� ��� ȸ��
			direction = turn(direction, info[index].second);
			index += 1;
		}
	}
	return time;
}

int main(void) {
	cin >> n >> k;

	for (int i = 0; i < k; i++) {                      // �� ���� (����� �ִ� ���� 1�� ǥ��)
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
	}

	cin >> l;                                            // ���� ȸ�� ���� �Է�
	for (int i = 0; i < l; i++) {
		int x;
		char c;
		cin >> x >> c;
		info.push_back({ x,c });
	}

	cout << simulate() << '\n';                // �ùķ��̼� ���
}