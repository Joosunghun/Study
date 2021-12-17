// ���� 17298�� ��ū��
// ũ�Ⱑ N�� ������ �ִ�. ������ �� ���� Ai�� ���ؼ� ��ū�� NGE(i)�� ���Ϸ��� �Ѵ�.
// Ai�� ��ū���� �����ʿ� �����鼭 ai���� ū �� �߿��� ���� ���ʿ� �ִ� ���� ��ū�� ��� �Ѵ�.
// ��ū���� ���� ���� -1 �̴�.

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	vector<int> v;          // ������ �Է¹��� ����
	stack<int> s;           // v[i]�� ���� �ε���

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	
	vector<int> ans(v.size(), -1);               // �⺻�� -1�� �ְ� �� ������ ���� ��ū�� ���� ���� vector

	for (int i = 0; i < v.size(); i++) {            
		while (!s.empty() && v[s.top()] < v[i]) {         // ������ �����ʰ�, top���� ���� �������� ������
			ans[s.top()] = v[i];                                  // ans�� v[i] ���� �ְ�
			s.pop();                                                  // pop
		}
		s.push(i);                                                   // �׷��� ������ i�� push
	}   
	for (int i = 0; i < n; i++) {                                   // ans�� ��� �� ���
		cout << ans[i] << ' ';
	}
}