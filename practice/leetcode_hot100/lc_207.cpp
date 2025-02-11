#include<bits/stdc++.h>
using namespace std;

struct Node{
    int degree;
    vector<int> after_course;
    Node(){
        degree=0;
    }
};

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, Node> node_map; 

        for(int i=0; i<prerequisites.size(); i++){
            if(!node_map.count(prerequisites[i][0])){
                Node crt_node;
                crt_node.after_course.push_back(prerequisites[i][1]);
                node_map[prerequisites[i][0]] = crt_node;
            }else{
                node_map[prerequisites[i][0]].after_course.push_back(prerequisites[i][1]);
            }
            if(!node_map.count(prerequisites[i][1])){
                Node crt_node_2;
                crt_node_2.degree = 1;
                node_map[prerequisites[i][1]] = crt_node_2;
            }else{
                node_map[prerequisites[i][1]].degree ++;
            }
        }

        queue<int> idxes;
        for(map<int, Node>::iterator p = node_map.begin(); p!=node_map.end(); p++){
            if((p->second).degree == 0) idxes.push(p->first);
        }
        int crt_idx;
        while(!idxes.empty()){
            crt_idx = idxes.front();
            idxes.pop();
            for(int i=0; i<node_map[crt_idx].after_course.size(); i++){
                if(node_map[node_map[crt_idx].after_course[i]].degree > 0){
                    node_map[node_map[crt_idx].after_course[i]].degree --;
                    if(node_map[node_map[crt_idx].after_course[i]].degree == 0){
                        idxes.push(node_map[crt_idx].after_course[i]);
                    }
                }
            }
        }
        for(map<int, Node>::iterator p = node_map.begin(); p!=node_map.end(); p++){
            if((p->second).degree != 0) return false;
        }
        return true;
    }
};