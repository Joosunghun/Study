// ���� 10818�� �ּ�, �ִ�
// N���� ������ �־�����. �̶�, �ּڰ��� �ִ��� ���ϴ� ���α׷�

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int n;
	vector<int> arr;

	cin >> n;

	for (int i = 0; i < n; i++) {        // ���Ϳ� n������ŭ ���� �ֱ�
		int x;
		cin >> x;
		arr.push_back(x);
	}

	sort(arr.begin(), arr.end());      // ������������ ����

	int max = arr[n-1];          
	int min = arr[0];

	cout << min << ' ' << max << '\n';
}