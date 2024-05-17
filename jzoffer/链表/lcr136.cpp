#include <bits/stdc++.h>
using namespace std;



struct ListNode {
    int val;
    struct ListNode *next;
};


class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param n int整型 
     * @return int整型
     */
    
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode* last = NULL;
        last = (ListNode *)malloc(sizeof(ListNode));
        last->next = head;

        ListNode* move = last;
        for(ListNode* p=head; p!=NULL; p = p->next){
            if(p->val == val){
                move->next = p->next;
                break;
            }
            move = move->next;
        }
        return last->next;
    }
};


int main(){
    // improve is speed
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    Solution solu;

    int length;
    cin >> length;

    ListNode* head = NULL;
    head = (ListNode *)malloc(sizeof(ListNode));
    if(head == NULL){
        cout << "memory allocation failure" << endl;
        exit(0);
    }
    head->next = NULL;

    int node_data;
    if(length > 0){
        ListNode* crt = head;
        for(int i=0; i< length; i++){
            ListNode* node = NULL;
            node = (ListNode *)malloc(sizeof(ListNode));
            if(node == NULL){
                cout << "memory allocation failure" << endl;
                exit(0);
            }
            node->next = NULL;
            cin >> node_data;
            node->val = node_data;
            crt->next = node;
            crt = crt->next;
        }
        crt = NULL;
    }else{
        assert(head->next == NULL);
    }

    // for(ListNode* p=head->next; p!=NULL; p = p->next){
    //     cout << p->val << " ";
    // }
    // cout << endl;
    
    int val;
    cin >> val;

    ListNode* rst = solu.deleteNode(head->next, val);

    for(ListNode* p=rst; p!=NULL; p = p->next){
        cout << p->val << " ";
    }
    cout << endl;
    return 0;
}