<<<<<<< HEAD
// 3_4 1이 될때 까지
// 두 과정 중 하나를 반복적으로 선택하여 수행
// N-1 or N/K
// 이 과정들을 1이 될 떄까지 수행해야 하는 최소 횟수
=======
// 3_4 1�씠 �맆�븣 源뚯��
// �몢 怨쇱젙 以� �븯�굹瑜� 諛섎났�쟻�쑝濡� �꽑�깮�븯�뿬 �닔�뻾
// N-1 or N/K
// �씠 怨쇱젙�뱾�쓣 1�씠 �맆 �뻹源뚯�� �닔�뻾�빐�빞 �븯�뒗 理쒖냼 �슏�닔
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
		rem = n % k;                           // �굹癒몄�� 留뚰겮 移댁슫�듃�빐以�  
		count += rem;
		n -= rem;

<<<<<<< HEAD
		if (n < k) {                              // n 이 K 보다 작아져서 나눌 수 없을 때 반복문 탈출
=======
		if (n < k) {                              // n �씠 K 蹂대떎 �옉�븘�졇�꽌 �굹�닃 �닔 �뾾�쓣 �븣 諛섎났臾� �깉異�
>>>>>>> d91d49590df568eabc8f0a53fffddf02a5b06acf
			count -= 1;                          
			break;
		}

<<<<<<< HEAD
		count += 1;                             // 횟수 1회 증가
		n /= k;                                   // n을 K로 나누기
=======
		count += 1;                             // �슏�닔 1�쉶 利앷��
		n /= k;                                   // n�쓣 K濡� �굹�늻湲�
>>>>>>> d91d49590df568eabc8f0a53fffddf02a5b06acf
	}

	cout  <<  count  <<  endl;

	return 0;
}
