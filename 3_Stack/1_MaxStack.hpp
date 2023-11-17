#ifndef DATA_STRUCTURES_BASICDATASTRUCTURES_MAXSTACK_
#define DATA_STRUCTURES_BASICDATASTRUCTURES_MAXSTACK_

#include <stack>
#include <iostream>


//Fast implementation of a Max Stack, a Stack that knows it maximum value.

//In this file the stack class will not be a template class due to the need of a overload operator< 

//In c++20 is trivial to impose such condicion using requires 

//I use std::stack


//Time Complexiy for Push, Pop, Peek and MAx is O(1). Space Complexity is O(2*n) since is need double space to be stored with respect to normal Stack
class MaxStack { 
 public:
  MaxStack() {
    size_ = 0;
  }

  ~MaxStack() {

  }

  void Push(int new_element_) {
    main_stack_.push(new_element_);
    if (size_== 0) {
      secondary_stack_.push(new_element_);
      ++size_;
      return;
    }
    if (new_element_ > secondary_stack_.top()) {
      secondary_stack_.push(new_element_);
    } else {
      secondary_stack_.push(secondary_stack_.top());
    }
    ++size_;
  }

  int Pop () {
    --size_;
    secondary_stack_.pop();
    int tmp = main_stack_.top();
    main_stack_.pop();
    return tmp;

  }

  const int & Peek() {
    return main_stack_.top();
  }

  int Max() {
    if (size_== 0) {
      throw "stack is empty\n";
    }
    return secondary_stack_.top();
  }

  void PrintBothStack() {
    std::cout << "|   " << "Main Stack" << "   |   " << "Max Stack" << "   |" << std::endl;
    for (uint64_t i = size_;i > 0;i--) {
      std::cout << "|       " << main_stack_.top() << "        |       " << secondary_stack_.top() << "       |" << std::endl;
      main_stack_.pop();
      secondary_stack_.pop();
      --size_;
    }
  }

  void PrintOneLine() {
    std::cout << "|   " << "Main Stack" << "   |   " << "Max Stack" << "   |" << std::endl;
    std::cout << "|       " << main_stack_.top() << "        |       " << secondary_stack_.top() << "       |" << std::endl;
  }

  int Size() {
    return size_;
  }

 private:
  std::stack<int> main_stack_;
  std::stack<int> secondary_stack_;
  size_t size_;
};

#endif