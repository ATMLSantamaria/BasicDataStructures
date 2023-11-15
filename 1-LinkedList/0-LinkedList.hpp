#ifndef DATASTRUCTURE_BASIC_DATASTRUCTURE_
#define DATASTRUCTURE_BASIC_DATASTRUCTURE_

#include <iostream>
#include <string>

//Basic Version of a Linked List


template<typename Content>
struct Node {

 Node(Content value){
    value_=value;
 }
 Node(){}

 Content value_;

 Node<Content> * next_;

 Node<Content> * prev_;

};

template<typename Content>
class SinglyLinkedList {

 public:
  SinglyLinkedList() {

    head_ = new Node<Content>();
    tail_ = new Node<Content>();

    head_->prev_=nullptr;
    head_->next_=tail_;

    tail_->prev_=head_;
    tail_->next=nullptr;

    len_ = 2;

  }

  SinglyLinkedList(int64_t len):len_(len) {

    head_ = new Node<Content>();
    head_->prev_ = nullptr;

    tail_ = new Node<Content>();
    tail_->next_ = nullptr;

    Node<Content> * last_created_node_ = head_;

    //We want to create len -2 Nodes in this loop, the number decide by the user - Tail adn HEad
    for (uint64_t i = 0;i<len-2;++i) {
        
        //Create a Node
        Node<Content> * next_node_ = new Node<Content>();

        //Update next in the previous node so that is point to the recently created Node
        last_created_node_->next_ = next_node_;

        //Point prev_ of the current Node to the previous node
        next_node_->prev_ = last_created_node_;

        //Point next_ of the current Node to nullptr
        next_node_->next_ = nullptr;

        //Store current Node as the last created
        last_created_node_ = next_node_;

    }

    tail_->prev_ =  last_created_node_;
    last_created_node_->next_ = tail_;
    
  }

  Node<Content> * GetHead() {
   return head_;
  }

  Node<Content> * GetTail() {
   return tail_;
  }



  void InsertAtEnd(Node<Content> * node) {

   //Update properties of node to integrate it in the LL
   node->prev_ = tail_;
   node->next_ = nullptr;

   //Update properties of the previous head
   tail_->next_ = node;
   
   //Update the LL property itself
   tail_ = node;

  //Update len_
  ++len_;

  }

  void InsertAtBeginning(Node<Content> * node) {

    //Update properties of node to integrate it in the LL
    node->prev_ = nullptr;
    node->next_ = head_;

    //Update properties of the previous head
    head_->prev_ = node;

    //Update the LL property itself
    head_ = node;

    //Update len_
    ++len_;

  }

  void InsertAfterNode(Node<Content> * target_node, Node<Content> * node_to_insert) {
   
   //Update properties of node to integrate it in the LL

   node_to_insert->prev_ = target_node;
   node_to_insert->next_ = target_node->next_;

   //Update properties of the previous nodes
   
   target_node->next_->prev_ = node_to_insert;
   target_node->next_ = node_to_insert;
   
   //Update len_

   ++len_;
  }

  // Content should support == comparison or this will not compile.
  
  Node<Content> * SearchNodeByContent (Content target_to_search) {

   Node<Content> * current_node_ = head_;

   for (uint64_t i = 0; i < len_;++i) {

    if (target_to_search == current_node_->value_) {
      return current_node_;
    }

    current_node_ = current_node_->next_;
     
   }

   return nullptr;

  }

  int64_t SearchNodeIndexByContent(Content target_to_search) {

    Node<Content> * current_node_ = head_;

    for (uint64_t i = 0;i < len_;++i) {

     if (target_to_search == current_node_->value_) {
      return i;
     }

     current_node_ = current_node_->next_;

    }

    return -1;
  }

  int64_t SearchNodeIndexByNode(Node<Content> * target_to_search) {

    Node<Content> * current_node_ = head_;
    
    for (uint64_t i = 0; i < len_;++i) {

      if(target_to_search == current_node_) {
        return i;
      }

      current_node_ = current_node_->next_;

    }

    return -1;
  }

  int64_t SearchNodeIndexByNodeVersionTwo(Node<Content> * target_to_search) {
   Node<Content> * current_node_ = head_;

   int64_t counter = 0;

   while(current_node_->next_ != nullptr) {

    if(current_node_ == target_to_search) {
      return counter;
    }

    current_node_ = current_node_->next_;
    ++counter;

   }
   //Case when the searched node is the tail
   if (current_node_ == target_to_search)
    return counter;

  }  

  //Content class need to have onverload operator<<
  void TraverseAndPrint() {

    Node<Content> * current_node_ = head_; 

    std::cout << "||  ";
    //Print all nodes except the tail
    while(current_node_->next_ != nullptr) {
      std::cout << current_node_->value_ << "  ";
      current_node_ = current_node_->next_;
    }

    //Print tail
    std::cout << current_node_->value_;
    std::cout << "  ||\n";
  }

  void EraseNode(Node<Content> * target_node) {
    
    //Edge cases of Head and Tail
    if (target_node == GetHead()) {

     target_node->next_->prev_ = nullptr;

    } else if (target_node == GetTail()) {

      target_node->prev_->next_ = nullptr;

    } else {

     //Rearrange the previous element to point to the next, and the next to the prev
     target_node->next_->prev_=target_node->prev_;
     target_node->prev_->next_=target_node->next_; 

    }

    //This depence of the ownership. But in principle I assume that the ownership of the node belongs to the LinkedList so it is deleted here
    delete target_node;
  }

  void EraseAtIndex(uint64_t target_index) {
    Node<Content> * current_node_=head_;
    for (uint64_t i = 0; i < target_index;++i) {
      current_node_ = current_node_->next_;
    }
    EraseNode(current_node_);

  }


 private:

  Node<Content> * head_;

  Node<Content> * tail_;

  uint64_t len_;

};


#endif

