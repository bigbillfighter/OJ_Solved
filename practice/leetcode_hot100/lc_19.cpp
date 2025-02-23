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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy, *first, *second;
        dummy = new ListNode();
        dummy->next = head;
        first = second = dummy;
        for(int i=0; i<n; i++) second = second->next;
        while(second->next != nullptr){
            second = second->next;
            first = first->next;
        }
        first->next = first->next->next;
        return dummy->next;
    }
};