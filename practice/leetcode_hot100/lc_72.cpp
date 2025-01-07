#include <bits/stdc++.h>
using namespace std;

const int max_n = 505;
int dist[max_n][max_n];

class Solution {
public:
    int minDistance(string word1, string word2) {
        int len_1 = word1.size(), len_2 = word2.size();
        if(len_1 == 0 || len_2 == 0) return len_1 + len_2;
        for(int i=0; i<=len_1; i++) for(int j=0; j<=len_2; j++) dist[i][j] = 0;
        for(int i=0; i<=len_1; i++) dist[i][0] = i;
        for(int j=0; j<=len_2; j++) dist[0][j] = j;
        int add_a, add_b, mod_a;
        for(int i=1; i<=len_1; i++){
            for(int j=1; j<=len_2; j++){
                if(word1[i-1] == word2[j-1]) mod_a = dist[i-1][j-1];
                else mod_a = dist[i-1][j-1] + 1;
                add_a = dist[i-1][j] + 1;
                add_b = dist[i][j-1] + 1;
                dist[i][j] = min(min(add_a, add_b), mod_a);
            }
        }
        return dist[len_1][len_2];
    }
};