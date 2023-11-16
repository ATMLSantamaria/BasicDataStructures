#ifndef DATA_STRUCTURES_BASICDATASTRUCTURES_BASICSTACK_
#define DATA_STRUCTURES_BASICDATASTRUCTURES_BASICSTACK_

#include <iostream>
#include <string>
#include <vector>


//Basic Stack template class

//Underlying it contains a std::vector

//Push
//Pop
//Peek
//Search


template<typename Content>
class BasicStack {
 public:
  BasicStack() :size_(0){
  }

  BasicStack(const BasicStack & other): stack_(other.stack_),size_(other.size_) {
  }

  ~BasicStack() {
  }

  void Push(Content & new_element) {
    //new element is pass by reference into the method, but then it copied when using push_back. 
    //So even if new element would be temporary this approach would work. Anyway there will be a test for this
    stack_.push_back(new_element);
    ++size_;
  }

  //Push with move semantics
  void Push(Content && new_element) {
    //new element is pass by reference into the method, but then it copied when using push_back. 
    //So even if new element would be temporary this approach would work. Anyway there will be a test for this
    stack_.push_back(new_element);
    ++size_;
  }

  Content Pop() {
    if (size_ == 0) {
     throw "Stack already empty\n";
    }
    --size_;
    Content tmp = stack_.back(); 
    stack_.pop_back();
    return tmp;
  }

  //Let you look but not modify.
  const Content & Peek() {
    return stack_.back();

  }

  //Return a pointer to the first element that is equal to the target.
  const Content * Search (Content & target_searched) {
    for (auto it = stack_.begin();it != stack_.end();++it) {
      if (target_searched == *it) {
        //return the memory address of the element, after dereferencing the it iteratos
        return &(*it);
      }
    }
    return nullptr;
  }

  const Content * Search (Content target_searched) {
  for (auto it = stack_.begin();it != stack_.end();++it) {
    if (target_searched == *it) {
      //return the memory address of the element, after dereferencing the it iteratos
      return &(*it);
    }
  }
    return nullptr;
  }

  //Getter
  uint64_t Size() {
    return size_;
  }

 private:
  std::vector<Content> stack_;
  uint64_t size_; 
};

#endif