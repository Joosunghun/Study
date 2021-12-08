// 문제 1181 단어정렬
// 단어의 개수 N개
//  N개의 줄에 걸쳐 알파벳 소문자로 이루어진 단어가 한줄에 하나씩 출력
// 조건에 따라 단어들을 출력, 길이가 짧은 것부터, 길이가 같으면 사전순으로

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compareWith(string a, string b) {       // 길이가 짧은 것부터 비교하고, 사전순으로 비교하기 위한 함수
    if (a.length() == b.length())
        return a < b;
    return a.length() < b.length();
}

int main() {
    int N;
    vector<string> vec;
    cin >> N;
    for (int i = 0; i < N; i++) {       
        string str;
        cin >> str;
        if (find(vec.begin(), vec.end(), str) == vec.end())
            vec.push_back(str);
    }
    sort(vec.begin(), vec.end(), compareWith);

    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << '\n';
    }
}