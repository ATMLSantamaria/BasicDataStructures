
#include "0_BasicStack.hpp"
#include <cassert>

template<typename Content>
void MethodToAddSomethingTemporal(BasicStack<Content> & target) {
  std::string tmp_string("I will remain");
  target.Push(tmp_string);
}

template<typename Content>
void AddSomethingEvenMoreTemporal(BasicStack<Content> & target) {
  int i = 99;
  target.Push(std::move(std::to_string(i)));
}


int main() {
  BasicStack<std::string> stack_object;

  MethodToAddSomethingTemporal<std::string>(stack_object);

  assert(stack_object.Peek() == "I will remain");
  assert(stack_object.Pop() == "I will remain");
  assert(stack_object.Size() == 0);


  AddSomethingEvenMoreTemporal(stack_object);
  assert(stack_object.Pop() == "99");
  
  for (uint64_t i = 0; i < 10; ++i) {
    stack_object.Push(std::move(std::to_string(i)));
  }

  assert(stack_object.Size() == 10);
  assert(stack_object.Pop() == "9");
  assert(stack_object.Size() == 9);

  const std::string * check_pointer = stack_object.Search("8");

  assert(*check_pointer == "8");

}