#include "0_VeryBasicBTree.hpp"
#include <sstream>


int main() {

  BinaryTree<int64_t> myTree;

  BinaryNode<int64_t> * root = myTree.GetRoot();
  assert(root == nullptr);

  for (uint64_t i = 0; i < 12;++i) {
    myTree.Insert(i);
  }

  for (int64_t i = -1; i > -12;--i) {
    myTree.Insert(i);
  }

  //Now redirect the output of the displayTree to test it
  std::stringstream buffer;

  // Redirect cout to the buffer
  std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());  
  myTree.displayTree();

  // Restore the original cout buffer
  std::cout.rdbuf(old);

  std::string output = buffer.str();
  assert(output == "11 10 9 8 7 6 5 4 3 2 1 0 -1 -2 -3 -4 -5 -6 -7 -8 -9 -10 -11 ");

}