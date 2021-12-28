// ���� 1654 ���� �ڸ���
// N���� ������ �����.
// K���� ������ ������ �ִµ�, ���̰� �������̴�. N���� ���� ������ �������� ����� �ͱ⶧���� K���� ������ �߶� �����.
// �̶� N�� �̻� ����鼭 ���� �� �ִ� �ִ� ������ ���̸� ���ϴ� ���α׷�

#include <iostream>
#include <algorithm>
using namespace std;


int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;          // N���� ���� �����, K���� ���� ����������
	int arr[10001];
	cin >> k >> n;

	for (int i = 0; i < k; i++) {       // k�� ���� �ֱ�
		cin >> arr[i];
	}

	long long left = 1;
	long long right = *max_element(arr, arr+ k);           // *max_element =���� �ȿ��� �ִ� ���� ���ϴ� �Լ�
	int ans = 0;

	while(left <= right) {
		long long mid = (left + right) / 2;
		int cnt = 0;
		for (int i = 0; i < k; i++) {
			cnt += (arr[i] / mid);
		}

		if (cnt < n)      // ���� ������ �ʿ��� �������� ������ �� �۰� �߶����
			right = mid - 1;
		else {
			ans = mid;
			left = mid + 1;
		}
	}

	cout << ans << '\n';

	return 0;
}