// ���� 2805�� ���� �ڸ���
// ���� M ���Ͱ� �ʿ�. ���ܱ��� ���� H, H���� ���̰� ū ������ �� �κ��� �߸�
// �� �ʿ丸 ��ŭ�� ������ �ڸ����� �� ��, ���ܱ⿡ �����Ҽ� �ִ� �ִ��� ���ϴ� ���α׷�

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int n, m;           // ������ �� ��, �ʿ��� ������ ����
	vector<int> h;      // ������ ���̸� ��� ���� ����

	cin >> n >> m;
	for (int i = 0; i < n; i++) {       // ���� ���� �޾ƿ���
		int x;
		cin >> x;
		h.push_back(x);
	}

	int result = 0;
	int start = 0;       // ���� ��
	int end = *max_element(h.begin(), h.end());       // �� ���� ���� ������ ���� �� ���� 

	while (start <= end) {        // ����Ž������
		long long int total = 0;
		int mid = (start + end) / 2;
		for (int i = 0; i < n; i++) {         // �ʿ��� ������ �� 
			if(h[i] > mid)
				total += h[i] - mid;
		}
		if (total < m)            // �ʿ��� ������ ���̰� ���ٸ� ���ܱ� ���� ���̱�
			end = mid - 1;
		else {                    // ���ų� ���ٸ� ���ܱ� ���� �ø��� ��Ż�� �ּڰ��� �� ���
			result = mid;
			start = mid + 1;
		}
	}
	cout << result << '\n';
}