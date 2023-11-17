#ifndef DATA_STRUCTURES_BASICDATASTRUCTURES_QUEUE_QUEUEPLUSLIST_
#define DATA_STRUCTURES_BASICDATASTRUCTURES_QUEUE_QUEUEPLUSLIST_

#include <iostream>
#include <memory>
#include <string>
#include <cassert>


// Here the purpose is to implement in this file a queue plus the underlying list.

//Node + DLinkedList + Queue

template<typename Content>
struct Node {
  Node(const Content & value) {
    value_=value;
  }

  //Return read only value
  const Content & GetValue() {
    return value_;
  }

  void SetValue(const Content & value) {
    value_ = value;
  }

  //Return a read/write reference of next_.
  Node * & GetNext() {
    return next_;
  }

  //Return a read/write reference of prev_.
  Node * & GetPrev() {
    return next_;
  }

  private:
  Content value_;
  Node * next_;
  Node * prev_;
};

template<typename Content>
class DoublyLinkedList {
 public:
  DoublyLinkedList() {
    size_=0;
  }

  ~DoublyLinkedList() {

    Node<Content> * tmp;
    Node<Content> * iterator;
    iterator = head_;
    while(iterator != nullptr && size_ != 0) {
      tmp = iterator->GetNext();
      size_--;
      delete iterator;
      iterator = tmp;
    }
  }

  void PushBack(Content & target) {
    if(size_ == 0) {
      CreateHead(target);
      ++size_;
      return;
    } else if ( size_ == 1) {
      CreateTail(target);
      size_++;
      return;
    }

    Node<Content> * tmp_ = new Node<Content>(target);
    tmp_->GetPrev() = tail_;
    tmp_->GetNext() = nullptr;
    tail_ = tmp_;
    size_++;
  }

  void PushFront(Content & target) {
    if(size_ == 0) {
      CreateHead(target);
      ++size_;
      return;
    } else if (size_ == 1) {
      //Allocate space for the new head, make old head the new tail
      Node<Content> * tmp_ = new Node<Content>(target);
      tail_ = head_;
      head_ = tmp_;
      ++size_;
      return;
    }

    Node<Content> * tmp_ = new Node<Content>(target);
    tmp_->GetPrev() = nullptr;
    tmp_->GetNext() = head_;
    head_ = tmp_;
    size_++;
  }

  Content PopBack() {
    Content temporal_content = tail_->GetValue();
    tail_->GetPrev()->GetNext()=nullptr;
    Node<Content> * tmp_ = tail_->GetPrev();
    delete tail_;
    tail_ = tmp_;
    size_--;
    return temporal_content;
  }

  Content PopFront() {
    Content temporal_content = head_->GetValue();
    (head_->GetNext())->GetPrev()=nullptr;
    Node<Content>  * tmp_ = head_->GetNext();
    delete head_;
    head_ = tmp_;
    size_--;
    return temporal_content;
  }

  const Content & GetHeadValue() {
    return head_->GetValue();
  }

  const Content & GetTailValue() {
    return tail_->GetValue();
  }

  //Auxiliary method that should not exist in production code.
  Node<Content> * GetHead() {
    return head_;
  }

  //Auxiliary method that should not exist in production code
  Node<Content> * GetTail() {
    return tail_;
  }

  uint64_t Size()const  {
    return size_;
  }

 private:
  Node<Content> * head_;
  Node<Content> * tail_;
  uint64_t size_;

  //Auxiliary private function to create the FIRST element in List
  void CreateHead(Content & target) {
    head_ = new Node<Content>(target);
    head_->GetNext() = nullptr;
    head_->GetPrev() = nullptr;
  }

  //Auxiliary private function to create the SECOND element in List
  void CreateTail(Content & target) {
    tail_ = new Node<Content>(target);
    tail_->GetPrev() = head_;
    head_->GetNext() = tail_;
  }
};

template<typename Content>
class QueuePlusList {
 public:
  QueuePlusList() :size_(0){
  }

  const Content & PeekFront() {
    return queue_.GetHeadValue();
  }

  const Content & PeekLast() {
    return queue_.GetTailValue();
  }

  Content PopFront() {
    size_--;
    return queue_.PopFront();
  }

  void PushBack(Content && target) {
    queue_.PushBack(target);
    size_++;
  }

  void PushBack(Content & target) {
    queue_.PushBack(target);
    size_++;
  }

  uint64_t GetSize() {
    return size_;
  }

  const DoublyLinkedList<Content> & GetDLL() {
    return queue_;
  }
 private:
  DoublyLinkedList<Content> queue_;
  uint64_t size_;


};


#endif