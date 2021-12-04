// ���� 4949 ������������
// "("�� ")"�͸� ¦�� �̷��, "["�� "]" �͸� ¦�� �̷��
// ���ڿ��� �־����� �� �������� ���ڿ����� �ƴ��� �Ǵ�

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void) {
	string s;
	while (1) {
		getline(cin, s);                   // ���ڿ��� ���پ� �޾ƿ�

		if (s == ".")                        // ���ڿ��� . �̸� ����
			break;

		stack<char> st;                 // ��ȣ�� ��� ���� ����
		bool flag = 0;                     // ���� ���� ������
		for (int i = 0; i < s.size(); i++) {         // ���ڿ� ���� ��ŭ �ݺ�
			if (s[i] == '(' || s[i] == '[')          // ���� ��ȣ�� 
				st.push(s[i]);                        // ���ÿ� push
			else if (s[i] == ')') {                    // �ݴ� �Ұ�ȣ �϶�
				if (!st.empty() && st.top() == '(')       // ������ �����ʰ�, top�� ���� �Ұ�ȣ�̸�
					st.pop();                             // pop
				else {                                   
					flag = 1;
					break;                               
				}
			}
			else if (s[i] == ']') {                    // �ݴ� ���ȣ �϶�
				if (!st.empty() && st.top() == '[')       // ������ �����ʰ�, top�� ���� ���ȣ�̸�
					st.pop();                             // pop
				else {
					flag = 1;
					break;
				}
			}
		}
		if (flag == 0 && st.empty())          
			cout << "yes" << '\n';
		else
			cout << "no" << '\n';
	}
}
