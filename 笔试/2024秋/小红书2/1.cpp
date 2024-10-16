#include<bits/stdc++.h>
using namespace std;

const int max_n = 1e6+5;
int total_scores[max_n];
int min_scores[max_n];
int max_scores[max_n];


struct Player{
    int score, id;
};

bool crt_cmp(Player &p1, Player& p2){
    return p1.score > p2.score;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    fill(total_scores, total_scores + m, 0);
    
    string ss;
    for(int i=0; i<n; i++){
        cin >> ss;
        for(int j=0; j<m; j++){
            char c = ss[j];
            if(c >= 'a' && c <= 'z'){
                total_scores[j] +=  26 - c + 'a';

                if(i == 0){
                    max_scores[j] = 26 - c + 'a';
                    min_scores[j] = 26 - c + 'a';
                }else{
                    max_scores[j] = max(max_scores[j], 26 - c + 'a');
                    min_scores[j] = min(min_scores[j], 26 - c + 'a');
                }

            }else{
                total_scores[j] +=  26 - c + 'A';
                if(i == 0){
                    max_scores[j] = 26 - c + 'A';
                    min_scores[j] = 26 - c + 'A';
                }else{
                    max_scores[j] = max(max_scores[j], 26 - c + 'A');
                    min_scores[j] = min(min_scores[j], 26 - c + 'A');
                }
            }
        }
    }


    // for(int i=0; i<m; i++){
    //     cout << total_scores[i] << " ";
    // }
    // cout << endl;

    // for(int i=0; i<m; i++){
    //     cout << max_scores[i] << " ";
    // }
    // cout << endl;

    // for(int i=0; i<m; i++){
    //     cout << min_scores[i] << " ";
    // }
    // cout << endl;

    int mod_nbr;
    vector<Player> players;

    for(int i=0; i<m; i++){
        // mod_nbr = (total_scores[i] - max_scores[i] - min_scores[i]) % (n - 2);
        total_scores[i] = (total_scores[i] - max_scores[i] - min_scores[i]) / (n - 2);
        // if(mod_nbr > 0) total_scores[i] += 1;
        
        Player crt;
        crt.id = i+1; crt.score = total_scores[i];
        players.push_back(crt);
    }

    sort(players.begin(), players.end(), crt_cmp);
    for(int i=0; i<m; i++){
        cout << players[i].id << " ";
    }
    cout << endl;

    for(int i=0; i<m; i++){
        char d = 26  - players[i].score + 'a';
        cout << d << " ";
    }
    cout << endl;   
    

    return 0;
}