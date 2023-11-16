#ifndef DATASTRUCTURE_BASIC_DATASTRUCTURE_BASICHASHTABLE_
#define DATASTRUCTURE_BASIC_DATASTRUCTURE_BASICHASHTABLE_

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <cmath>
#include <cassert>

//Very Basic Implementation of a Hash Table using a std::list and a std::vector
//AFor the Hash Function I decided to use the one in the standard library

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
    number_of_items_=0;
    array_capacity_ = 12;
    items_dynamic_array_.resize(array_capacity_);
    number_of_rehashing_=0;
  }

  HashTable(uint64_t len):array_capacity_(len){
  }

  double ComputeLoadFactor() {
    double load_factor = static_cast<float>(number_of_items_ + 1) / static_cast<float>(array_capacity_);
    return load_factor;
  }

  uint64_t HashIndexComputation(std::string key,uint64_t array_capacity) {
    
    std::hash<std::string> hasher_;
    auto hash_result_ = hasher_(key);
    uint64_t index_hash  = hash_result_ % array_capacity;
    return index_hash;
  }


  void ReHashing() {
    ++number_of_rehashing_;
    //Basically I need a new vector with double capacity, and copy all elements there.
    uint64_t new_capacity_ = array_capacity_ * 2;

    std::vector<std::list<HashItem<std::string>>> tmp_vector_(new_capacity_);

    for (auto &i : items_dynamic_array_) {
      for (auto &j : i){
        uint64_t element_index_ = HashIndexComputation(j.key_,new_capacity_);
        tmp_vector_[element_index_].push_back(j);
      }
    }

    items_dynamic_array_ = std::move(tmp_vector_);
    array_capacity_ = new_capacity_;

  }

  void Insert(HashItem<Content> target) {
    if (ComputeLoadFactor() > 0.75) {
      ReHashing();
    }

    uint64_t element_index_ = HashIndexComputation(target.key_,array_capacity_);

    items_dynamic_array_[element_index_].push_back(target);

    ++number_of_items_;

  }


  Content LookUp(std::string key) {
    //First. Retrive information about the index where this Item is stored
    uint64_t index = HashIndexComputation(key,array_capacity_);

    //Second, search the key in the list
    for (auto it = items_dynamic_array_[index].begin();it != items_dynamic_array_[index].end();++it) {
      if(it->key_ == key) {
        return it->value_;
      }
    }
    //This will only work if Content has the adecuate costructor that accept a string but let asssume it has it.
    Content result = "not found";
    return result;
  }

  void Remove(std::string key) {
    //First. Retrieve index
    uint64_t index = HashIndexComputation(key,array_capacity_);
    //Second,search and remove in the list
    for (auto it = items_dynamic_array_[index].begin();it != items_dynamic_array_[index].end();) {
      if(it->key_ == key) {
        it = items_dynamic_array_[index].erase(it);
      } else {
        ++it;
      }
    }
    --number_of_items_;
    
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

  ~HashTable() {
  }

uint32_t array_capacity_;
uint64_t number_of_items_;
uint64_t number_of_rehashing_;

std::vector<std::list<HashItem<Content>>> items_dynamic_array_;


};



#endif


