// 3_4 1�� �ɶ� ����
// �� ���� �� �ϳ��� �ݺ������� �����Ͽ� ����
// N-1 or N/K
// �� �������� 1�� �� ������ �����ؾ� �ϴ� �ּ� Ƚ��

#include <iostream>
using namespace std;

int main() {
	int n, k;
	int count = 0;
	int rem;
	cin >> n;    
	cin >> k;

	while (1) {
		rem = n % k;                           // ������ ��ŭ ī��Ʈ����  
		count += rem;
		n -= rem;

		if (n < k) {                              // n �� K ���� �۾����� ���� �� ���� �� �ݺ��� Ż��
			count -= 1;                          
			break;
		}

		count += 1;                             // Ƚ�� 1ȸ ����
		n /= k;                                   // n�� K�� ������
	}

	cout  <<  count  <<  endl;

	return 0;
}
