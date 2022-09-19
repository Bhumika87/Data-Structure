#include <iostream>
#include <queue>
using namespace std;

class node {
public:
	int data;
	node* left;
	node* right;
	node(int d): data(d) {
		left = right = NULL;
	}
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
node* creatBst(int arr[],int start,int end)
{
    if(start>end)
    {
        return NULL;
    }
    int mid = (start+end)/2 ;
    node * n=new node(arr[mid]);
    n->left=creatBst(arr,start,mid-1);
    n->right=creatBst(arr,mid+1,end);
    return n;
}
class linkedList
{
    public:
    node * head, *tail;

};
linkedList BSTtoll(node * root)
{
    linkedList l;
    if(!root->left and !root->right)
    {
        l.head=l.tail= root;
        return l;
    }else if(!root->left and root->right)
    {
        linkedList rightll = BSTtoll(root->right);
        root->right=rightll.head;
        l.head=root;
        l.tail=rightll.tail;
        return l;

    }else if(root->left and !root->right)
    {
        linkedList leftll=BSTtoll(root->left);
        leftll.tail->right=root;
        l.head=leftll.head;
        l.tail=root;
        return l;
    }else
    {
        linkedList leftll=BSTtoll(root->left);
        linkedList rightll = BSTtoll(root->right);
        leftll->

    }

}
int main()
{
    int arr[] ={60,70,80,90,100};
    node * root=creatBst(arr,0,4);
    preorder(root);
    cout<<endl;
    return 0;
}