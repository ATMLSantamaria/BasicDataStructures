#include "1_MaxStack.hpp"


int main() {
  MaxStack MaxStack;

  MaxStack.Push(1);
  MaxStack.Push(5);
  MaxStack.Push(3);
  MaxStack.Push(9);
  MaxStack.Push(2);
  MaxStack.Push(7);
  MaxStack.Push(1);

  MaxStack.PrintBothStack();

  MaxStack.Push(1);
  MaxStack.Push(5);
  MaxStack.Push(3);
  MaxStack.Push(9);
  MaxStack.Push(2);
  MaxStack.Push(7);
  MaxStack.Push(1);

  while(MaxStack.Size()>0) {
    std::cout << "Max value is " << MaxStack.Max() << std::endl;

    std::cout << "Now, " << MaxStack.Pop() << " has been popped\n";
  }

  std::cout << "Now, stack is empty\n";


}