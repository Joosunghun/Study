// ���� 11047�� ���� 0
// ������ �ִ� ������ ���� N, ������ ���� ������ �ſ� ����
// ������ ������ ����ؼ� ���� K�� ������� ��
// �̶� �ʿ��� ���� ������ �ּڰ�

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
vector<int> arr;

bool compare(int a, int b) {                                 // ������������ �����ϱ� ���� ����� �� 
	return a > b;
}

int main(void) {
	cin >> n >> k;                                               // ���� ���� �� �� ����
	for (int i = 0; i < n; i++) {                                 // ������ ��� ���� �ֱ�
		int x;
		cin >> x;
		arr.push_back(x);
	}
	int result = 0;
	sort(arr.begin(), arr.end(), compare);               // ������ ũ�Ⱑ ū �ͺ��� ����
	for (int i = 0; i < n; i++) {                               
		while (k - arr[i] >= 0) {                               // �� ���ݿ��� ũ�Ⱑ ū �������� �� ���� 0�� ���� ���
			result++;                                                // ���� �ϳ� ���ϰ�
			k -= arr[i];                                             // �� ���ݸ�ŭ ����
		}
	} 

	cout << result << endl;                                    // �� ��� ���
}