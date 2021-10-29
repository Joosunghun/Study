// 1이 될때 까지

#include <iostream>
using namespace std;

int main() {
	int n, k;
	int count = 0;
	int rem;
	cin >> n;    
	cin >> k;

	while (1) {
		rem = n % k;                           // 나머지 만큼 카운트해줌  
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
