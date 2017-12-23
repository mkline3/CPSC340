//Matt Kline
#include "tree.h"
#ifndef TREE_CPP
#define TREE_CPP
#include "Room.h"

template<class ItemType>
void TreeType<ItemType>::operator=(TreeType<ItemType> &original)
{
        if(original == this)
                return; //ignore assigning self to self
        Destroy(root);
        CopyTree(root, original.root);
}


template<class ItemType>
void TreeType<ItemType>::CopyTree(TreeNode<ItemType>*& copy, const TreeNode<ItemType>* original)
{
        copy = original;
        if(original != NULL){
                copy = new TreeNode<ItemType>;
                copy->data = original->data;
                CopyTree(copy->left, original->left);
                CopyTree(copy->right, original->right);
        }
}



template<class ItemType>
TreeType<ItemType>::~TreeType()
{
   Destroy(root);
}
template <class ItemType>
void TreeType<ItemType>::Destroy(TreeNode<ItemType>*& root)
{
        if(root != NULL){
                Destroy(root->left);
                Destroy(root->right);
                delete root;
        }
}

template <class ItemType>
TreeType<ItemType>::TreeType()
{
   root = NULL;
}
template<class ItemType>
void TreeType<ItemType>::Insert(ItemType item)
{
   InsertItem(root, item);
}


template<class ItemType>
bool TreeType<ItemType>::InsertItem(TreeNode<ItemType>*& root, ItemType value)
{
        if(root == NULL){
                root = new TreeNode<ItemType>;
                root->data = value;
                root->left = NULL;
                root->right = NULL;
                return true;
        }
        else if(value < root->data){
                return(InsertItem(root->left, value));
	}
        else if(value > root->data){
                return(InsertItem(root->right,value));
        }
        else{
                return false;
        }
}


template<class ItemType>
void TreeType<ItemType>::Print()
{
   PrintTree(root);

}


template <class ItemType>
void TreeType<ItemType>::PrintTree(TreeNode<ItemType>* root)
{
        if(root != NULL){
                PrintTree(root->left);
                cout<< root->data << " ";
                PrintTree(root->right);
        }
}

template<class ItemType>
bool TreeType<ItemType>::DeleteItem(ItemType item)
{
   return Delete(root, item);
}
template<class ItemType>
void TreeType <ItemType>::FindMin(TreeNode <ItemType>* root, ItemType &data)
{
        if(root->left == NULL){
                this.data = root->data;
        }
        else{
                FindMin(root->left, data);
        }
}

template<class ItemType>
bool TreeType<ItemType>::Delete(TreeNode<ItemType>*& root, ItemType item)
{
        if(root->left != NULL){
                Delete(root->left, root->left->data);
        }
        else if(root->right !=NULL){
                Delete(root->right,root->right->data);
        }
        else{
                root = NULL;
        }
}
template <class ItemType>
void TreeType<ItemType>::moveCurrentLeft(){
	if(current->left !=NULL)
		current = current->left;
}

template <class ItemType>
void TreeType<ItemType>::moveCurrentRight(){
	if(current->right != NULL)
		current = current->right;

}
template <class ItemType>
void TreeType<ItemType>::setCurrentToRoot(){
	if(root != NULL)
		current = root;
}
#endif
