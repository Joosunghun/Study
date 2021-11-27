// Hash_3 위장

#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;

    map<string, int> m;
    for (auto cloth : clothes) {                      // 옷 종류가 같으면 카운트 1 증가
        m[cloth[1]] += 1;
    }

    for (auto it = m.begin(); it != m.end(); it++) {         // 옷 종류 만큼 반복하여 옷개수 + 1 을 곱함
        answer *= it->second + 1;
    }
    return answer - 1;                                // 마지막에 1 감소(옷을 하나도 입지않은경우)
}