// level2
// 성공. 구현, string, map
#include <string>
#include <vector>
#include<iostream>
#include<map>
#include<cmath>
using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    map<string, string> temp;
    map<string, int> m;
    
    for(int i=0;i<records.size();i++){
        int firstindex = records[i].find(' ');
        int twoindex = records[i].find(' ', firstindex+1);
        //cout<<firstindex<<' '<<twoindex<<endl;
        
        string time = records[i].substr(0, firstindex);
        string num = records[i].substr(firstindex+1, twoindex-firstindex-1);
        string op = records[i].substr(twoindex+1);
        
        //cout<<time<< ' '<<num<<' '<<op<<endl;
        auto iter = temp.find(num);
        if(iter!=temp.end()){
            //find
            string mtime = temp[num];
            
            int index = time.find(':');
            int hour = stoi(time.substr(0, index));
            int min = stoi(time.substr(index+1));
            
            int mindex = mtime.find(':');
            int mhour = stoi(mtime.substr(0, mindex));
            int mmin = stoi(mtime.substr(mindex+1));
            
            int cost = 0;
            cost += 60*(hour-mhour);
            if(min-mmin>=0){
                cost+=(min-mmin);
            }
            else{
                cost -= 60;
                cost += (min+(60-mmin));
            }
            temp.erase(num);
            if(m.find(num)!=m.end()){
                //find
                m[num]+=cost;
            }
            else{
                m.insert({num,cost});
            }
            
        }
        else{
            temp.insert({num, time});
        }
    }
    if(temp.size()>0){
        for(auto iter : temp){
            string num = iter.first;
            string time = iter.second;
            int index = time.find(':');
            int hour = stoi(time.substr(0, index));
            int min = stoi(time.substr(index+1));
            
            int cost=0;
            cost += 60*(23-hour);
            cost += (59-min);
            m[num]+=cost;
            temp.erase(num);
        }
    }
    
    vector<int> answer;
    
    for (auto iter : m) { 
        //cout << iter.first << " " << iter.second << endl; 
        if(fees[0]>=iter.second) answer.push_back(fees[1]);
        else{
            int cost = fees[1];
            double temp = (iter.second-fees[0])/double(fees[2]);
            cout<<ceil(temp)<<endl;
            cost += (ceil(temp))*fees[3];
            answer.push_back(cost);
        }
    }

    return answer;
}