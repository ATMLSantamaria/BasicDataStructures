#include <list>
#include <iostream>
#include <string>
#include <memory>


//Basic implementation of a Queue using a List

//The elements in the Queue will be of type QueueItems

//To enforce ownership I will use a unique pointer

//This QueueItem take ownership of the Content Item you pass to it
template<typename Content>
class Node {
 public:

  Node() {
    value_handler_ = nullptr;
  }
  Node(std::unique_ptr<Content> target) {
    value_handler_ = std::move(target);

  }
  ~Node() {

  }

  Content * GetHandler() {
    return value_handler_;
  }
 private:
 std::unique_ptr<Content> value_handler_;
 Node<Content> next_;
 Node<Content> prev_;

};

template<typename Content>
class DLinkedList {
 public:
  DLinkedList() {

    

  }
  ~DLinkedList() {

  }

  Node<content> * GetHead() {
    return head_;
  }

  Node<content> * GetTail() {
    return tail_;
  }

 private:
  Node<Content> * head_;
  Node<content> * tail_

};

template<typename Content>
class Queue {
 public:
  Queue() {

  }
  ~Queue() {

  }

  void Insert(Content target) {



  }



}




int main() {

}