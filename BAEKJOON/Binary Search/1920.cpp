// ���� 1920 �� ã��
// N���� ������ �־��� ���� ��, �� �ȿ� X��� ������ �����ϴ� �� �˾Ƴ��� ���α׷� �ۼ�

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binary_search(vector<int>& arr, int target, int start, int end) {       // ����Ž��
	while (start <= end) {                  
		int mid = (start + end) / 2;                  // �߰� ��
		if (arr[mid] == target)                        // �߰� ���� Ÿ���̸� 
			return 1;                                      // 1�� ����
		else if (arr[mid] > target)                   // �߰� ���� Ÿ�ٺ��� ũ�� ���� ���ݿ��� Ž��
			end = mid - 1;                             
		else                                                // �߰� ���� Ÿ�ٺ��� ������ ������ ���ݿ��� Ž��
			start = mid + 1;
	}
	return 0;
}

int main(void) {
	int n, m;
	vector<int> arr;
	vector<int> target;
	
	cin >> n;
	for (int i = 0; i < n; i++) {            // n�� �޾ƿ���
		int x;
		cin >> x;
		arr.push_back(x);
	}

	sort(arr.begin(), arr.end());       // n �� �������� ����

	cin >> m;
	for (int i = 0; i < m; i++) {           // m�� �޾ƿ���
		int x;
		cin >> x;
		target.push_back(x);
	}

	for (int i = 0; i < m; i++) {
		int check = binary_search(arr, target[i], 0, n - 1);     // ����Ž�� ����
		if (check == 1)                   // 1�� ��ȯ�ϸ� 1 ���
			cout << 1 << '\n';
		else                                 // �׷��� ������ 0 ���
			cout << 0 << '\n';
	}

}