// 7-2 ��ǰã��
// ������ �ִ� ��ǰN, �մ��� ��û�� ��ǰ M
// N,M Ȯ���ؼ� ������ yes, ������ no ���

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ���� Ž��
int binarySearch(vector<int>& arr, int target, int start, int end) {

	while (start <= end) {
		int mid = (start + end) / 2;                               // �߰� ��
		if (arr[mid] == target)                                     // Ÿ���� ã���� �� ���� ���
			return mid;                      
		else if (arr[mid] > target)                               // Ÿ���� �߰� ������ ������ �������� �̵�
			end = mid - 1;         
		else                                                            // Ÿ���� �߰� ������ ũ�� ���������� �̵�
			start = mid + 1;                                       
	}
	return -1;
}

void main() {
	int n, m;
	vector<int> arr;
	vector<int> targets;

	cin >> n;
	for (int i = 0; i < n; i++) {                                    // ���Կ� �ִ� ��ǰ arr �迭�� �ֱ�
		int x;
		cin >> x;
		arr.push_back(x);
	}

	sort(arr.begin(), arr.end());                                // ���Կ� �ִ� ��ǰ ����

	cin >> m;                                                         
	for (int i = 0; i < m; i++) {                                  // �մ��� ��û�� ��ǰ target �迭�� �ֱ�
		int y;
		cin >> y;
		targets.push_back(y);
	}

	for (int i = 0; i < m; i++) {
		int check = binarySearch(arr, targets[i], 0, n - 1);   // Ž���� ���� ��ǰ ���� ���� Ȯ��
		if (check != -1)
			cout << "yes ";
		else
			cout << "no ";
	}
}