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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int top=0;
        ListNode *p1, *p2;
        ListNode *last, *new_node;
        for(p1=l1, p2=l2; p1!=nullptr && p2!=nullptr; p1=p1->next, p2=p2->next){
            p1->val += p2->val+top;
            top = p1->val / 10;
            p1->val = p1->val % 10;
            last = p1;
        }
        if(p2==nullptr){
            for(;p1!=nullptr; p1=p1->next){
                p1->val += top;
                top = p1->val / 10;
                p1->val = p1->val % 10;
                last = p1;
            }
            if(top){
                new_node = new ListNode(top);
                last->next = new_node;
            }
        }else{
            last -> next = p2;
            for(;p2!=nullptr; p2=p2->next){
                p2->val += top;
                top = p2->val / 10;
                p2->val = p2->val % 10;
                last = p2;
            }
            if(top){
                new_node = new ListNode(top);
                last->next = new_node;
            }
        }
        return l1;
    }
};