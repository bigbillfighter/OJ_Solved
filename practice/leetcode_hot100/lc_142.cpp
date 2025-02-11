#include<bits/stdc++.h>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr || head->next->next==nullptr) return nullptr;
        ListNode *slow = head->next, *fast = head->next->next;
        while(fast != slow){
            if(fast->next==nullptr || fast->next->next==nullptr) return nullptr;
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *p = head;
        while(p!=slow){
            p=p->next;
            slow=slow->next;
        }
        return p;

    }
};