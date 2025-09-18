#include <iostream>

using namespace std;

class Node
{
public:
    int key;
    Node* left;
    Node* right;
    Node* parent;
    Node(int k,Node* l,Node* r,Node* p) : key(k),left(l),right(r),parent(p) {}
};

class BST
{
public:
    Node* root;

    BST() : root(nullptr) {}
    
    Node* Root()
    {
        return root;
    }

    void insert(int k)
    {
        if(!root)
        {
            root=new Node(k,nullptr,nullptr,nullptr);
            return;
        }

        Node* cur=root;
        Node* parent;

        while(cur)
        {
            parent=cur;
            if(k<cur->key) cur=cur->left;
            else if(k>cur->key) cur=cur->right;
        }

        Node* node=new Node(k,nullptr,nullptr,parent);
        if(k<parent->key) parent->left=node;
        else if(k>parent->key) parent->right=node;
    }

    void postOrder(Node* node)
    {
        if(!node) return;
        postOrder(node->left);
        postOrder(node->right);
        cout<<node->key<<"\n";
    }
};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    BST bst;

    int k;
    while(cin>>k) bst.insert(k);

    bst.postOrder(bst.Root());

    return 0;
}