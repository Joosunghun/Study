<<<<<<< HEAD
// 3_3 ����ī�����
// N X M ���·� ���� ī��, N = ���� ����, M = ���� ����
// �࿡�� ���� ���ڰ� ���� ī�� �̱�
// ó���� ī�带 ��� ���� ������ ��, ���Ŀ� �ش� �࿡�� ���� ���ڰ� ���� ī�带 ������ ���, ���������� ���� ���� ������ ī�� �̱�
=======
// 3_3 숫자카드게임
// N X M 형태로 놓인 카드, N = 행의 개수, M = 열의 개수
// 행에서 가장 숫자가 낮은 카드 뽑기
// 처음에 카드를 골라낼 행을 선택할 떄, 이후에 해당 행에서 가장 숫자가 낮은 카드를 뽑을걸 고려, 최종적으로 가장 높은 숫자의 카드 뽑기
>>>>>>> d91d49590df568eabc8f0a53fffddf02a5b06acf

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	int n, m;
	int result;

	cin >> n >> m;
<<<<<<< HEAD
	for (int i = 0; i < n; i++) {                    // ���� �ٿ� �Էµ� �� �� ���� ���� �� ã��
		int min_no = 10001;
		for (int j = 0; j < m; j++) {               // �� �پ� �Է¹ޱ�
			int x;
			cin >> x;
			min_no = min(min_no, x);          // min_no �� x �߿� �ּڰ�
		}

		result = max(result, min_no);         // ���õ� min_no �߿� �ִ� ã��
=======
	for (int i = 0; i < n; i++) {                    // 현재 줄에 입력된 값 중 가장 작은 값 찾기
		int min_no = 10001;
		for (int j = 0; j < m; j++) {               // 한 줄씩 입력받기
			int x;
			cin >> x;
			min_no = min(min_no, x);          // min_no 와 x 중에 최솟값
		}

		result = max(result, min_no);         // 선택된 min_no 중에 최댓값 찾기
>>>>>>> d91d49590df568eabc8f0a53fffddf02a5b06acf
	}

	cout << result << endl;                    
}
