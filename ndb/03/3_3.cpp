<<<<<<< HEAD
// 3_3 숫자카드게임
// N X M 형태로 놓인 카드, N = 행의 개수, M = 열의 개수
// 행에서 가장 숫자가 낮은 카드 뽑기
// 처음에 카드를 골라낼 행을 선택할 떄, 이후에 해당 행에서 가장 숫자가 낮은 카드를 뽑을걸 고려, 최종적으로 가장 높은 숫자의 카드 뽑기
=======
// 3_3 �닽�옄移대뱶寃뚯엫
// N X M �삎�깭濡� �넃�씤 移대뱶, N = �뻾�쓽 媛쒖닔, M = �뿴�쓽 媛쒖닔
// �뻾�뿉�꽌 媛��옣 �닽�옄媛� �궙��� 移대뱶 戮묎린
// 泥섏쓬�뿉 移대뱶瑜� 怨⑤씪�궪 �뻾�쓣 �꽑�깮�븷 �뻹, �씠�썑�뿉 �빐�떦 �뻾�뿉�꽌 媛��옣 �닽�옄媛� �궙��� 移대뱶瑜� 戮묒쓣嫄� 怨좊젮, 理쒖쥌�쟻�쑝濡� 媛��옣 �넂��� �닽�옄�쓽 移대뱶 戮묎린
>>>>>>> d91d49590df568eabc8f0a53fffddf02a5b06acf

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	int n, m;
	int result;

	cin >> n >> m;
<<<<<<< HEAD
	for (int i = 0; i < n; i++) {                    // 현재 줄에 입력된 값 중 가장 작은 값 찾기
		int min_no = 10001;
		for (int j = 0; j < m; j++) {               // 한 줄씩 입력받기
			int x;
			cin >> x;
			min_no = min(min_no, x);          // min_no 와 x 중에 최솟값
		}

		result = max(result, min_no);         // 선택된 min_no 중에 최댓값 찾기
=======
	for (int i = 0; i < n; i++) {                    // �쁽�옱 以꾩뿉 �엯�젰�맂 媛� 以� 媛��옣 �옉��� 媛� 李얘린
		int min_no = 10001;
		for (int j = 0; j < m; j++) {               // �븳 以꾩뵫 �엯�젰諛쏄린
			int x;
			cin >> x;
			min_no = min(min_no, x);          // min_no ��� x 以묒뿉 理쒖넖媛�
		}

		result = max(result, min_no);         // �꽑�깮�맂 min_no 以묒뿉 理쒕뙎媛� 李얘린
>>>>>>> d91d49590df568eabc8f0a53fffddf02a5b06acf
	}

	cout << result << endl;                    
}
