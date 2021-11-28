// Hash_4 베스트 앨범

#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {                           // 이차원 배열에서 첫번째 원소를 기준으로 내림차순하기 위한 함수
    return a.first > b.first;
}

bool compare_map_value(pair<string, int> a, pair<string, int> b) {      // 이차원 배열에서 두번째 원소를 기준으로 내림차순하기 위한 함수
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, vector<pair<int, int>>> genre_playlist;                 // 장르, vector(재생횟수, 노래 고유번호(인덱스) 값)
    map<string, int> genre_play_cnt;                                         // 장르, 총 재생횟수
    vector<pair<string, int>> genre_play_cnt_v;                          // genre_play_cnt를 value로 정렬하기 위한 vector

    for (int i = 0; i < genres.size(); i++) {                                   // hash map에 데이터 삽입
        genre_playlist[genres[i]].push_back(make_pair(plays[i], i));
        genre_play_cnt[genres[i]] += plays[i];
    }

    for (auto& k : genre_playlist) {                                             // 장르별 재생음악들 빈도수를 내림 차순으로 정렬
        sort(k.second.begin(), k.second.end(), compare);
    }

    genre_play_cnt_v.assign(genre_play_cnt.begin(), genre_play_cnt.end());               // assign(원소의 개수, 값) -> 특정 원소로 채운다(이전 데이터는 저장 x)
    sort(genre_play_cnt_v.begin(), genre_play_cnt_v.end(), compare_map_value);        // 장르별 총 재생횟수를 내림 차순으로 정렬

    for (int i = 0; i < genre_play_cnt_v.size(); i++) {                              
        string genre_name = genre_play_cnt_v[i].first;                               
        for (int j = 0; (j < genre_playlist[genre_name].size()) && (j < 2); j++) {               // 음악이 1개면 1개만, 2개이상이면 2개까지만 answer에 저장
            answer.push_back(genre_playlist[genre_name][j].second);
        }
    }
    return answer;
}