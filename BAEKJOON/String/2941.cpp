// ���� 2941�� ũ�ξ�Ƽ�� ���ĺ�
// �ܾ �־����� ��, ��� ũ�ξ�Ƽ�� ���ĺ����� �̷���� �ִ��� ����ϴ� ���α׷�

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string s;
vector<string> arr = { "c=", "c-", "dz=","d-", "lj", "nj", "s=", "z=" };
int cnt = 0;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> s;

	for (int i = 0; i < arr.size(); i++) {       // ũ�ξ�Ƽ�� ���� ã��
		while (1) {
			int idx = s.find(arr[i]);          
			if (idx == string::npos)             // ũ�ξ�Ƽ�� ���ڿ��� ������ break
				break;

			s.replace(idx, arr[i].length(), "*");          // ũ�ξ�Ƽ�� ���ڿ��� �ѱ��� �� *�� ����
		}
	}
	cnt = s.length();
	cout << cnt << '\n';
}