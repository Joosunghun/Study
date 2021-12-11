// ���� 1931 ȸ�ǽ� ����
// �Ѱ��� ȸ�ǽ��� �ִµ� �̸� ����ϰ��� �ϴ� N���� ȸ�ǿ� ���Ͽ� ȸ�ǽ� ���ǥ�� �����.
// �� ȸ�ǿ� ���� ���۽ð��� �����½ð��� �־����ְ�, ȸ�ǰ� ��ġ�� �ʰ� �ϸ鼭 ����� �� �ִ� ȸ���� �ִ� ����
// �� ȸ�ǰ� ������ �Ͱ� ���ÿ� ����ȸ�ǰ� ���� ����
// ȸ���� ���۽ð��� ������ �ð��� ������, �������ڸ��� �P���� ������ ����

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int n;
	vector<pair<int, int>> time;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		time.push_back(make_pair(y, x));             // ȸ�ǰ� ������ �Ͱ� �����ϴ� ������ vector�� �־���
	}

	sort(time.begin(), time.end());        // ȸ�ǰ� ���� ������ ������� ����
	int run_time = 0;                            // ȸ�� �ð�
	int count = 0;                                // ����
	for (int i = 0; i < time.size(); i++) {
		if (run_time <= time[i].second) {         // ȸ�ǽð��� ���۽ð����� ������ 
			run_time = time[i].first;                   // ȸ�ǽð��� ������ �ð��� �ְ�
			count++;                                      // ȸ�� ���� �� �� ����
		}
	}
	cout << count << '\n';
}