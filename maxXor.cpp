#include <iostream>
using namespace std;

class node {
public:
	int data;
	node* left;
	node* right;
	node() {
		left = right = NULL;
	}
};

class Trie {
public:
	node* root;
	Trie() {
		root = new node();
	}

	void insert(int n) {
		node* temp = root;
		for (int i = 31; i >= 0; --i)   
		{
			int bit = (n & (1 << i)) ?  1 : 0;    //no ki MSB MEANG LEFT VALI BIT KO CHECK KREGA 0 H Y 1
			if (bit == 1) {
				if (!temp->right) {      //AGR TEMP RIGHT NULL H TOH NEW NODE
					temp->right = new node();
				}
				temp = temp->right;  //AGR NAHI HAI TOH RIGHT M MOVE KRDENGE
				/*
				if (temp->right) {
					temp = temp -> right;
				}
				else {
					temp->right = new node();
					temp = temp->right;
				}
				*/
			}
			else {
				if (!temp->left) {   //AGR 0 HAI TOH LEFT M NODE NAHI HAI TOH NEW BNKR TEMP KO AGGEE MOVE
					temp->left = new node();
				}
				temp = temp->left;
			}
		}
		temp->data = n;   //OR FIR SARE BIT FILL KRNA K BD LAST M NUM DLDENGE JISKI BIT NIKLI H 
	}

	int maxXorPairHelper(int n) {
		node* temp = root;
		for (int i = 31 ; i >= 0 ; i--) {
			int bit = (n & (1 << i)) ? 1 : 0;
			if (bit == 0) {     //MAXIMUM XOR K LIA MSB M 1 CHAIYA AGR 0 H TOH ONE K LIA CHECK KRNGE MTLN RIGHT NODE H Y NI
				if (temp->right) {
					temp = temp->right;
				}
				else {
					temp = temp->left;   //AGR NHI H TOH LEFT M HI MOVE KRLO
				}
			}    
			else {
				if (temp->left) { // LKIN MSB 1 HAI TOH 0 DKHNGE MTLB LEFT NODE
					temp = temp->left;
				}
				else {
					temp = temp->right;   // AGR NHI H TOH RIGHT M MOVE
				}
			}
		}
		return temp->data ^ n;  // EXOR RETURN KRDENGE 
	}

	int maxXorPair(int a[], int n) {
		int ans = INT_MIN;

		for (int i = 0; i < n; ++i)
		{
			insert(a[i]);
			int t = maxXorPairHelper(a[i]);
			ans = max(ans, t);   // MAX XOR IN TRIE
		}
		return ans;
	}
};

int main() {

	Trie t;

	int a[] = {1, 5, 3, 4, 10};
	int n = sizeof(a) / sizeof(int);

	cout << t.maxXorPair(a, n) << endl;

	return 0;
}

