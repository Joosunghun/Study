// Stack_Queue_4 주식가격

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    for (int i = 0; i < prices.size(); i++) {           // vector의 첫 번째 인덱스 부터 비교하면서
    int count = 0;                                           // 초를 세기 위한 카운트
        for (int j = i + 1; j < prices.size(); j++) {   
            count++;
            if (prices[i] > prices[j])                   // 가격이 떨어지면 증가하는것을 멈춤
                break;
        }
        answer.push_back(count);                  // 초를 answer에 넣어줌
    }
    return answer;
}