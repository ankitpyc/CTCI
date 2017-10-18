//Program to Remove Duplicates 


#include <bits/stdc++.h>
using namespace std;

struct node {
	int data;
	struct node *next;
};


struct node * create_node_util(int key) {
	struct node *newnode = (node *)malloc(sizeof(node));
	newnode->data = key;
	newnode->next = NULL;
	return newnode;
}


struct node * create_List_util(struct node *root, int key) {
	if (root == NULL) {
		return create_node_util(key);
	}
	else
	{
		root->next = create_List_util(root->next, key);
	}
	return root;
}


void print_list(struct node  *root) {
	while (root != NULL) {
		cout << root->data << " ";
		root = root->next;
	}
	cout << "\n";
}

int k_th_to_last(struct node *root,int k){
struct node *p = root;
struct node *q = p+k;
cout<<p->data<<"->"<<q->data<<"\n";
return 0;
}








int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	struct node *newroot = create_List_util(NULL, 5);
	create_List_util(newroot, 6);
	create_List_util(newroot, 11);
	create_List_util(newroot, 11);
	create_List_util(newroot, 9);
	create_List_util(newroot, 11);
	create_List_util(newroot, 11);

	print_list(newroot);
	cout<<k_th_to_last(newroot,5)<<"\n";


}