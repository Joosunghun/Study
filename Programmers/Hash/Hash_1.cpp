// Hash_1 완주하지 못한 선수

#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {

    string answer;

    sort(participant.begin(), participant.end());          // 참가자들을 이름순으로 정렬
    sort(completion.begin(), completion.end());         // 완주한 선수들을 이름 순으로 정렬

    for (int i = 0; i < participant.size(); i++) {              // 참가자와 완주한 선수들의 이름이 다를때
        if (participant[i] != completion[i]) {
            answer = participant[i];
            return answer;                                          // 그 때의 참가자 이름을 반환
        }
    }
}