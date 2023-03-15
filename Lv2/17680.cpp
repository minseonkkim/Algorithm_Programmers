#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    // 캐시 크기가 0일 경우
    if(cacheSize == 0){
        answer = cities.size() * 5;
        return answer;
    }
    
    vector<string> cache;
    for(int i = 0; i < cities.size(); i++){
        string check = cities[i];
        transform(check.begin(), check.end(), check.begin(), ::tolower); 
        auto it = find(cache.begin(), cache.end(), check);
        if(it == cache.end()){
            answer += 5;
            if(cache.size() < cacheSize){
                cache.push_back(check);
            } else{
                cache.erase(cache.begin());
                cache.push_back(check);
            }
        } else{
            answer += 1;
            cache.erase(it);
            cache.push_back(check);
        }
    }
    return answer;
}
