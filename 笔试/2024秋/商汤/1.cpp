#include<bits/stdc++.h>
using namespace std;

struct STU{
    int id, chinese, math, english, total;
};

const int max_n = 1e5+5;
STU stus[max_n];

bool crt_cmp(const STU& a, const STU& b){
    return a.total < b.total;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    int min_chinese = 100, min_math = 100, min_english = 100;
    int cur_chinese, cur_math, cur_english;
    for(int i=0; i<n; i++){
        cin >> cur_chinese >> cur_math >> cur_english;
        stus[i].id = i;
        stus[i].chinese = cur_chinese;
        stus[i].math = cur_math;
        stus[i].english = cur_english;
        stus[i].total = (cur_chinese + cur_math + cur_english);
    }

    sort(stus, stus+n, crt_cmp);
    // for(int i=0; i<n; i++){
    //     cout << stus[i].id << " " << stus[i].total << ", ";
    // }
    // cout << endl;

    if(n == 1){
        cout << 0 << endl;
    }else{
        int rst = 0;
        min_chinese = stus[n-1].chinese;
        min_math = stus[n-1].math;
        min_english = stus[n-1].english;

        int same_min_chinese = min_chinese;
        int same_min_math = min_math;
        int same_min_english = min_english;

        for(int i=n-2; i>=0; i--){
            if(stus[i].total < stus[i+1].total){
                if((stus[i].english > min_english) || (stus[i].math > min_math) || (stus[i].chinese > min_chinese)){
                    rst ++;
                }
                min_chinese = min(min_chinese, stus[i].chinese);
                min_math = min(min_math, stus[i].math);
                min_english = min(min_english, stus[i].english);
                
                same_min_chinese = min_chinese;
                same_min_math = min_math;
                same_min_english = min_english;

            }else{
                if((stus[i].english > same_min_english) || (stus[i].math > same_min_math) || (stus[i].chinese > same_min_chinese)){
                    rst ++;
                }
                min_chinese = min(min_chinese, stus[i].chinese);
                min_math = min(min_math, stus[i].math);
                min_english = min(min_english, stus[i].english);
            }

        }
        cout << rst << endl;
    }

    return 0;
}