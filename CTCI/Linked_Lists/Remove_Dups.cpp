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



void remove_dups(struct node *root) {
	if (root == NULL) {
		return;
	}
	else {
		while (root != NULL)
		{
			struct node  *p = root;
			struct node  *q = p->next;
			struct node  *temp = q;
			while (q != NULL) {
				if (p->data == q->data) {
					if (p->next->next == NULL && q->next == NULL) {
						p->next = NULL;
						break;
					}
					if (p->data == q->data && p->next == q) {
						p->next = q->next;
						continue;
					}
					temp->next = q->next;
					q = q->next;
					continue;
				} else {
					temp = q;
					q = q->next;
				}

			}
			root = root->next;
		}

	}
}




int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	struct node *newroot = create_List_util(NULL, 5);
	create_List_util(newroot, 6);
	create_List_util(newroot, 11);
	create_List_util(newroot, 11);
	create_List_util(newroot, 7);
	create_List_util(newroot, 16);
	create_List_util(newroot, 16);
	create_List_util(newroot, 16);
	create_List_util(newroot, 16);
	create_List_util(newroot, 15);
	print_list(newroot);
	remove_dups(newroot);
	print_list(newroot);


}