#include <iostream>
#include <string>
#include "EmpBinaryTree.h"
#include "Employee.h"
using namespace std;

void EmpBinaryTree::insert(TreeNode *&parent, TreeNode *&newnode){

	if(parent == NULL){//there is no first node
		parent = newnode;
		//cout<<"my dog"<<endl;
	}
	else if(parent->e.getName() < newnode->e.getName()){
		insert(parent->right,newnode);
		//cout<<"what up my dog"<<endl;
	}
	else{
		insert(parent->left,newnode);
		//cout<<"dude dog"<<endl;
	}

}
void EmpBinaryTree::destroySubTree(TreeNode *head){ // delete the entire tree
	if(head->left){ // first it will go all the way to the left of the tree
		destroySubTree(head->left);
	}
	if(head->right){
		destroySubTree(head->right);
	}
	delete head; //it will go to the leaf node of the tree and then start deleting
}
void EmpBinaryTree::deleteNode(Employee emp, TreeNode *&parent){ // finds the employee which needs to be deleted in the bst. then it passes to makeDeletion().
	if(emp.getName() < parent->e.getName()){
		deleteNode(emp,parent->left);
	}
	else if(emp.getName() > parent->e.getName()){
		deleteNode(emp,parent->right);
	}
	else {
		makeDeletion(parent);
	}
}
void EmpBinaryTree::makeDeletion(TreeNode *&parent){//receives the exact Treenode to delete.
//Now just delete the node properly
	TreeNode *temp = NULL;
	if(parent == NULL){ // there is nothing to delete
		cout<<"can't delete"<<endl;
	}
	else if(parent->right == NULL){ //node only has a left child
		temp = parent;
		parent = parent->left;
		delete temp;
	}
	else if(parent->left == NULL){ //node only has a right child
		temp = parent;
		parent = parent->left;
		delete temp;
	}
	else{//when the node that needs to be deleted as two children
		temp = parent->left; //or go to the right
		while (temp->right){ //find the min.
			temp = temp->right;
		}
		temp->right = parent->right;
		temp = parent;
		parent = parent->left;
		delete temp;

	}
}
void EmpBinaryTree::displayInOrder(TreeNode *parent) const{
	if (parent)
	{
		displayInOrder(parent->left);

		cout << parent->e.getName() <<endl;

		cout << parent->e.getNumber() <<endl;
		//cout<<"wassup"<<endl;
		cout << parent->e.getHireDate() <<endl;
		//cout<<"dang"<<endl;
		displayInOrder(parent->right);
	}
}
void EmpBinaryTree::displayPreOrder(TreeNode *parent) const{
	if (parent)
	{
		cout << parent->e.getName()<<endl;
		displayPreOrder(parent->left);
		displayPreOrder(parent->right);
	}

}
void EmpBinaryTree::displayPostOrder(TreeNode *parent) const{
	if (parent)
	{
		displayPostOrder(parent->left);
		displayPostOrder(parent->right);
		cout << parent->e.getName()<<endl;
	}
}

void EmpBinaryTree::insertEmployee(Employee emp){
	TreeNode *newnode = new TreeNode;
	newnode->e=emp;
	newnode->left = NULL;
	newnode->right = NULL;

	insert(root, newnode);
}
bool EmpBinaryTree::searchEmployee(Employee emp){
	TreeNode *temp = root;
	while(temp){
		if(temp->e.getName() == emp.getName()){
			return true;
		}
		else if(emp.getName() < temp->e.getName()){
			temp=temp->left;
		}
		else{
			temp=temp->right;
		}
	}
	return false;
}
Employee EmpBinaryTree::getEmployee(string name){ // cant do recursively because need to pass the parent node as a parameter
	TreeNode *temp = root;
	Employee ee;
	while(temp){
		if(temp->e.getName() == name){
			ee = temp->e; //the copy constructor gets called when you do ee= temp->e.
						//Sometimes you need to overload the copy constructor. in this case you dont need to
			break;
		}
		else if(name < temp->e.getName()){
			temp=temp->left;
		}
		else{
			temp=temp->right;
		}
	}
	return ee;
}
void EmpBinaryTree::remove(Employee emp){
	deleteNode(emp, root);
}




