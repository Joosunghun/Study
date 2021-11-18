// 11_4 ����� ���� �ݾ�
// N���� ����
// �� ������ �̿��Ͽ� ���� �� ���� ���� ���� �ݾ� �� �ּڰ�


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int n;
	vector<int> price;

	cin >> n;
	for (int i = 0; i < n; i++) {                        // ��� ������ ���� �޾ƿ���
		int x;
		cin >> x;
		price.push_back(x);
	}

	sort(price.begin(), price.end());             // ������ ������ ���� �� ���� ����
	
	int result = 1;                                        // �ּڰ� 1
	for (int i = 0; i < n; i++) {                        
		if (result < price[i])                           // �ּڰ��� ���� ���ݺ��� ������ �ű⼭ ����
			break;
		result += price[i];                              // �ּڰ��� ���ݸ�ŭ ������
	}

	cout << result << '\n';                          // ��� ���
}