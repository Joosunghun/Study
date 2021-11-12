// ���� 10989�� �� �����ϱ� 3
// N ���� ���� �־����� ��, ���� �������� �����ϴ� ���α׷�

#include <iostream>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);                        // ���α׷��� ����� �ӵ��� ������Ű�� ���� �ڵ�
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int arr[10001] = { 0, };                                 // �� ũ�Ⱑ 10000�̹Ƿ� ����� ���ÿ� 0 ���� �ʱ�ȭ
	cin >> n;
	for (int i = 0; i < n; i++) {                              // ��� ���� �Է¹ޱ�
		int x;
		cin >> x;
		arr[x]++;
	}

	for (int i = 1; i < 10001; i++) {                        // �迭�� ��ü�� ��ȸ�ϴµ� 0�� ���� ���ܽ�Ű�� �迭�� ��� ����ŭ �ε��� ���� ���
		if (arr[i]) {
			for (int j = 0; j < arr[i]; j++) {
				cout << i << '\n';
			}
		}
	}
	return 0;
}