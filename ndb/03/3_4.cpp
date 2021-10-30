// 3_4 1이 될때 까지
// 두 과정 중 하나를 반복적으로 선택하여 수행
// N-1 or N/K
// 이 과정들을 1이 될 떄까지 수행해야 하는 최소 횟수

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
