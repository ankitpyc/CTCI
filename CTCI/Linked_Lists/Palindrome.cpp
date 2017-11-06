
#include <bits/stdc++.h>
using namespace std;

//Structure of a Node as Doubly Linked List
struct node {
	int data;
	struct node *next,*prev;
}*head1;

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

		root->next = create_List_util(root->next,key);
	
	}
	return root;
}

//Utility Function to Print the List
void print_list(struct node  *root) {
	while (root != NULL) {
		cout << root->data << " ";
		root = root->next;
	}
	cout << "\n";
}


bool isPalindrome(node *head2){
bool isP = true;
struct node *prev;
while(head2!=NULL){
	prev = head2;
	isPalindrome(head2->next);
	if(prev->data == head1->data){
		if(head1 == prev){
			head1 = NULL;
			prev = NULL;
			return true;
		}
		cout<<head1->data<<" == "<<prev->data<<"\n";
		head1 = head1->next;
}
	else{
		if(head1 != prev)
		return false;
	}

}
return isP;
}



//Driver Function to test the Above 
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//Creating the Root Element
	struct node *LL1 = create_List_util(NULL, 7);
	//Pointer to  start of the List2
	head1 = LL1;
	 create_List_util(LL1, 1);
	 create_List_util(LL1, 3);
	 create_List_util(LL1, 1);
	 create_List_util(LL1, 7);
if(isPalindrome(LL1))
	cout<<"LL is Palindrome\n";
else
	cout<<"LL is not Palindrome\n";

	

}