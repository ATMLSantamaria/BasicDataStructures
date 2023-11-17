#ifndef DATA_STRUCTURES_BASICDATASTRUCTURES__
#define DATA_STRUCTURES_BASICDATASTRUCTURES_BASICSTACK_

#include <stack>
#include <iostream>
#include <concepts>
#include <string>


//Fast implementation of a Max Stack, a Stack that knows it maximum value.

//Max Stack is a template class. It use concepts to imposse that the operator< should be implemented

//First I create the concept class
template <typename T>
concept LessThanComparable = requires(const T& a, const T& b) {
    { a < b } -> std::convertible_to<bool>;
};
// template <typename T>
// concept LessThanComparable = requires(const T& b) {
//     { b < b } -> std::convertible_to<bool>;
// };

//This concept impose that any Content used here need tohave implemented the operator<
template<LessThanComparable Content>
class MaxStack { 
 public:
  MaxStack() {
    size_ = 0;
  }

  ~MaxStack() {

  }

  void Push(Content new_element_) {
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

  Content Pop () {
    --size_;
    secondary_stack_.pop();
    Content tmp = main_stack_.top();
    main_stack_.pop();
    return tmp;

  }

  const Content & Peek() {
    return main_stack_.top();
  }

  Content & Max() {
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
  std::stack<Content> main_stack_;
  std::stack<Content> secondary_stack_;
  size_t size_;
};



#endif