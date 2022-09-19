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

node* createBT() {
	int data;
	cin >> data;
	if (data == -1) {
		return NULL;
	}

	node* root = new node(data);
	root->left = createBT();
	root->right = createBT();
	return root;
}

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
node* levelOrderInput()
{
        queue<node*>q;
        int d;
        cout<<"enter root data:";
        cin>>d;
        if(d==-1)
        {
            return NULL;
        }
        node * root=new node(d);
        q.push(root);
        while(!q.empty())
        {
            node* n=q.front();
            q.pop();
            cout<<"enter children of"<<n->data;
            int l,r;
            cin>>l>>r;
            if(l!=-1)
            {
                n->left=new node(l);
                q.push(n->left);
            }
            if(r!=-1)
            {
                n->right=new node(r);
                q.push(n->right);
            }
        }
        return root;



}
int pre[]={8,10,1,6,4,7,3,14,13};
int k=0;
node * buildTree(int *in,int s,int e)
{
    //base case
    if(s>e)
    {
        return NULL;
    }
    int d=pre[k++];
    node* root=new node(d);
    int i=-1;
    for(int j=s;j<=e;j++)
    {
        if(in[j] == d)
        {
            i=j;
            break;
        }
    }
    root->left=buildTree(in,s,i-1);
    root->right=buildTree(in,i+1,e);
    return root;
}


int main() {
	node* root = NULL;

	//root = createBT();
    //levelOrderInput();
    int in[]={1,10,4,6,7,8,3,13,14};
    int n=sizeof(in)/sizeof(int);
    root=buildTree(in,0,n-1);

	preorder(root);
	cout << endl;
	inorder(root);
	cout << endl;
	postorder(root);
	cout << endl;
    levelOrderTrav(root);

    return 0;
}