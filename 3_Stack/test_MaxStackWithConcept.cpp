#include "2_MaxStackWithConceps.hpp"


int main() {

  MaxStack<int> a;

  MaxStack<std::string> b;

  //local class wihout such operator
  class Local {};

  // MaxStack<Local> c; This is not allowed to compile

  class LocalComparable {
   public:
   bool operator<(const LocalComparable& b) const{
    return true;
   }
  };
  //Here the concept is fullfilled with a Dummy method
  MaxStack<LocalComparable> c;



}