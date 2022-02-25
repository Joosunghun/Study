// ���� 9663�� N-Queen
// N-Queen ������ ũ�Ⱑ N x N�� ü���� ���� �� N���� ���� ������ �� ���� ����� ����
// N�� �־����� ��, ���� ���� ����� ���� ���ϴ� ���α׷�

#include <iostream>
#include <vector>
using namespace std;

int n;
int ans = 0;

vector<int> visited(15);           // ü���� �迭

bool Check(int x) {
	for (int i = 0; i < x; i++) {
		if (visited[x] == visited[i] || x - i == abs(visited[x] - visited[i]))            // ������ ���� ������ �� �ִٸ� 0
			return 0;
	}

	return 1;          // ���� ��ġ�� �Ǹ� 1
}

void Queen(int x) {
	if (x == n) {              // ���� ��ġ�� ���� ������ �Է°��� ���ٸ� Ż��
		ans++;
		return;
	}

	for (int j = 0; j < n; j++) {         
		visited[x] = j;              // [x, j]�� ���� ��ġ�غ��� ��ġ�� �� �ִٸ� ���� ���� +1�ϰ� ���� ���� ��ġ�Ѵ�

		if (Check(x))
			Queen(x + 1);
	}
}

int main(void) {
	cin >> n;
	Queen(0);
	cout << ans;
}