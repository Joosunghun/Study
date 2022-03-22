// ���� 14725�� ���̱�
// ù ��° ���� �κ� ���̰� �� ���� ���� �������鼭 �˰� �� ������ ���� ���� N���� �־�����.
// �� ��° �ٺ��� n+1 ��° �ٱ���, �� ���� ������ �κ� ���� �Ѹ����� ������ ���� ���� ���� K�� �־�����.
// K���� �Է��� �κ� ���̰� ���ʺ��� ������� �� ������ ������ �濡 �ִ� ���� �����̸� ���� �̸��̴�.
//  ���̱��� �ð�ȭ�� ������ ����ϴ� ���α׷�

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n, k;
vector<string> arr[1001];

int main(void) {
	cin >> n;
	string temp;

	for (int i = 0; i < n; i++) {
		cin >> k;
		for (int j = 0; j < k; j++) {
			cin >> temp;
			arr[i].push_back(temp);
		}
	}

	sort(arr, arr + n);

	vector<string> stack;

	for (int i = 0; i < n; i++) {
		int count = 0;
		for (int j = 0; j < arr[i].size() && j < stack.size(); j++) {
			if (arr[i][j] == stack[j])
				count++;
			else
				break;
		}
		int size = stack.size();
		for (int j = count; j < size; j++)
			stack.pop_back();

		for (int j = count; j < arr[i].size(); j++) {
			for (int k = 0; k < stack.size(); k++)
				cout << "--";
			cout << arr[i][j] << '\n';
			stack.push_back(arr[i][j]);
		}
	}

	return 0;
}