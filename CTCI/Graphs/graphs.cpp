#include <bits/stdc++.h>
using namespace std;
struct node{
int node_val;
struct node *left,*right;
};



//utiltiy function that creates a node dynamically
struct node *create_node(int key){
struct node *newnode  = (node *)malloc(sizeof(node));
newnode->node_val = key;
newnode->left = NULL;
newnode->right = NULL;
return newnode;
}

//utiltiy function that adds a child 
struct node *add_child(struct node *root,int key){
if(root == NULL){
	cout<<"Created node \n";
	return create_node(key);
}
if(key > root->node_val){
	cout<<"going right\n";
	root->right = add_child(root->right,key);
	return root;
}
else{
	cout<<"going left\n";
	root->left  = add_child(root->left,key);
	return root;
}

}


//Print nodes in Inorder traversal
void print_nodes(struct node *root){
if (root != NULL)
    {
        print_nodes(root->left);
        printf("%d \n", root->node_val);
        print_nodes(root->right);
    }

}

int main(int argc, char const *argv[])
{
	struct node *root = NULL;
	root = add_child(root,1);
	add_child(root,5);
	add_child(root,53);
	add_child(root,12);
	print_nodes(root);
	return 0;
}