//partitioning the Linked List wrt to a  Given Element
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

void Partition(struct node *root, int k) {
	cout << "Now here the Real Fun starts\n";
	struct node *gre_nod_ll;
	gre_nod_ll = NULL;
	struct node *temp;
	while (root != NULL) {
		temp = root;
		root = root->next;
		// Constraints need to satisfied Here
		if (root->data >= k) {
			if (gre_nod_ll == NULL) {
				cout<<"Yup i am here NULL section\n";
				temp->next = root->next;
				gre_nod_ll = root;
				gre_nod_ll->next = NULL;
				root = temp->next;
				cout<<"Now temp point: "<<temp->data<<"\n";
				cout<<"Now root point: "<<root->data<<"\n";
			}
			else {
				cout<<"I am here the section below\n";
				gre_nod_ll->next = root;
				temp->next = root->next;
				gre_nod_ll = gre_nod_ll->next;
				root->next = NULL;

			}
		} else {
			continue;

		}
	}

	while (gre_nod_ll != NULL) {
		cout << gre_nod_ll->data << " -> ";
		gre_nod_ll = gre_nod_ll->next;
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
	create_List_util(newroot, 3);
	create_List_util(newroot, 12);
	create_List_util(newroot, 1);
	create_List_util(newroot, 0);
	print_list(newroot);
	//getting the K th Element from the Last
	Partition(newroot, 7);
	cout<<"\n";
		print_list(newroot);

}