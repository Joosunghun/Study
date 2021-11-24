// 12_6 ��հ� �� ��ġ
// ��հ� ���� �̿��Ͽ� ���� �������� �ڵ����� ����� �κ� ���� ��ȹ �ùķ��̼�
// 2���� ���� ��հ� ���� �̿��� ������ ��ġ, ��հ� ���� ���̰� 1�� �������� ǥ��
// ����� �ٴ� ���� �ְų� ���� ���� ���κ� ���� �ְų�, �Ǵ� �ٸ� ��� ���� �־�� �Ѵ�.
// ���� ���� ���κ��� ������� �ְų�, �Ǵ� ���� ���κ��� �ٸ� ���� ���ÿ� ����Ǿ� �־�� �Ѵ�.
// �ٴ��� ������ �� �Ʒ� ����
// 2���� ������ n x n ũ�� ���簢 ����, �� ���ڴ� 1 x 1, ó�� ������ ��� �ִ� ����
// ��հ� ���� ���� ���� �������� ��ġ�� �ʰ�, ���� ĭ�� �� ���� ��Ȯ�� ��ġ�ϵ��� ��ġ�� �� �ִ�.
// ������ ũ�� n, ��հ� ���� ��ġ�ϰų� �����ϴ� �۾��� ������� ��� 2���� �迭 build_frame�� �Ű�����
// ��� ��ɾ ������ �� �������� ���¸� return �ϵ��� solution �Լ� ����

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool possible(vector<vector<int>> answer) {                     // ���� ��ġ���� ������ ���������� Ȯ���ϴ� �Լ�
	for (int i = 0; i < answer.size(); i++) {
		int x = answer[i][0];
		int y = answer[i][1];
		int stuff = answer[i][2];
		if (stuff == 0) {                                                        // ��ġ�� ���� '���'�� ���
			bool check = false;
			if (y == 0)                                                           // �ٴ��� ����� ����
				check = true;
			for (int j = 0; j < answer.size(); j++) {                   // ���� ���� �� �κ� �� Ȥ�� �ٸ� ��� ����� ����
				if (x - 1 == answer[j][0] && y == answer[j][1] && 1 == answer[j][2]) {
					check = true;
				}
				if (x == answer[j][0] && y == answer[j][1] && 1 == answer[j][2]) {
					check = true;
				}
				if (x == answer[j][0] && y - 1 == answer[j][1] && 0 == answer[j][2]) {
					check = true;
				}
			}
			if (!check)                                                      // �ƴ϶�� false ��ȯ
				return false;
		}
		else if (stuff == 1) {                                             // ��ġ�� ���� '��'�� ���
			bool check = false;
			bool left = false;
			bool right = false;
			for (int j = 0; j < answer.size(); j++) {               // ���� ���κ��� ��� �� Ȥ�� ���� ���κ��� �ٸ� ���� ���ÿ� �����̶�� ����
				if (x == answer[j][0] && y - 1 == answer[j][1] && 0 == answer[j][2]) {
					check = true;
				}
				if (x + 1== answer[j][0] && y - 1 == answer[j][1] && 0 == answer[j][2]) {
					check = true;
				}
				if (x - 1== answer[j][0] && y == answer[j][1] && 1 == answer[j][2]) {
					left = true;
				}
				if (x + 1== answer[j][0] && y == answer[j][1] && 1 == answer[j][2]) {
					right = true;
				}
			}
			if (left && right)
				check = true;
			if (!check)                                                  //�ƴ϶�� false ��ȯ
				return false; 
		}
	}
	return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
	vector<vector<int>> answer;
	for (int i = 0; i < build_frame.size(); i++) {                               // �۾��� ������ �ִ� 1000��
		int x = build_frame[i][0];
		int y = build_frame[i][1];
		int stuff = build_frame[i][2];
		int operate = build_frame[i][3];
		if (operate == 0) {                                                            // �����ϴ� ���
			int index = 0;                                                              // �ϴ� ������ ��
			for (int j = 0; j < answer.size(); j++) {
				if (x == answer[j][0] && y == answer[j][1] && stuff == answer[j][2]) {
					index = j;
				}
			}
			vector<int> erased = answer[index];
			answer.erase(answer.begin() + index);
			if (!possible(answer)) {                                             // ������ ���������� Ȯ��
				answer.push_back(erased);                                  // ������ �������� �ƴ϶�� �ٽ� ��ġ
			}
		} 
		if (operate == 1) {                                                         // ��ġ�ϴ� ���
			vector<int> inserted;                                                 // �ϴ� ��ġ�� �� �� ��
			inserted.push_back(x);
			inserted.push_back(y);
			inserted.push_back(stuff);
			answer.push_back(inserted);
			if (!possible(answer)) {                                            // ������ ���������� Ȯ��
				answer.pop_back();                                             // ������ �������� �ƴ϶�� �ٽ� ����
			}
		}
	}

	sort(answer.begin(), answer.end());                                 // ���ĵ� ����� ��ȯ
	return answer;
}

