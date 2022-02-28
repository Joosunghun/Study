// ���� 14889�� ��ŸƮ�� ��ũ
// N���̼� �౸�� �غ����� �Ѵ�. N/2������ �̷���� ��ŸƮ ���� ��ũ ������ ������� ����
// ��ȣ�� 1���� N���� �����߰�, �ɷ�ġ�� ����. �ɷ�ġ Sij�� i�� j�� ���� ���� ������ �� ���� �������� �ɷ�ġ��. 
// �� ���� �ɷ�ġ ������ �ּڰ��� ����ϴ� ���α׷�

#include <iostream>
#include <math.h>
using namespace std;

int stats[21][21];
bool check[22];
int n;
int ans = 100000000;

void dfs(int x, int pos) {             // x�� ī��Ʈ, pos�� ���� ��
	if (x == n / 2) {
		int start, link;
		start = 0;
		link = 0;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (check[i] == true && check[j] == true)
					start += stats[i][j];
				if (check[i] == false && check[j] == false)
					link += stats[i][j];
			}
		}

		int tmp = abs(start - link);
		if (ans > tmp)
			ans = tmp;

		return;
	}       

	for (int i = pos; i < n; i++) {
		check[i] = true;
		dfs(x + 1, i + 1);
		check[i] = false;
	}
}

int main(void) {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> stats[i][j];
		}
	}

	dfs(0, 1);        // ī��Ʈ�� 0, ���ڴ� 1���� ����

	cout << ans << '\n';
}