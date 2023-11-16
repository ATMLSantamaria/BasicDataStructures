#ifndef DATA_STRUCTURES_BASICDATASTRUCTURES_
#define DATA_STRUCTURES_BASICDATASTRUCTURES_

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <cmath>

//Very Basic Implementation of a Hash Table using a std::list and a std::vector
//Also a very simple hash function -> Polynomial Rolling Algorithm
//hash = x₁*A⁰ + x₂*Aⁱ + x₃*A² ... xₙ*Aⁿ⁻ⁱ

//Insert
//Remove
//Lookup

//Prime number close to the number of characters in the alphabet
const int PRIME_CONST = 31;

template<typename Content>
struct HashItem {
  //Constructor 1
  HashItem(){
  }

  HashItem(const HashItem & target) {
    key_=target.key_;
    value_=target.value_;

  }

  std::string key_;
  Content value_;
};

template<typename Content>
class HashTable {
 public:
  HashTable(){
    //Following Java example I set the initial lenght of the underlying array to 12
    array_capacity_ = 12;
    items_dynamic_array_.resize(12);
  }

  HashTable(uint64_t len):array_capacity_(len){
  }

  double ComputeLoadFactor() {
    double load_factor = static_cast<float>(number_of_items_ = 1) / static_cast<float>(array_capacity_);
    return load_factor;
  }

  uint64_t IndexComputation(std::string key,uint64_t array_len) {

    uint64_t index = 0;
    index = HashFunction(key) % array_len;
    std::cout << HashFunction(key) << std::endl;
    std::cout << "index result = " << index << std::endl;

    return index;

  }

  uint64_t HashFunction(std::string & key) {
    //This function need improvement

    //Polynomial Rolling Algorithm 
    int hashCode = 0;
    for (uint64_t i = 0; i < key.size(); i++) {
      hashCode += key[i] * pow(PRIME_CONST, i);
    }
    return hashCode;
  }

  void ReHashing() {
  }

  void Insert(HashItem<Content> target) {

    /*     if (compute_load_factor() > 0.5d) {

    rehashing();
    } */

    int element_index_ = IndexComputation(target.key_,array_capacity_);

    items_dynamic_array_[element_index_].push_back(target);

  }


  HashItem<Content> Search(std::string key) {
  } 

  void PrintHashTable(){
    int counter = 0;
    for (auto i : items_dynamic_array_){
      std::cout << "index " <<counter << ": ";
      for (auto j : i) {
        
        std::cout << j.value_ << " -> ";
      }
      counter++;
      std::cout << std::endl;
    }
  }

uint32_t array_capacity_;
uint64_t number_of_items_;

std::vector<std::list<HashItem<Content>>> items_dynamic_array_;


};

int main() {
  HashItem<std::string> madrid;
  std::string a="9122054442492";
  madrid.value_=a;
  madrid.key_="c";

  HashItem<std::string> mobilHanna;
  std::string b="45644534432423";
  mobilHanna.value_=b;
  mobilHanna.key_="h"; 

  HashItem<std::string> papa;
  std::string c="676670545465";
  papa.value_=c;
  papa.key_="p"; 

  HashItem<std::string> mama;
  std::string d="646545098543";
  mama.value_=d;
  mama.key_="m"; 

  HashTable<std::string> myHashTable;

  myHashTable.Insert(madrid);
  myHashTable.Insert(mobilHanna);
  myHashTable.Insert(mama);
  myHashTable.Insert(papa);

  myHashTable.PrintHashTable();

}

#endif


