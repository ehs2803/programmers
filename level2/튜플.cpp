// level2
// 성공. 구현 - 문자열
#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;

bool check[100001];

bool compare(vector<int> &a, vector<int> &b){
    if(a.size()<b.size()) return true;
    else return false;
}

vector<int> solution(string s) {
    s.erase(0,1);
    s.erase(s.size()-1,1);

    vector<vector<int> > v;
    int index_start=0;
    while(1){
        int openIndex = s.find('{',index_start);
        int closeIndex = s.find('}',index_start);
        if(openIndex==-1) break;

        string str = s.substr(openIndex+1,closeIndex-openIndex-1);
        //cout<<str<<endl;
        int index_com = 0;
        vector<int> temp;
        while(1){
            int comindex = str.find(',',index_com);
            if(comindex==-1){
                temp.push_back(stoi(str.substr(index_com)));
                break;
            }
            temp.push_back(stoi(str.substr(index_com,comindex-index_com)));
            index_com = comindex+1;
        }
        //for(int i=0;i<temp.size();i++){cout<<temp[i]<<' ';}
        //cout<<endl;
        v.push_back(temp);

        index_start = closeIndex+1;
    }

    sort(v.begin(), v.end(), compare);

    //for(int i=0;i<v.size();i++) cout<<v[i].size()<<' ';

    vector<int> answer;
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            if(check[v[i][j]]== false){
                answer.push_back(v[i][j]);
                check[v[i][j]]= true;
                break;
            }
        }
    }

    return answer;
}
/*
#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;

vector<int> solution(string s) {
    s.erase(0,1);
    s.erase(s.size()-1,1);
    int index=0;
    vector<string> strVector;
    while(1){
        index=s.find(',',0);
        if(index==-1) break;
        strVector.push_back(s.substr(0,index));
        s.replace(0,index,"");
    }

    vector<int> v;
    return v;
}
 */
