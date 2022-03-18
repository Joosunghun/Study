// ���� 1786�� ã��
// �������μ��� ���� ����ϴ� ���߿� ã�� ����� �̿��� �� ���� ���� ���̴�. �̸� ���� �����غ���
// �� ���� ���ڿ� P�� T�� ����, ���ڿ� P�� ���ڿ� T �߰��� �� ��, ��� ��ġ���� ��Ÿ������ �˾Ƴ��� ������ '���ڿ� ��Ī'�̶�� �Ѵ�.
// T�� i�� ���ڿ��� �����ϴ� ��Ī�� �˻��ϴ��� T[i+j-1] != P[j]���� �߰��ߴٰ�����, �̷��� P�� j�� ���ڿ��� ��Ī�� ������ ���, T�� i+j-1 ��° ���ڿ� P�� K+1�� ���ں��� �񱳸� ����� ������ȴ�.
// �� �ִ��� K�� j�� ���� �Լ���� �����ϰ�, 1~m������ �� j���� ���� �ִ��� k�� �̸� ����� ������ ���� ���̴�. �̸� ��ó�� �����̶�� �θ���, O(m)�� �Ϸ��� �� �ִ�.
// �̸� �̿��Ͽ�, T�� P�� �־����� ��, ���ڿ� ��Ī ������ �ذ��ϴ� ���α׷�

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> Fail(string pattern) {
	int m = pattern.length();
	vector<int> pi(m);

	int begin = 1;
	int matched = 0;
	pi[0] = 0;
	while (begin + matched < m) {
		if (pattern[begin + matched] == pattern[matched]) {
			matched++;
			pi[begin + matched - 1] = matched;
		}
		else {
			if (matched == 0)
				begin++;
			else {
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return pi;
}

vector<int> KMP(string pattern, string text) {
	int m = pattern.length();
	int n = text.length();
	vector<int> pos;
	vector<int> pi = Fail(pattern);

	int begin = 0;
	int matched = 0;
	while (begin + m <= n) {
		if (matched < m && text[begin + matched] == pattern[matched]) {
			matched++;

			if (matched == m)
				pos.push_back(begin + 1);
		}
		else {
			if (matched == 0)
				begin++;
			else {
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return pos;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string text;
	getline(cin, text);
	string pattern;
	getline(cin, pattern);

	vector<int> ans = KMP(pattern, text);
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << ' ';
	}
}