#include <bits/stdc++.h>
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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr) return head;
        else if(head->next == nullptr) return head;
        else{
            ListNode* new_head = head->next;
            head->next = head->next->next;
            new_head->next = head;
            head->next = swapPairs(head->next);
            return new_head;
        }
    }
};