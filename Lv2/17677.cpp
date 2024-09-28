#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// 영문자 아닌 글자 들어있는 글자 쌍 제거
bool isEng(string s){
    return isalpha(s[0]) && isalpha(s[1]);
}

// 대문자 -> 소문자
string normalization(string s){
    s[0] = tolower(s[0]);
    s[1] = tolower(s[1]);
    return s;
}

int solution(string str1, string str2) {
    int answer = 0;
    
    // 두 글자씩 끊기
    vector<string> v1;
    vector<string> v2;
    for(int i = 0; i < str1.length() - 1; i++){
        string s = str1.substr(i, 2);
        if(isEng(s)) {
            v1.push_back(normalization(s));
        }
    }
    for(int i = 0; i < str2.length() - 1; i++){
        string s = str2.substr(i, 2);
        if(isEng(s)) {
            v2.push_back(normalization(s));
        }
    }
    
    if(v1.size() == 0 && v2.size() == 0) return 65536;
    
    // 교집합, 합집합 구하기
    int intersection_size = 0, union_size = 0;
    unordered_map<string, int> um1;
    unordered_map<string, int> um2;
    for(int i = 0; i < v1.size(); i++) um1[v1[i]]++;
    for(int i = 0; i < v2.size(); i++) um2[v2[i]]++;
    
    for(auto &elem: um1){
        string key = elem.first;
        if(um2.find(key) != um2.end()){
            intersection_size += min(um1[key], um2[key]);
        }
        union_size += max(um1[key], um2[key]);
    }
    for(auto &elem: um2){
        string key = elem.first;
        if(um1.find(key) == um1.end()){
            union_size += um2[key];
        }
    }
    
    // 자카드 유사도 구하기
    double jaccard_similarity = (double)intersection_size / union_size;
    answer = (int)(jaccard_similarity * 65536);

    return answer;
}
