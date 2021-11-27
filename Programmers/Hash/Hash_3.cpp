// Hash_3 ����

#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;

    map<string, int> m;
    for (auto cloth : clothes) {                      // �� ������ ������ ī��Ʈ 1 ����
        m[cloth[1]] += 1;
    }

    for (auto it = m.begin(); it != m.end(); it++) {         // �� ���� ��ŭ �ݺ��Ͽ� �ʰ��� + 1 �� ����
        answer *= it->second + 1;
    }
    return answer - 1;                                // �������� 1 ����(���� �ϳ��� �����������)
}