// 1�� �ɶ� ����

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

		if (n < k) {
			count -= 1;
			break;
		}

		count += 1;
		n /= k;  
	}

	cout  <<  count  <<  endl;

	return 0;
}
