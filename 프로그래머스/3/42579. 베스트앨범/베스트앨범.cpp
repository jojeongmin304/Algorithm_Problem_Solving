#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool gencmp(pair<string, int>& a, pair<string, int>& b) {
    return a.second > b.second;
}

bool songcmp(pair<int, int>& a, pair<int, int>& b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, int> genres_dict;
    unordered_map<string, vector<pair<int, int>>> songs_dict;
    
    for (int i = 0; i < genres.size(); i++) {
        genres_dict[genres[i]] += plays[i];
        songs_dict[genres[i]].push_back({i, plays[i]});
    }
    
    vector<pair<string, int>> sorted_genres(genres_dict.begin(), genres_dict.end());
    
    sort(sorted_genres.begin(), sorted_genres.end(), gencmp);
    
    for (auto& pair : sorted_genres) {
        auto& songs = songs_dict[pair.first];
        sort(songs.begin(), songs.end(), songcmp);
        for (int i = 0; i < min(2, (int)songs.size()); i++)
            answer.push_back(songs[i].first);
    }
    
    return answer;
}