
#include "00_ReallyBasicQueue.hpp"

int main() {

  Queue my_queue_;

  std::vector<std::string> my_dogs_ = {"Turco","Terry","Lyra","Frodo","Arwen","Orion","Thor","Rocky","Turco"};

  for (auto i : my_dogs_) {
    my_queue_.Push(i);
  }

  assert(my_queue_.Front() == "Turco");
  assert(my_queue_.Back() == "Turco");

  my_queue_.Pop();

  assert(my_queue_.Front() == "Terry" );


}