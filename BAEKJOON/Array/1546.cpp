// ���� 1546�� ���
// ���� �� �ְ� ���� ��� �� ���� M�̶�� �� �� ��� ������ ����/M*100���� ���ƴ�
// ���ο� ������� ����� ���ϴ� ���α׷�

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	int n;
	double arr[1001];
	double sum = 0;
	double avg = 0;

	cin >> n;

	for (int i = 0; i < n; i++) {        // ���� �޾ƿ���
		cin >> arr[i];
	}

	sort(arr, arr+n);             // ������ ������������ ����

	for (int i = 0; i < n; i++) {          // ��ģ �������� �� ���ϱ�
		sum += arr[i] / arr[n - 1] * 100;
	}

	avg = sum / n;           // ���� ������ ������ ��� ���ϱ�
	cout << avg << '\n';

}