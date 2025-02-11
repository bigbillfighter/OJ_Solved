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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return head;
        stack<ListNode*> list;
        for(ListNode* p = head; p!=nullptr; p=p->next){
            list.push(p);
        }
        ListNode* first = list.top();
        list.pop();
        ListNode* crt = first;
        while(!list.empty()){
            ListNode* next = list.top();
            crt->next = next;
            crt = next;
            list.pop();
        }

        crt->next = nullptr;
        return first;
    }
};