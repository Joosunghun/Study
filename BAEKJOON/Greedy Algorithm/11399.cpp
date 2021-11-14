// ���� 11399�� ATM
// ATM�� N���� ������� �� ���־�
// i�� ����� ���� �����ϴµ� �ɸ��� �ð� Pi��
// �տ� ����� ���� ���� ������ ��ٷ�����
// �� ����� ���� �����ϴµ� �ʿ��� �ð��� ���� �ּڰ��� ���ϴ� ���α׷�

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int n;
	vector<int> arr;

	cin >> n;
	for (int i = 0; i < n; i++) {                                // ��� Pi�ޱ�
		int x;
		cin >> x;
		arr.push_back(x);
	}

	sort(arr.begin(), arr.end());                            // ������������ ����
	int result = 0;
	for (int i = 0; i < n; i++) {                                 // �ð��� ���� �ּڰ��� ���ϱ����� arr[i]*(n-i) ��ŭ ������� ����
		result += arr[i]*(n-i);
	}

	cout << result << '\n';                                   // ����� ���
}