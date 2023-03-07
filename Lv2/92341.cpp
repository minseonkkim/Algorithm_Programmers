#include <string>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    map<int, int> inCar;
    map<int, int> outCar;
    for(int i = 0; i < records.size(); i++){
        int time = stoi(records[i].substr(0, 3)) * 60 + stoi(records[i].substr(3, 5));
        int carNum = stoi(records[i].substr(6, 10));
        string inOrOut = records[i].substr(11, 13);
        
        if(inOrOut == "IN"){
            inCar[carNum] = time;
        } else if(inOrOut == "OUT"){
            outCar[carNum] += time - inCar[carNum];
            inCar.erase(carNum);
        }
    }
    
    for (auto iter = inCar.begin() ; iter != inCar.end(); iter++){
        outCar[iter->first] += 1439 - iter->second;
    }
    
    for(auto iter = outCar.begin() ; iter != outCar.end(); iter++){
        if(iter->second <= fees[0]){
            answer.push_back(fees[1]);
        } else{
            answer.push_back(fees[1] + ceil((double)(iter->second -  fees[0]) / fees[2]) * fees[3]);
        }
    }
    
    return answer;
}
