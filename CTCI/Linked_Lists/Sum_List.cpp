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


void Sum_E(struct node *LL1, struct node *LL2) {
string str1 = "",str2 = "";
while(LL1 != NULL){
	str1+=to_string(LL1->data);
	LL1 = LL1->next;
}
while(LL2 != NULL){
	str2+=to_string(LL2->data);
	LL2 = LL2->next;
}
reverse(str1.begin(),str1.end());
reverse(str2.begin(),str2.end());

cout<< stoi(str1)+stoi(str2)<<"\n";
}



void Sum_S(struct node *LL1, struct node *LL2) {

string str1 = "",str2 = "";
while(LL1 != NULL){
	str1+=to_string(LL1->data);
	LL1 = LL1->next;
}
while(LL2 != NULL){
	str2+=to_string(LL2->data);
	LL2 = LL2->next;
}
cout<< stoi(str1)+stoi(str2)<<"\n";
}


int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//Creating the Root Element
	struct node *LL1 = create_List_util(NULL, 7);
	create_List_util(LL1, 1);
	create_List_util(LL1, 6);


	struct node *LL2 = create_List_util(NULL, 5);
	create_List_util(LL2, 9);
	create_List_util(LL2, 2);


	Sum_S(LL1,LL2);
		Sum_E(LL1,LL2);

	//getting the K th Element from the Last
	cout<<"\n";

}