// ���� 14888�� ������ �����ֱ�
// N���� ���� �̷���� ������ �־�����. ��, ���� �� ���̿� �������� �� �ִ� n-1���� �����ڰ� �־�����. �����ڴ� ����,����,����,���������θ� �̷���� �ִ�.
// ���� �� ���̿� �����ڸ� �ϳ��� �־, ������ �ϳ� ���� �� �ִ�. �̶�, �־��� ���� ������ �ٲٸ� �ȵȴ�.
// n���� ���� n-1���� �����ڰ� �־����� ��, ���� �� �ִ� ���� ����� �ִ��� �Ͱ� �ּ��� ���� ���ϴ�  ���α׷�

#include <iostream>
using namespace std;

int n;
int a[12];
int b[4];
int max_num, min_num;
int chk[11];

void Calc() {
	int tmp = a[0];
	for (int i = 1; i < n; i++) {
		switch (chk[i]) {
		case 0: tmp += a[i]; break;
		case 1: tmp -= a[i]; break;
		case 2: tmp *= a[i]; break;
		case 3: tmp /= a[i]; break;
		}
	}
	if (tmp > max_num)
		max_num = tmp;
	if (tmp < min_num)
		min_num = tmp;
}

void dfs(int x) {
	if (x == n) {
		Calc();
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (b[i] == 0)
			continue;
		chk[x] = i;
		b[i]--;
		dfs(x + 1);
		b[i]++;
		chk[x] = 0;
	}
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> b[i];
	}

	max_num = -0x7fffffff;
	min_num = 0x7fffffff;

	dfs(1);

	cout << max_num << '\n';
	cout << min_num << '\n';
}