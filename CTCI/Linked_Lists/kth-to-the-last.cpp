//Getting the k th element from the Last
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

void k_th_to_last(struct node *root, int k) {
	static int count = 0;
	if (root == NULL) {
		return ;
	}
	else {
		k_th_to_last(root->next, k);
		count++;
		if (count == k) {
			cout << root->data << "\n";
		}

	}
}


int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//Creating the Root Element
	struct node *newroot = create_List_util(NULL, 5);
	create_List_util(newroot, 6);
	create_List_util(newroot, 11);
	create_List_util(newroot, 11);
	create_List_util(newroot, 9);
	create_List_util(newroot, 11);
	create_List_util(newroot, 11);
	//getting the K th Element from the Last
	k_th_to_last(newroot, 7);
}