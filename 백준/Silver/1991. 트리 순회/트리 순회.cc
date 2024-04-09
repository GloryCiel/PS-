#include <bits/stdc++.h>

using namespace std;

typedef struct NODE
{
    char key;
    NODE* left;
    NODE* right;
}NODE;

void preorder(NODE*);
void inorder(NODE*);
void postorder(NODE*);

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;cin>>N;

    vector<NODE>nodes(N);
    for(int i=0;i<N;++i)
    {
        nodes[i].key = i+'A';
    }

    for(int i=0;i<N;++i)
    {
        char a,b,c;cin>>a>>b>>c;
        if(b!='.')
            nodes[a-65].left = &nodes[b-65];
        if(c!='.')
            nodes[a-65].right = &nodes[c-65];
    }

    preorder(&nodes[0]);cout<<'\n';
    inorder(&nodes[0]);cout<<'\n';
    postorder(&nodes[0]);cout<<'\n';

}

void preorder(NODE* root)
{
    cout<<root->key;
    if(root->left !=NULL)
    {
        preorder(root->left);
    }
    if(root->right != NULL)
    {
        preorder(root->right);
    }
}

void inorder(NODE* root)
{
    if(root->left !=NULL)
    {
        inorder(root->left);
    }
    cout<<root->key;
    if(root->right != NULL)
    {
        inorder(root->right);
    }
}

void postorder(NODE* root)
{
    if(root->left !=NULL)
    {
        postorder(root->left);
    }
    if(root->right != NULL)
    {
        postorder(root->right);
    }
    cout<<root->key;
}