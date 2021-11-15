// ���� 11650�� ��ǥ �����ϱ�
// 2���� ��� ���� �� N�� �־���
// ��ǥ�� x��ǥ�� �����ϴ� ������, ��ǥ�� ������ y��ǥ�� �����ϴ� ������ �����ϴ� ���α׷�

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int n;
	vector<pair<int, int>> arr;                                                  // ��ǥ�� �����ϱ� ���� 2���� �迭 

	cin >> n;
	for (int i = 0; i < n; i++) {                                                   // ��� ��ǥ�� �޾ƿ���
		int a, b;
		cin >> a >> b;
		arr.push_back(make_pair(a, b));
	}

	sort(arr.begin(), arr.end());                                             // first�� �������� �������� ���� �� ������ second�� �������� �������� ����

	for (int i = 0; i < n; i++) {                                                  // ����� ���
		cout << arr[i].first << " " << arr[i].second << "\n";
	}
}