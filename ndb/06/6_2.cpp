// 6_2 ������ �Ʒ���
// �ϳ��� �������� ū�� ���� ���� ���� ������������ �����ϴ� ���α׷�

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<int> arr;

bool compare(int a, int b) {                                   // �׳� �����ϸ� ���������̹Ƿ� ���������� ���� ����
	return a > b;
}

int main(void) {
	cin >> n;                                                       // n �Է� �ޱ�
	for (int i = 0; i < n; i++) {                                  // n ���� ������ �Է¹޾� ����Ʈ�� ����
		int x; 
		cin >> x;
		arr.push_back(x);
	}
	
	sort(arr.begin(), arr.end(), compare);                // �������� ����

	for (int i = 0; i < n; i++) {                                   // ���
		cout << arr[i] << ' ';
	}
}