// ���� 2839�� ���� ���
// �������Կ� ���� ��Ȯ�ϰ� nų�η��� ����ؾ��Ѵ�.
// ���� ������ 3Ű�ο� 5Ű�ΰ� �ִ�.
// ������ ��Ȯ�ϰ� Nų�� �׷� ����ؾ� �� ��, ���� �� ���� �������� �Ǵ��� �� ���� ���ϴ� ���α׷�

#include <iostream>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	int a, b;
	a = n / 5;
	while (1) {
		if (a < 0) {
			cout << "-1";
			return 0;
		}
		if ((n - (5 * a)) % 3 == 0){
			b = (n - (5 * a)) / 3;
			break;
		}
		a--;
	}

	cout << a + b;
	return 0;
}