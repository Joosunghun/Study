// ���� 2562�� �ִ�
// 9���� ���� �ٸ� �ڿ����� �־��� ��, �̵� �� �ִ��� ã�� �� �ִ��� �� ��° �������� ���ϴ� ���α׷�

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int max = 0, cnt = 0;
	vector<int> arr;

	for (int i = 0; i < 9; i++) {            // ���Ϳ� ���� �ֱ�
		int x;
		cin >> x;
		arr.push_back(x);
	}

	for (int i = 0; i < arr.size(); i++) {        
		if (arr[i] > max) {                // ���� ���� max ������ ũ�� max�� ���� �� ��, ���� ��ġ ����
			max = arr[i];
			cnt = i;
		}
	}

	cout << max << '\n';
	cout << cnt + 1 << '\n';        // �ε����� 0���� �����ϱ� ������ 1 ������
}