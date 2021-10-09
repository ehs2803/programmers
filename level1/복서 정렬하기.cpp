#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct info{
    int num;
    double rate;
    int weight;
    int win=0;
};

bool cmp(const struct info &a, const struct info &b){
    if(a.rate>b.rate) return true;
    else if(a.rate==b.rate){
        if(a.win>b.win) return true;
        else if(a.win==b.win){
            if(a.weight>b.weight) return true;
            else if(a.weight==b.weight){
                if(a.num<b.num) return true;
                else return false;
            }
            else return false;
        }
        else return false;
    }
    else{
        return false;
    }
}

vector<int> solution(vector<int> weights, vector<string> head2head) {
    int size = weights.size();
    struct info *infos = new info[size];

    for(int i=0;i<size;i++){
        int WinCnt=0;
        int LCnt=0;
        for(int j=0;j<size;j++){
            if(i!=j && head2head[i][j]=='W') {
                WinCnt++;
                if(weights[i]<weights[j]) infos[i].win+=1;
            }
            if(i!=j && head2head[i][j]=='L') LCnt++;
        }
        //cout<<WinCnt<<endl; pass
        double temp = WinCnt;
        double rate;
        if(WinCnt+LCnt==0) rate = 0;
        else rate = (temp/(WinCnt+LCnt))*100.0;
        infos[i].rate = rate;
        infos[i].weight = weights[i];
        infos[i].num = i;
    }

    sort(infos, infos+size, cmp);
    /*
    for(int i=0;i<size;i++){
        cout<<infos[i].num<<' '<<infos[i].rate<<' '<<infos[i].weight<<' '<<infos[i].win<<endl;
    }
    */
    vector<int> answer;
    for(int i=0;i<size;i++){
        answer.push_back(infos[i].num+1);
    }
    return answer;
}
