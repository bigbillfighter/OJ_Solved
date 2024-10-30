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
    bool hasCycle(ListNode *head) {
        
        // method 1
        // int number = 1e4+5;
        // ListNode *p = head;
        // int idx = 0;
        // while(p!=nullptr && idx < number){
        //     p = p->next;
        //     idx += 1;
        // }
        // if(idx >= number) return true;
        // else return false;

        // method 2
        if(head == nullptr || head->next == nullptr) return false;
        ListNode *fast = head->next, *slow = head;
        while(fast!=slow){
            if(fast->next == nullptr || fast->next->next==nullptr) return false;
            fast = fast->next->next;
            slow = slow->next;
        }
        return true;
    }
};