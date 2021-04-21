#ifndef EMPBINARYTREE_H
#define EMPBINARYTREE_H
#include "Employee.h"
#include <string>

class EmpBinaryTree
{
private:
    struct TreeNode
    {
        Employee e;
        TreeNode *left;
        TreeNode *right;
    };
    TreeNode *root;
    void insert(TreeNode *&, TreeNode *&);
    void destroySubTree(TreeNode *);
    void deleteNode(Employee, TreeNode *&);
    void makeDeletion(TreeNode *&);
    void displayInOrder(TreeNode *) const;
    void displayPreOrder(TreeNode *) const;
    void displayPostOrder(TreeNode *) const;
public:
//    // Constructor
    EmpBinaryTree()
        { root = nullptr; }
    // Destructor
    ~EmpBinaryTree()
        { destroySubTree(root); }
    // Binary tree operations
    void insertEmployee(Employee);
    bool searchEmployee(Employee); //see if the number of employee matches if have two chris smith in there.
    Employee getEmployee(string);
    void remove(Employee);
    void displayInOrder() const
        { displayInOrder(root); }
    void displayPreOrder() const
        { displayPreOrder(root); }
    void displayPostOrder() const
        { displayPostOrder(root); }
};
#endif
