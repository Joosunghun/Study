// ���� 1874 ���� ����
// 1���� n������ ���� ���ÿ� �־��ٰ� ���� �þ�������ν� �ϳ��� ������ �����
// ���ÿ� push�ϴ� ������ ���������� ��Ų��
// ������ ������ �־����� �� �� ������ ���� �� �ִ� �� ���� ��, �ִٸ� � ������ push�� pop�� �ؾ��ϴ� �� ����ϴ� ���α׷�

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	stack<int> s;
	vector<char> result;

	int cnt = 1;
	for (int i = 0; i < n; i++) {
		int x;                          
		cin >> x;                     // ���� �־��ֱ�

		while (cnt <= x) {         // cnt �� ���ϴ� ������ �۴ٸ� 
			s.push(cnt);            // cnt�� 1�� ������Ű�鼭 ���ÿ� push
			cnt++;
			result.push_back('+');      // push�� ������ŭ result ���Ϳ� + �ֱ�
		}
		
		if (s.top() == x) {           // ������ ���� ���� ���� x�� ���ٸ�
			s.pop();                   // pop ��Ű��
			result.push_back('-');      // result ���Ϳ� - �ֱ�
		}
		else {                       // �Ѵ� �������� ������ NO ���
			cout << "NO";
			return 0;
		}
	}
	for (int i = 0; i < result.size(); i++) {          // result ��� ���� ���
		cout << result[i] << '\n';
	}
}