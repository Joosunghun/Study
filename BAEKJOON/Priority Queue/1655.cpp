// ���� 1655�� ����� ���ؿ�
// ������ �ϳ��� ��ĥ �� ���� ���ݱ��� ���� �� �߿��� �߰� ���� ����ϴ� ���α׷�
// ���� ��ģ ������ ¦����� ��� �ִ� �� �� �� ���� ���� ���ؾ� �Ѵ�.

#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	priority_queue<int> maxq;
	priority_queue<int, vector<int>, greater<int>> minq;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		if (maxq.empty())        // ó�� ť�� ����� ���
			maxq.push(x);
		else {
			if (maxq.size() > minq.size())         // �ִ����� ũ�Ⱑ �� ũ�� �ּ� ���� ���� �ִ´�
				minq.push(x);
			else                                             // ũ�Ⱑ ������ �ִ� ���� ���� �ִ´� 
				maxq.push(x);


			if (maxq.top() > minq.top()) {          // �ִ� ���� top���� �ּ� ���� top���� ũ�ٸ� ��ȯ
				int maxtop = maxq.top();
				int mintop = minq.top();
				maxq.pop();
				minq.pop();
				maxq.push(mintop);
				minq.push(maxtop);
			}
		}

	cout << maxq.top() << '\n';
	}


}