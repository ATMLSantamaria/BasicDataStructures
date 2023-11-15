
#include "0-LinkedList.hpp"




int main(){

    SinglyLinkedList<std::string> my_linked_list(5);
    Node<std::string> * current_node = my_linked_list.GetHead();
    for (int i = 0;i<5;++i) {
      current_node->value_=std::to_string(i);
      current_node = current_node->next_;
    }

    my_linked_list.GetHead()->value_ = "head";
    //my_linked_list.GetHead()->next_->value_="2";

    my_linked_list.GetTail()->value_ = "tail";

    Node<std::string> * new_node = new Node<std::string>("new head");

    my_linked_list.InsertAtBeginning(new_node);

    std::cout << my_linked_list.GetHead()->value_ << std::endl;

    Node<std::string> * found_node = my_linked_list.SearchNodeByContent("head");

    if (found_node != nullptr)
      std::cout << found_node->value_ << std::endl;

    int64_t position = my_linked_list.SearchNodeIndexByNode(my_linked_list.GetTail());

    std::cout << "Position of the Node is: " << position << std::endl;

    position = my_linked_list.SearchNodeIndexByNodeVersionTwo(my_linked_list.GetTail());

    std::cout << "Position of the Node using version 2 is: " << position << std::endl;

    position = my_linked_list.SearchNodeIndexByContent("tail");

    std::cout << "Position of the Node using  SeachNodeIndexByTail is: " << position << std::endl;


    my_linked_list.TraverseAndPrint();

    my_linked_list.EraseAtIndex(my_linked_list.SearchNodeIndexByContent("tail"));

    my_linked_list.TraverseAndPrint();




}
