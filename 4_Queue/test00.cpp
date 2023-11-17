#include "00_ReallyBasicQueue.hpp"

#include "1_QueuePlusList.hpp"

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

  
  
  QueuePlusList<int> myQueue;

  assert(myQueue.GetSize() == 0);
  for (uint64_t i = 0;i < 10;++i) {
    myQueue.PushBack(std::move((i)));
  }
  assert(myQueue.GetSize() == 10);
  assert(myQueue.PopFront() == 0);
  assert(myQueue.GetSize() == 9);
  assert(myQueue.PeekFront() == 1);
}