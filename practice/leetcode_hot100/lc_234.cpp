#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> rst;
        for(ListNode* p=head; p!=nullptr; p=p->next){
            rst.push_back(p->val);
        }
        int rst_size = rst.size();
        for(int i=0; i< (rst_size+1)/2; i++){
            if(rst[i]!=rst[rst_size-i-1]) return false;
        }
        return true;
    }
};