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

void Del_Mid_Element(struct node *root) {
	struct node *p, *q ;
	p = root;
	q = root;
	struct node *temp;
	while (q->next != NULL) {
		temp = p;
		p = p->next;
		q = q->next->next;
		//Check for incase of Even Length Linked Lists has Two Middle ELements
		if (q->next != NULL && q->next->next == NULL) {
			temp->next = temp->next->next;
			break;
		}
		else
		{
			continue;
		}
	}
	if (q->next == NULL) {
		cout << p->data << "\n";
		q->next = p->next;
	}
}


int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//Creating the Root Element
	struct node *newroot = create_List_util(NULL, 5);
	//Filling the Linked Lists
	create_List_util(newroot, 6);
	create_List_util(newroot, 10);
	create_List_util(newroot, 11);
	create_List_util(newroot, 12);
	create_List_util(newroot, 13);
	create_List_util(newroot, 14);
	create_List_util(newroot, 15);
	cout << "Actual linked List\n";
	print_list(newroot);
	//getting the K th Element from the Last
	Del_Mid_Element(newroot);
	cout << "Deleting the Middle element from linked List\n";
	print_list(newroot);

}