// Hash_1 �������� ���� ����

#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {

    string answer;

    sort(participant.begin(), participant.end());          // �����ڵ��� �̸������� ����
    sort(completion.begin(), completion.end());         // ������ �������� �̸� ������ ����

    for (int i = 0; i < participant.size(); i++) {              // �����ڿ� ������ �������� �̸��� �ٸ���
        if (participant[i] != completion[i]) {
            answer = participant[i];
            return answer;                                          // �� ���� ������ �̸��� ��ȯ
        }
    }
}