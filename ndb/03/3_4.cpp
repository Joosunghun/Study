<<<<<<< HEAD
// 3_4 1�� �ɶ� ����
// �� ���� �� �ϳ��� �ݺ������� �����Ͽ� ����
// N-1 or N/K
// �� �������� 1�� �� ������ �����ؾ� �ϴ� �ּ� Ƚ��
=======
// 3_4 1이 될때 까지
// 두 과정 중 하나를 반복적으로 선택하여 수행
// N-1 or N/K
// 이 과정들을 1이 될 떄까지 수행해야 하는 최소 횟수
>>>>>>> d91d49590df568eabc8f0a53fffddf02a5b06acf

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

<<<<<<< HEAD
		if (n < k) {                              // n �� K ���� �۾����� ���� �� ���� �� �ݺ��� Ż��
=======
		if (n < k) {                              // n 이 K 보다 작아져서 나눌 수 없을 때 반복문 탈출
>>>>>>> d91d49590df568eabc8f0a53fffddf02a5b06acf
			count -= 1;                          
			break;
		}

<<<<<<< HEAD
		count += 1;                             // Ƚ�� 1ȸ ����
		n /= k;                                   // n�� K�� ������
=======
		count += 1;                             // 횟수 1회 증가
		n /= k;                                   // n을 K로 나누기
>>>>>>> d91d49590df568eabc8f0a53fffddf02a5b06acf
	}

	cout  <<  count  <<  endl;

	return 0;
}
