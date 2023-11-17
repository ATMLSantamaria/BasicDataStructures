#ifndef DATA_STRUCTURES_BASICDATASTRUCTURES_QUEUE_REALLYBASICQUEUE_
#define DATA_STRUCTURES_BASICDATASTRUCTURES_QUEUE_REALLYBASICQUEUE_

#include <list>
#include <iostream>
#include <string>
#include <cassert>
#include <vector>





//Basic implementation of a Queue for std::strings using a List

class Queue {
 public:
  Queue() {
    size_= 0;
  }
  ~Queue() {}

  //Operaciones

  //Push element into the back queue. Also called enqueuing
  void Push(std::string target) {
    queue_list_.push_back(target);
    ++size_;
  }

  //Remove an element from the front of the queue. Also called dequeuing
  std::string Pop() {
    if (size_==0) {
      return "empty queue\n";
    }
    std::string tmp_string = queue_list_.front();
    queue_list_.pop_front();
    --size_;
    return tmp_string;
  }

  //Returns a read reference of an element in the front of the queue
  const std::string & Front(){
    return queue_list_.front();
  }

  //Returns a read reference of an element in the back of the queue
  const std::string & Back(){
    return queue_list_.back();
  }

  //Return size of the queue
  uint64_t Size() {
    return size_;
  }

  //Returns if the queue is empty
  bool Empty() {
    return queue_list_.empty();
  }


 private:
 std::list<std::string> queue_list_;
 uint64_t size_;

};

#endif