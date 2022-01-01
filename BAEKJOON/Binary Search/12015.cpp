// ���� 12015�� ���� �� �����ϴ� �κ� ���� 2
// ���� A�� �־����� ��, ���� �� �����ϴ� �κ� ������ ���ϴ� ���α׷�

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
		auto it = lower_bound(arr.begin(), arr.end(), x);            // lower_bound �Լ��� � ������ ũ�ų� ���� ���� ���� ������ �̺�Ž������ ã��
		if (it != arr.end())       // ã�� ���� �� ���� �ƴ϶�� it�� x���� �ִ´�
			*it = x;
		else                        // ���� ������ ���̶�� arr ���Ϳ� push
			arr.push_back(x);
	}
	
	cout << arr.size() << '\n';     // ������ ũ�⸦ ���
}