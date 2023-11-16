#include "0_BasicHashTable.hpp"

int main() {

  

  HashTable<std::string> myHashTable;
  std::vector<std::string> vectorAlphabet = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};

  for (auto i : vectorAlphabet) {
    HashItem<std::string> tmp;
    tmp.key_ = i;
    tmp.value_ = std::toupper(i[0]); 

    myHashTable.Insert(tmp);
  }

  //Check the Search Function
  std::cout << "LookUp key h gives value = " << myHashTable.LookUp("h") <<std::endl;
  assert(myHashTable.LookUp("h") == "H");

  //Check Erase Function
  myHashTable.Remove("h");
  std::cout << "LookUp key h gives value = " << myHashTable.LookUp("h") <<std::endl;
  assert(myHashTable.LookUp("h") == "not found");



  // std::cout << "number of ReHashing = " << myHashTable.number_of_rehashing_ <<std::endl;
}