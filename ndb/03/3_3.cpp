// 3_3 ����ī�����
// N X M ���·� ���� ī��, N = ���� ����, M = ���� ����
// �࿡�� ���� ���ڰ� ���� ī�� �̱�
// ó���� ī�带 ��� ���� ������ ��, ���Ŀ� �ش� �࿡�� ���� ���ڰ� ���� ī�带 ������ ���, ���������� ���� ���� ������ ī�� �̱�

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	int n, m;
	int result;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {                    // ���� �ٿ� �Էµ� �� �� ���� ���� �� ã��
		int min_no = 10001;
		for (int j = 0; j < m; j++) {               // �� �پ� �Է¹ޱ�
			int x;
			cin >> x;
			min_no = min(min_no, x);          // min_no �� x �߿� �ּڰ�
		}

		result = max(result, min_no);         // ���õ� min_no �߿� �ִ� ã��
	}

	cout << result << endl;                    
}
