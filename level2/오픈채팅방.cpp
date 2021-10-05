#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> solution(vector<string> record) {
    map<string, string> m;
    vector<string> answer;
    for(int i=0;i<record.size();i++){
        int index = record[i].find(' ');
        int preindex;

        string cmd = record[i].substr(0, index);

        preindex = index;
        index = record[i].find(' ', preindex+1);

        string id = record[i].substr(preindex+1, index-preindex-1);

        if(cmd=="Leave") {
            string str=id+"님이 나갔습니다.";
            answer.push_back(str);
            continue;
        }
        preindex = index;
        string name = record[i].substr(preindex+1);

        if(cmd=="Enter"){
            if(m.find(id)!=m.end()){
                m[id]=name;
                string str=id+"님이 들어왔습니다.";
                answer.push_back(str);
            }
            else{
                m.insert({id, name});
                string str=id+"님이 들어왔습니다.";
                answer.push_back(str);
            }
        }
        else if(cmd=="Change"){
            m[id]=name;
        }

    }

    for(int i=0;i<answer.size();i++){
        string str = answer[i];
        int index = str.find("님");
        string id = str.substr(0, index);
        str = str.substr(index);
        str = m[id] + str;
        answer[i]=str;
    }
    return answer;
}
