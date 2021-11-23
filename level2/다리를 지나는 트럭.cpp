// level2
// 성공. 구현
#include <vector>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int second=0;
    int totalweight = 0;
    int index_truck = 0;
    vector<pair<int,int> > bridge; // second,weight

    while(true){
        second++;
        if(index_truck<truck_weights.size() && totalweight+truck_weights[index_truck]<=weight){
            totalweight += truck_weights[index_truck];
            bridge.push_back({bridge_length,truck_weights[index_truck]});
            index_truck++;
        }
        for(int i=0;i<bridge.size();i++){
            bridge[i].first-=1;
        }
        if(bridge[0].first==0) {
            totalweight -= bridge[0].second;
            bridge.erase(bridge.begin());
        }
        if(bridge.empty() && index_truck==truck_weights.size()) break;
    }

    return second+1;
}

/*
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int index_truck=0;
    queue<pair<int,int>> bridge_truck;

    int cweight=0;
    while(true){
        if(index_truck==truck_weights.size() && bridge_truck.empty()){
            break;
        }
        if(index_truck<truck_weights.size() && cweight<=weight){
            bridge_truck.push({truck_weights[index_truck],1});
            cweight+=truck_weights[index_truck];
        }

        answer++;
    }
    return answer;
}
*/
/*
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int index=0;
    int sum=0;
    queue<pair<int,int>> bridge_truck;
    while(1){
        if(bridge_truck.size()>0){
            for(int i=0;i<bridge_truck.size();i++) bridge_truck[i].second++;
            if(bridge_truck[0].second==bridge_length) {
                bridge_truck.pop();
                index++;
                if(index==truck_weights.size()) break;
            }
        }
        if(sum+truck_weights[index]<=weight){
            bridge_truck.push_back(make_pair(truck_weights[index], 0));
        }
        answer++;

    }
    return answer;
}
*/
