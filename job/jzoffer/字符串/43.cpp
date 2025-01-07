#include <bits/stdc++.h>
using namespace std;

const int max_length = 405;

class BigInt{
public:
    int length = 0;
    int digits[max_length];

    BigInt(){
        length = 1;
        for(int i=0; i<max_length; i++){
            digits[i] = 0;
        }
    }

    BigInt(string& str){
        length = str.length();
        for(int i=0; i<max_length; i++){
            digits[i] = 0;
        }

        for(int i=length-1; i>=0; i--){
            digits[length-i-1] = str[i] - '0';
        }
    }

    BigInt (const BigInt& bigint2){
        length = bigint2.length;
        for(int i=0; i<max_length; i++){
            digits[i] = bigint2.digits[i];
        }
    }

    void move(int start){
        if(start == 0) return;
        if(length == 1 && digits[0] == 0) return;
        for(int i=length-1; i>=0; i--){
            digits[i+start] = digits[i];
        }
        for(int i=0; i<start; i++){
            digits[i] = 0;
        }
        length = length + start;
    }

    void add(const BigInt& num){
        int rst_length = this->length > num.length ? this->length : num.length;
        int add_rest = 0;
        for(int i=0; i<rst_length; i++){
            int cur = (this->digits[i] + num.digits[i] + add_rest) % 10;
            add_rest = (this->digits[i] + num.digits[i] + add_rest) / 10;
            this->digits[i] = cur;
        }
        if(add_rest > 0){
            this->digits[rst_length] = add_rest;
            this->length = rst_length + 1;
        }else{
            this->length = rst_length;
        }
    }

    void multiply(int nbr){
        int add_rest = 0;
        for(int i=0; i< length; i++){
            int cur = (digits[i] * nbr + add_rest) % 10;
            add_rest = (digits[i] * nbr + add_rest) / 10;
            digits[i] = cur;
        }
        if(add_rest > 0){
            digits[length] = add_rest;
            length++;
        }
        if(nbr == 0){
            length = 1;
        }
    }

    void multiply(const BigInt& bigint2){
        BigInt rst;
        for(int i=0; i<bigint2.length; i++){
            BigInt crt = BigInt(*this);
            crt.multiply(bigint2.digits[i]);
            crt.move(i);
            rst.add(crt);
        }
        *this = BigInt(rst);
    }

    string to_string(){
        string rst = "";
        for(int i=length-1; i>=0; i--){
            rst += '0' + digits[i];
        }
        return rst;
    }
};

class Solution {
public:
    string multiply(string num1, string num2) {
        BigInt big1(num1), big2(num2);
        big1.multiply(big2);
        return big1.to_string();
    }
};

int main(){
    // improve is speed
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    Solution solu;
    string num1, num2;
    cin >> num1 >> num2;

    string rst = solu.multiply(num1, num2);
    cout << rst << endl;
    return 0;
}