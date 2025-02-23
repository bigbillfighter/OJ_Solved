#include <bits/stdc++.h>
using namespace std;

/*
// Definition for a Node.
*/
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;
        
        unordered_map<Node*, Node*> cacheNode;
        Node* newhead = new Node(head->val);

        cacheNode[head] = newhead;
        Node* past=newhead, *crt = newhead;
        
        for(Node* p=head->next; p!=nullptr; p=p->next){
            crt = new Node(p->val);
            past->next = crt;
            past = past->next;
        
            cacheNode[p] = crt;
        }
        crt->next=nullptr;

        crt = newhead;
        for(Node* p=head; p!=nullptr; p=p->next){
            crt->random = cacheNode[p->random];
            crt = crt->next;
        }
        return newhead;
    }
};