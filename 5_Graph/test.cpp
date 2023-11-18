#include "0_VeryBasicGraph.hpp"

int main() {

  BasicDirectedGraph<std::string> myGraph;
  myGraph.GetFirstVertex()->value_ = "first";

  myGraph.PlaceNewVertexAfterExistingVertex(myGraph.GetFirstVertex())->value_ = "first_first";

  myGraph.PlaceNewVertexAfterExistingVertex(myGraph.GetFirstVertex())->value_ = "first_second";

  Vertex<std::string> * handler_ = myGraph.PlaceNewVertexAfterExistingVertex(myGraph.GetFirstVertex()->edges_[0]);
  handler_->value_ = "first_first_first";

  //I create a edgge from the Vertex pointed by hangler to the first one, making it a circular
  myGraph.CreateEdgeFromAtoB(handler_,myGraph.GetFirstVertex());
  std::cout << "size of my graph = " << myGraph.GetSize() << std::endl;

  myGraph.TraverseAndOutputDummyAndIncomplete();

}