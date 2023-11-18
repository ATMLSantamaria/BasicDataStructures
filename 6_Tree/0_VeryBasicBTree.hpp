#ifndef DATA_STRUCTURES_BASICDATASTRUCTURES_TREE_VERYBASICTREE_
#define DATA_STRUCTURES_BASICDATASTRUCTURES_TREE_VERYBASICTREE_

#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <cassert>


template<typename Content>
struct BinaryNode {

  BinaryNode(Content value) : value_(value) {
    children_.first = nullptr;
    children_.second = nullptr;
  }
  ~BinaryNode() {
    if (children_.first != nullptr) {
      delete children_.first ;
    }
    if (children_.second != nullptr) {
      delete children_.second;
    }
  }

  //Incomplete types allowed since C++17 for std::vector, std::list, and std::forward_list
  //They are still not allowed in pairs.
  //So   std::pair<BinaryNode , BinaryNode > it is illegal
  //But   std::pair<BinaryNode *, BinaryNode * >
  std::pair<BinaryNode<Content> *, BinaryNode<Content> *> children_;

  //The pais is totally unnecesary, although it gives us the alreadz implemented swap functionality

  Content value_;

};

template<typename Content>
class BinaryTree {
 public:

  BinaryTree() {
    root_node_ = nullptr;
  }

  ~BinaryTree() {
    //This destroy the root and initiate the recursive destruction of childs
    delete root_node_;
  }

  void Insert(Content value_) {
    root_node_ = Insert(root_node_,value_);

  }

  void displayTree() {
    displayTree(root_node_);
  }

  BinaryNode<Content> *  Insert(BinaryNode<Content> * root,Content & value_) {
    if(root == nullptr){
      return new BinaryNode<Content>(value_);
    }

    if (value_ >= root->value_ ) {
      root->children_.first = Insert(root->children_.first,value_);
    } else {
      root->children_.second = Insert(root->children_.second,value_);
    }

    return root;
  }

  BinaryNode<Content> * GetRoot() {
    return root_node_;
  }

 private:

  void displayTree(BinaryNode<Content>* root) {
    if (root != nullptr) {
      displayTree(root->children_.first);  // Display left child
      std::cout << root->value_ << " ";    // Display current node
      displayTree(root->children_.second); // Display right child
    }
  }
  
  BinaryNode<Content> * root_node_;
  uint64_t depth_;
  
};

#endif
