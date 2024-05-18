```cpp
/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        if(pNode->right==NULL){
            TreeLinkNode* p = pNode;
            pNode = pNode->next;
            while(pNode->right==p && pNode !=NULL){
                p = p->next;
                pNode = pNode->next;
            }
            if(pNode==NULL){
                return NULL;
            }else 
                return pNode;
            
        }else{
            TreeLinkNode* p = pNode->right;
            while(p->left!=NULL){
                p=p->left;
            }
            return p;
        }
    }
};

```