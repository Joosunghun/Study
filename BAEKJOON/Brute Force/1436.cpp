// ���� 1436�� ��ȭ���� ��
// 6�� ��� 3���̻� �������� ���� ��
// ���� ���� ���� 666. �� �������� ū ���� 1666,2666,3666...
//  N��° ��ȭ ���� �� ���ڸ� ����ϴ� ���α׷�

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int n;
	int start = 666;
	int cnt = 0;
	int temp;
	cin >> n;

	while (1) {
		temp = start;
		
		while (temp > 0) {          // ���� �ȿ� 666�� �ִ��� Ȯ��
			if (temp % 1000 == 666) {
				cnt++;
				break;
			}
			temp /= 10;
		}

		if (cnt == n) {              // n��° ���ڸ� ã���� ���
			cout << start << '\n';
			break;
		}

		start++;                      // ã�� ���ڰ� �ƴ϶�� start �����ؼ� �ٽ� ����
	}
}