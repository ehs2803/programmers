#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool cmp1(const pair<string,int>& a, const pair<string,int>& b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second > b.second;
}

bool cmp2(const pair<int,int>& a, const pair<int,int>& b){
    if(a.first==b.first) return a.second<b.second;
    return a.first>b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    map<string, int> m;
    for(int i=0;i<genres.size();i++){
        if(m.find(genres[i])!=m.end()){
            // find
            m[genres[i]]+=plays[i];
        }
        else{
            // not find
            m[genres[i]] = plays[i]; 
            //m.insert({geners[i], plays[i]});
        }
    }
    
    vector<pair<string,int>> v( m.begin(), m.end() );
    sort(v.begin(), v.end(), cmp1);
    
    vector<int> answer;
    for(int i=0;i<v.size();i++){
        vector<pair<int,int>> temp;
        for(int j=0;j<plays.size();j++){
            if(genres[j]==v[i].first){
                temp.push_back({plays[j], j}); // time index
            }
        }
        sort(temp.begin(), temp.end(), cmp2);
        answer.push_back(temp[0].second);
        if(temp.size()>1) answer.push_back(temp[1].second); // 항상 두개 이상의 노래가 아닐 수 있음.
    }

    return answer;
}
//20220101
//hash