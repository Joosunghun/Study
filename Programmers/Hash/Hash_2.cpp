// Hash_2  ��ȭ��ȣ ���

#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;
	
	for (int i = 0; i < phone_book.size(); i++) {                                      // i�� j�� �ٸ���, i�� ���λ翡 j�� ������ false ��ȯ
		for (int j = 0; j < phone_book.size(); j++) {
			if (i != j && phone_book[i].find(phone_book[j]) == 0) {
				answer = false;
				return answer;
			}
		}
	}
	return answer;                                                                          // �׷��� ������ true ��ȯ
}