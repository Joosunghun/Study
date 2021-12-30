// ���� 2110�� ������ ��ġ
// �� N���� ������ ���� �ִ�. �� �������� ���� ��ǥ�� ������ ���� ����.
// ���� ������ C���� ��ġ�Ϸ����Ѵ�. �� ������ �ϳ��� ������ ��ġ ����, ���� ������ �� ������ ������ �Ÿ��� ������ ũ�� �Ͽ� ��ġ�Ϸ��� �Ѵ�.
// C���� �����⸦ N���� ���� ������ ��ġ�ؼ�, ���� ������ �� ������ ������ �Ÿ��� �ִ�� �ϴ� ���α׷�

#include <iostream>
#include <vector>
#include  <algorithm>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, c;
	vector<int> arr;

	cin >> n >> c;
	for (int i = 0; i < n; i++) {    // �����⿡ �� �ֱ�
		int x;
		cin >> x;
		arr.push_back(x);
	}

	sort(arr.begin(), arr.end());     // ����

	int start = 0;
	int end = arr.back();       
	int ans = 0;

	while (start <= end) {
		long long mid = (start + end) / 2;
		int before_set_idx = 0;
		int set_num = 1;

		for (int i = 1; i < n; i++) {        // �������� ���� ���� ���� mid �̻��� ��쿡�� ��ġ ����
			if (arr[i] - arr[before_set_idx] >= mid) {      // ���� ��ġ�� ���� ��ġ�� ��ġ�� ������ mid ���� ũ�ٸ�
				before_set_idx = i;               // ���� ��ġ �ֱ�
				set_num++;
			}
		}

		if (set_num >= c) {             // �Է¹��� ������ C���� ũ�� ������ �ִ�, start�� �����Ͽ� �� ū �� Ž��
			ans = mid;
			start = mid + 1;
		}           
		
		else                              // �ݴ��� ��� end�� �����Ͽ� �� ���� �� Ž��
			end = mid - 1;

	}
	cout << ans << '\n';
	return 0;

}