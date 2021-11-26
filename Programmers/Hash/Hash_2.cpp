// Hash_2  전화번호 목록

#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;
	
	for (int i = 0; i < phone_book.size(); i++) {                                      // i와 j가 다르고, i의 접두사에 j가 있으면 false 반환
		for (int j = 0; j < phone_book.size(); j++) {
			if (i != j && phone_book[i].find(phone_book[j]) == 0) {
				answer = false;
				return answer;
			}
		}
	}
	return answer;                                                                          // 그렇지 않으면 true 반환
}