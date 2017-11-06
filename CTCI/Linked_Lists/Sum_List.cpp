//Printing the Sum of  List 
#include <bits/stdc++.h>
using namespace std;

//Structure of a Node as Doubly Linked List
struct node {
	int data;
	struct node *next,*prev;
};

//Utility Function to create the Node
struct node * create_node_util(int key) {
	struct node *newnode = (node *)malloc(sizeof(node));
	newnode->data = key;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}

//Utility Function to create the List
struct node * create_List_util(struct node *root, int key) {
	if (root == NULL) {
		return create_node_util(key);
	}
	else
	{

		root->next = create_node_util(key);
		root->next->prev = root;
	}
	return root->next;
}

//Utility Function to Print the List
void print_list(struct node  *root) {
	while (root != NULL) {
		cout << root->data << " ";
		root = root->prev;
	}
	cout << "\n";
}

//Prints the Sum assuming forward storing of numbers
int  Sum_F(struct node *LL1, struct node *LL2) {

int sumf = 0;
int i = 0;
while(LL1 != NULL && LL2 != NULL){
	sumf = sumf + (LL1->data+LL2->data)*pow(10,i);
	LL1 = LL1->prev;
	LL2 = LL2->prev; 
	i++;
}
return sumf;
}


//Prints the Sum assuming backward storing of numbers
int Sum_B(struct node *LL1, struct node *LL2) {

int sumf = 0;
int i = 0;
while(LL1 != NULL && LL2 != NULL){
	sumf = sumf + (LL1->data+LL2->data)*pow(10,i);
	LL1 = LL1->next;
	LL2 = LL2->next; 
	i++;
}
return sumf;

}

//Driver Function to test the Above 
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//Creating the Root Element
	struct node *head1,*head2;
	struct node *LL1 = create_List_util(NULL, 7);
	//Pointer to  start of the List2
	head1 = LL1;
	LL1  = create_List_util(LL1, 1);
	LL1 = create_List_util(LL1, 6);


	struct node *LL2 = create_List_util(NULL, 5);
	//Pointer to  start of the List2  
	head2  = LL2;
	LL2 = create_List_util(LL2, 9);
	LL2 = create_List_util(LL2, 2);

	//Adding numbers which are stored backwards
	int sumb = Sum_E(LL1, LL2);
	//Adding numbers assuming they are stored forward
	int sumf = Sum_S(head1,head2);
	
	// Print the List
	//print_list(LL2);
	
	//Printing for Numbers stored in backward Form
	cout << sumf<<"\n";
	//printing for numbers stored in forward form
	cout << sumb<<"\n";
	

}