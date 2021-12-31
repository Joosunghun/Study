// ���� 1330�� K��° ��
// ũ�Ⱑ N X N �� �迭 A, �迭�� ����ִ� �� A[i][j] = i x j �̴�.
// �� ���� ������ �迭 B�� ������ B�� ũ��� N x N �̵ȴ�.
// B�� �������� ���� ���� ��, B[k]�� ���ϴ� ���α׷�

#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, k;
	cin >> n >> k;

	int start = 1;
	int end = k;
	int result = 0;
	while (start <= end) {
		int cnt = 0;
		int mid = (start + end) / 2;
		for (int i = 1; i <= n; i++) {
			cnt += min(mid / i, n);        // mid���� ���� j�� �� (i + j <= mid)
		}
		if (cnt < k)
			start = mid + 1;
		else {
			result = mid;
			end = mid - 1;
		}
	}
	cout << result << '\n';
}