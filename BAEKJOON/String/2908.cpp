// ���� 2908�� ���
// �� �ڸ� �� �� ���� �־�����.
// �� ���� �Ųٷ� �о�, �� ū ���� ����ϴ� ���α׷�

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string x, y;
	string nx, ny;

	cin >> x >> y;
	for (int i = 2; i >= 0; i--) {          // �� ���� ������ ���� 
		nx += x[i];
		ny += y[i];
	}

	cout << max(nx, ny);          // �� ���� ū �� ���
}