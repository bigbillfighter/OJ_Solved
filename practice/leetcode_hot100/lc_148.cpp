#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:

    ListNode* find_middle(ListNode* crt){
        ListNode *dummy = new ListNode();
        dummy->next = crt;

        ListNode *fast=dummy, *slow=dummy;
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* first, ListNode* second){
        if(first == nullptr) return second;
        if(second == nullptr) return first;

        ListNode* dummy = new ListNode();
        if(first->val > second->val){
            dummy->next = second;
            second = second->next;
        }else{
            dummy->next = first;
            first = first->next;
        }

        ListNode* prev = dummy->next;
        while(first != nullptr && second != nullptr){
            if(first->val > second->val){
                prev->next = second;
                second = second->next;
                prev = prev->next;
            }else{
                prev->next = first;
                first = first->next;
                prev = prev->next;
            }
        }
        if(first != nullptr){
            prev->next = first;
        }
        if(second != nullptr){
            prev->next = second;
        }
        return dummy->next;
    }

    ListNode* sortList(ListNode* head) {
        if(head==nullptr || head->next == nullptr){
            return head;
        }

        ListNode* middle_node = find_middle(head);
        ListNode* left_head = head, *right_head = middle_node->next;
        middle_node->next = nullptr;

        left_head = sortList(left_head);
        right_head = sortList(right_head);

        return merge(left_head, right_head);
    }
};