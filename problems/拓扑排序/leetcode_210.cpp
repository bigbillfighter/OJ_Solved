# include <bits/stdc++.h>
using namespace std;

const int max_n = 2e3+5;
int order[max_n];
vector<int> sub_link[max_n];

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int> >& prerequisites) {
        vector<int> ans;
        fill(order, order+numCourses, 0);

        for(int i=0; i<prerequisites.size(); i++){
            int front=prerequisites[i][0], second=prerequisites[i][1];
            sub_link[second].push_back(front);
            order[front] ++;
        }

        queue<int> rst_q;
        for(int i=0; i<numCourses; i++){
            if(!order[i]) rst_q.push(i);
        }


        while(!rst_q.empty()){
            int crt_idx = rst_q.front();
            rst_q.pop();
            ans.push_back(crt_idx);
            for(int i=0; i<sub_link[crt_idx].size(); i++){
                order[sub_link[crt_idx][i]]--;
                if(!order[sub_link[crt_idx][i]]) rst_q.push(sub_link[crt_idx][i]);
            }
        }

        vector<int> null_vector;
        if(ans.size()==numCourses) return ans;
        else return null_vector;
    }   
};


int main(){
    ios::sync_with_stdio(false); cin.tie(0);

    Solution solu;
    int numcourse, relations;
    cin >> numcourse >> relations;

    vector<vector<int> > prerequisites;
    int front, end;
    for(int i=0; i<relations; i++){
        vector<int> re_pair;
        cin >> front >> end;
        re_pair.push_back(front); re_pair.push_back(end);       
        prerequisites.push_back(re_pair);
    }


    vector<int> ans = solu.findOrder(numcourse, prerequisites);
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}