#include <iostream>

using namespace std;

int N;

struct Node
{
    char data;
    Node* left;
    Node* right;
};

Node* nodes[26];

Node* MakeNode(char data)
{
    return new Node{data,nullptr,nullptr};
}

Node* GetOrMake(char data)
{
    if(data=='.') return nullptr;
    if(nodes[data-'A']==nullptr) nodes[data-'A']=MakeNode(data);

    return nodes[data-'A'];
}

void PreOrder(Node* node)
{
    if(node==nullptr) return;

    cout<<node->data;
    PreOrder(node->left);
    PreOrder(node->right);
}

void InOrder(Node* node)
{
    if(node==nullptr) return;

    InOrder(node->left);
    cout<<node->data;
    InOrder(node->right);
}

void PostOrder(Node* node)
{
    if(node==nullptr) return;

    PostOrder(node->left);
    PostOrder(node->right);
    cout<<node->data;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin>>N;
    for(int i=0;i<N;i++)
    {
        char a,b,c;
        cin>>a>>b>>c;

        Node* node=GetOrMake(a);
        node->left=GetOrMake(b);
        node->right=GetOrMake(c);
    }

    PreOrder(nodes[0]);
    cout<<"\n";

    InOrder(nodes[0]);
    cout<<"\n";

    PostOrder(nodes[0]);
    cout<<"\n";

    return 0;
}