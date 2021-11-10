// 6_4 �� �迭�� ���� ��ü
// �� �迭�� N�� �� ���ҷ� ���� �Ǿ� �ְ� K�� �ٲ�ġ�� ���� ���� ����
// �ٲ�ġ�Ⱑ ������ �� �迭 A�� ��� ���� ���� �ִ��� �ǵ��� ���α׷� �ۼ�

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, k;
vector<int> a;
vector<int> b;

bool compare(int x, int y) {                                   // ���� ������ ���� ����
	return x > y;
}

int main() {
	cin >> n >> k;                                                 // n, k �Է¹ޱ�

	for (int i = 0; i < n; i++) {                                   // �迭 A�� ��� ���� �Է¹ޱ�
		int x;
		cin >> x;
		a.push_back(x);
	}

	for (int i = 0; i < n; i++) {                                    // �迭 B�� ��� ���� �Է¹ޱ�
		int x;
		cin >> x;
		b.push_back(x);
	}

	sort(a.begin(), a.end());                                    // A �������� ����
	sort(b.begin(), b.end(), compare);                      // B �������� ����

	for (int i = 0; i < k; i++) {                                     // ù ��° �ε��� ���� Ȯ���ϸ�, �� �迭�� ���Ҹ� K�� ���� ��
		if (a[i] < b[i])                                               // A�� ���Ұ� B ���Һ��� �������
			swap(a[i], b[i]);                                       // �� ���Ҹ� ��ü
		else break;                                                    // ũ�ų� ������ �ݺ��� Ż��
	}

	int result = 0;
	for (int i = 0; i < n; i++) {                                       // �迭 A�� ��� ������ ���� ���
		result += a[i];
	}

	cout << result << endl;
}