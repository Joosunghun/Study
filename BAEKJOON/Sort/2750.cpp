// ���� 2750�� �� �����ϱ�
// N���� ���� �־����� ��, �̸� ���� �������� �����ϴ� ���α׷�

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int n;
	vector<int> arr;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr.push_back(x);
	}

	sort(arr.begin(), arr.end());
	for (int i = 0; i < n; i++) {
		cout << arr[i] << '\n';
	}
}