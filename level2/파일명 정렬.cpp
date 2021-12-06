// level2
// 성공. 문자열, 구현, stable_sort
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<pair<string, string>, string> a, pair<pair<string, string>, string> b){
    string aHead = a.first.first;
    string bHead = b.first.first;
    for(int i=0;i<aHead.size();i++) aHead[i] = toupper(aHead[i]);
    for(int i=0;i<bHead.size();i++) bHead[i] = toupper(bHead[i]);
    int aNumber = stoi(a.first.second);
    int bNumber = stoi(b.first.second);
    if(aHead<bHead) return true;
    else if(aHead==bHead){
        if(aNumber<bNumber) return true;
        else return false;
    }
    else return false;
}

vector<string> solution(vector<string> files) {
    vector<pair<pair<string, string>, string>> v;
    for(int i=0;i<files.size();i++){
        string str = files[i];
        int startIndex=-1, endIndex=-1;
        for(int j=0;j<str.size();j++){
            if(startIndex==-1){
                if('0'<=str[j] && str[j]<='9'){
                    startIndex=j;
                }
            }
            else{
                if(!('0'<=str[j] && str[j]<='9')){
                    endIndex=j-1;
                }
            }
        }
        if(endIndex==-1) endIndex=str.size()-1;
        string head = str.substr(0, startIndex);
        string number;
        if(endIndex-startIndex+1>5){
            number = str.substr(startIndex, 5);
            endIndex = startIndex+4;
        }
        else{
            number = str.substr(startIndex, endIndex-startIndex+1);
        }

        string tail;
        if(endIndex==str.size()-1) tail = "";
        else{
            tail = str.substr(endIndex+1);
        }
        v.push_back({{head,number}, tail});
    }

    stable_sort(v.begin(), v.end(), compare);

    vector<string> answer;
    for(int i=0;i<v.size();i++){
        string filename = v[i].first.first+v[i].first.second+v[i].second;
        answer.push_back(filename);
    }
    return answer;
}