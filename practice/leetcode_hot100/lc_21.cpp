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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;
        
        ListNode* fstart=list1, *sstart = list2;
        ListNode* rst = list1;

        if(list1->val > list2->val) rst = list2;
        
        ListNode *p1=list1, *p2=list2;
        while(p1 != nullptr && p2 != nullptr){
            if(p1->val <= p2->val){
                while(p1->next != nullptr && p1->next->val < p2->val){
                    p1 = p1->next;
                }
                ListNode *crt = p2->next;
                p2->next = p1->next;
                p1->next = p2;
                p2 = crt;
            }else{
                while(p2->next != nullptr && p2->next->val < p1->val){
                    p2 = p2->next;
                }
                ListNode *crt = p1->next;
                p1->next = p2->next;
                p2->next = p1;
                p1 = crt;
            }
        }
        return rst;

    }
};