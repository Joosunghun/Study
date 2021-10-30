// 3_2 ū ���� ��Ģ
// N�� �ڿ���, M�� ���ϴµ� K ��ŭ�� �����ؼ� ������ �� ����

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int i, n, m, k;
	vector<int> arr;
	int result = 0;
	int count = 0;
	cin >> n >> m >> k;

	for (i = 0; i < n; i++) {                                // n ���� ���� arr�� �ֱ�
		int x;
		cin >> x;
		arr.push_back(x);
	}

	sort(arr.begin(), arr.end());                      // ����
	int first = arr[n - 1];                                 // ���� ū ��
	int second = arr[n - 2];                           // �� ��°�� ū��

	count = (m / (k + 1)) * k;                         // ���� ū ���� �������� Ƚ�� ���
	count += m % (k + 1);

	result += count * first;                             // ���� ū �� ���ϱ�
	result += (m - count) * second;               // �� ��°�� ū �� ���ϱ�

	cout << result << endl;
	
}
