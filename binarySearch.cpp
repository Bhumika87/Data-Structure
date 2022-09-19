#include <iostream>
#include<queue>
using namespace std;
class node {
public:
	int data;
	node* left;
	node* right;
	node(int d): data(d), left(NULL), right(NULL) {}
};
void preorder(node* root) {
	// base case
	if (!root) {
		return;
	}
	// recursive case
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}

void inorder(node* root) {
	// base case
	if (!root) {
		return;
	}
	// recursive case
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

void postorder(node* root) {
	// base case
	if (!root) {
		return;
	}
	// recursive case
	postorder(root->left);
	postorder(root->right);
	cout << root->data << " ";
}
void levelOrderTrav(node * root)
{
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node * n=q.front();
        q.pop();
        if(n==NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }else{
            cout<<n->data<<" ";
            if(n->left!=NULL)
            {
               q.push(n->left);
            }
            if(n->right!=NULL)
            {
               q.push(n->right);
            }

        }
    }
}
node * insertBST(node*root,int d)
{
    //base casee
    if(!root)
    {
        root=new node(d);
        return root;
    }
    if(root->data >= d)
    {
        root->left=insertBST(root->left,d);
    }else{
        root->right=insertBST(root->right,d);
    }
    return root;
}

node * creatBST()
{
    node* root= NULL;
    int d;
    cin>>d;
    if(d==-1) return root;
    while(d!=-1)
    {
        root=insertBST(root,d);
        cin>>d;
    }
    return root;

}
void printRange(node * root,int k1,int k2)
{
    if(!root)
    {
        return;
    }
    if(root->data >=k1 and root->data<=k2)
    {
         cout<<root->data<<" ";
    }
    printRange(root->left,k1,k2);
    printRange(root->right,k1,k2);

}
node *searchBST(node* root,int key)
{
    if(!root)
    {
        return nullptr;
    }
    if(root->data==key)
    {
        return root;
    }
    else if(root->data > key)
    {
        return searchBST(root->left,key);
    }else{
        return searchBST(root->right,key);
    }
}
bool isBST(node * root,int mi=INT_MIN,int mx=INT_MAX)
{
    if(!root)
    {
        return true;
    }
    if(root->data>=mi and root->data <=mx
    and isBST(root->left,mi,root->data) and isBST(root->right,root->data,mx))
    {
         return true;
    }
    return false;
}

int main()
{
    node* root=creatBST();
    preorder(root);
	cout << endl;
	inorder(root);
	cout << endl;
	postorder(root);
	cout << endl;
    levelOrderTrav(root);
    node * ans=searchBST(root,100);
    if(!ans)
    {
        cout<<"not found";
    }else{
        cout<<"found"<<ans->data;
    }
    int r=isBST(root,);
    if(r==true)
    {
        cout<<"tree is bst";
    }else{
        cout<<"tree is not bst";
    }

    return 0;
}