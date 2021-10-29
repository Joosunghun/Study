// 7-3 ������ �� �����
// �� ���� N. ���� ���� M
// ���ܱ�� ���� �ڸ� ��ŭ �մ��� ������ 
// �մ��� M ��û�� ��ŭ ���������� �� �� ���ܱ� ����

#include <iostream>;
#include <vector>;
#include <algorithm>;
using namespace std;

int main(void) {
	int n, m;
	vector<int> arr;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {                    // ���� ���� ��ŭ ���� �ֱ�
		int x;
		cin >> x;
		arr.push_back(x);
	}

	sort(arr.begin(), arr.end());
	int start = 0;
	int end = arr[n-1];
	int result = 0;
	while (start <= end) {
		long long int total = 0;
		int mid = (start + end) / 2;           // �߰� �� ( ���ܱ� ��)
		for (int i = 0; i < n; i++) {             // �߶��� �� ���� �� ����ϱ�
			if (arr[i] > mid)  total = total + arr[i] - mid;
		}
		if (total < m)                      // ��Ż ���� m ���� ������ �������� ��ĭ �̵�
			end = mid - 1;
		else
			result = mid;                 // �ִ��� ���� �߶��� �� �̹Ƿ� result ���
			start = mid + 1;              // ��Ż ���� m ���� ũ�� ���������� ��ĭ �̵�
	}
	cout << result;
}

// MAX �Լ� ���� end  ���� �����ϰ� ��������