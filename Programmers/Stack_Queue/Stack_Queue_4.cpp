// Stack_Queue_4 �ֽİ���

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    for (int i = 0; i < prices.size(); i++) {           // vector�� ù ��° �ε��� ���� ���ϸ鼭
    int count = 0;                                           // �ʸ� ���� ���� ī��Ʈ
        for (int j = i + 1; j < prices.size(); j++) {   
            count++;
            if (prices[i] > prices[j])                   // ������ �������� �����ϴ°��� ����
                break;
        }
        answer.push_back(count);                  // �ʸ� answer�� �־���
    }
    return answer;
}