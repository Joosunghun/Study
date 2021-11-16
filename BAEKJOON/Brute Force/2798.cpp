// ���� 2798�� ����
// ī���� ���� �ѵ� ������, �ִ��� ũ�� ����� ����
// N���� ī�忡 ���� �ִ� ���ڰ� �־����� ��, M�� ���� �����鼭 �ִ��� ����� ī�� 3���� �� ���ϱ�

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int n, m;
	vector<int> card;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {                      // ��� ī�� �� �޾ƿ���
		int x;
		cin >> x;
		card.push_back(x);
	}

	int result = 0;                                      // ��� �� �ʱ�ȭ
	for (int i = 0; i < n; i++) {                       // 3���� ���� ��� ����� ���� ���ϱ� ���� 3�� for�� ���
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				if ((card[i] + card[j] + card[k] <= m) && (card[i] + card[j] + card[k] > result))                       // 3���� ���� m���� �۰� �� ���� ��� �� ���� Ŭ �� 
					result = card[i] + card[j] + card[k];                                                                                // ��� ���� 3���� ��
			}
		}
	}

	cout << result << '\n';                         // ��� ���
}