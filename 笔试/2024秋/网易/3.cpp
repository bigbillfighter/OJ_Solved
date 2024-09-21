#include<bits/stdc++.h>
using namespace std;

const int max_n = 1e4+5;
int a[max_n], b[max_n];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    int n, m;

    int first, second;
    int all_nbr;
    int f_sum, s_sum;
    int f_last, s_last;

    while(T--){
        cin >> n >> m;
        all_nbr = n + m + 1;
        for(int i=0; i < all_nbr; i++){
            cin >> a[i];
        }
        for(int i=0; i < all_nbr; i++){
            cin >> b[i];
        }

        first = 0; second = 0;
        f_sum = 0; s_sum = 0;
        vector<int> output;
        int idx = 0;
        int type = 0;
        int idx_f, idx_s;
        int flag = true;

        for(int i=0; i < all_nbr; i++){
            if(first > n && second == m){
                s_last = b[i];
            }
            if(second > m && first == n){
                f_last = a[i];
            }

            if(((first == n) || (second == m)) && flag){
                flag = false;
                idx = i;
                idx_f = a[i];
                idx_s = b[i];
                if(first == n) {
                    f_last = a[i];
                    type = 1;
                }else{
                    s_last = b[i];
                    type = 2;
                }

                f_sum += a[i];
                s_sum += b[i];
                first ++;
                second ++;

            }else{
                if(first > n){
                    s_sum += b[i];
                    second ++;

                }else if(second > m){
                    f_sum += a[i];
                    first ++;

                }else{
                    if(a[i] > b[i]){
                        first ++;
                        f_sum += a[i];
                    }else{
                        second ++;
                        s_sum += b[i];
                    }
                }
            }
        }

        if(n == 0){
            for(int i=0; i<all_nbr; i++){
                output.push_back(s_sum - b[i]);
            }

        }else if(m == 0){
            for(int i=0; i<all_nbr; i++){
                output.push_back(f_sum - a[i]);
            }
        }else{
            for(int i=0; i<all_nbr; i++){
                if(i < idx){
                    if(a[i] < b[i]){
                        if(type==1){
                            output.push_back(f_sum + s_sum - b[i] - f_last); 
                        }else{
                            output.push_back(f_sum + s_sum - b[i] - idx_f); //
                        }
                    }else{
                        if(type==1){
                            output.push_back(f_sum + s_sum - a[i] - idx_s); // 
                        }else{
                            output.push_back(f_sum + s_sum - a[i] - s_last); // 
                        }
                    }
                }else if (i==idx){
                    if(type == 1){
                        output.push_back(f_sum + s_sum - b[i] - f_last);
                    }else{
                        output.push_back(f_sum + s_sum - a[i] - s_last);
                    }

                }else{
                    if(type == 1){
                        output.push_back(f_sum + s_sum - b[i] - f_last);
                    }else{
                        output.push_back(f_sum + s_sum - a[i] - s_last);
                    }
                }
            }

        }

        for(int i=0; i<output.size(); i++){
            cout << output[i] << " ";
        }
        cout << endl;

    }

    return 0;
}