// ���� 1305�� ����
// ũ�Ⱑ L�� ������, �ѹ��� L���� ���� ǥ�� ����
// ���̰� N�� ���� ������ �ٿ��� �����Ѵ�.
// �ð��� 1�ʰ� ������ ����, ���ڴ� ��ĭ�� ������ �̵�
// ��� ���� �������� �Ĵٺ��� ��, �� �� �����ִ� ���ڰ� �Է����� �־����� ��, ������ ������ ������ ���� ª�� ���� ����ϴ� ���α׷�

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int L;
string S;

vector<int> getPartialMatch(const string& N) {          // N���� �ڱ� �ڽ��� ã���鼭 ��Ÿ���� �κ� ��ġ�� �̿��� pi[] ���
	int M = N.size();
	vector<int> pi(M, 0);

	int begin = 1;
	int matched = 0;
	while (begin + matched < M) {            // ���� ���ڰ� N���� ������ ������ ã���鼭 �κ� ��ġ�� ��� ���
		if (N[begin + matched] == N[matched]) {
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

int main(void) {
	cin >> L;
	cin >> S;

	vector<int> pi = getPartialMatch(S);

	cout << L - pi[L - 1] << '\n';
	return 0;
}