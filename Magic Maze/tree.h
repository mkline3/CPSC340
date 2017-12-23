//Matt Kline
#ifndef TREE
#define TREE
#include <fstream>
#include <iostream>
using namespace std;
#include "Treend.h"
template<class ItemType>
class TreeType
{

   public:
      TreeType();
      TreeType (const TreeType &original){CopyTree(root, original.root);}
      void operator=(TreeType &orginalTree);
      bool Search(ItemType &value);
      void Insert(ItemType value);
      void Print() ;
     ~TreeType();
      bool isEmpty() {return root==0;}
      bool DeleteItem(ItemType value);
      ItemType getCurrentData(){return current ->data;}
      void moveCurrentLeft();
      void moveCurrentRight();
      void setCurrentToRoot();


   private:
      TreeNode<ItemType>* root;
      TreeNode<ItemType>* current;
      void CopyTree(TreeNode<ItemType>*& copy, const TreeNode<ItemType>* original);

      bool BinarySearch(TreeNode<ItemType>* root, ItemType &value);
      bool InsertItem(TreeNode<ItemType>*&  root, ItemType value);
      void PrintTree(TreeNode<ItemType>* root);
      void Destroy(TreeNode<ItemType>*& root);
      bool Delete(TreeNode<ItemType>*& root, ItemType);
      void FindMin(TreeNode<ItemType>* root, ItemType &data);
};

#include "tree.cpp"
#endif
