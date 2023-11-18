#ifndef DATA_STRUCTURES_BASICDATASTRUCTURES_GRAPH_VERYBASICGRAPH_
#define DATA_STRUCTURES_BASICDATASTRUCTURES_GRAPH_VERYBASICGRAPH_

#include <vector>
#include <list>
#include <string>
#include <iostream>
#include <cassert>


// First approach to a Graph based in an adjancency list. I will use a std::list for this purpose. 
// I use a vector to store the edges of each node.
// For simplicity I will use raw pointers for the edges

//The graph will be created with one root vertex and the number of Vertex that we choose

template<typename Content>
struct Vertex {
  uint64_t id_;
  Content value_;
  std::vector<Vertex *> edges_;
  uint64_t depth_ = 0;
};


template<typename Content>
class BasicDirectedGraph {
 public:
  BasicDirectedGraph() {
    tracking_latest_id_of_vertices_ = 0;
    size_ = 0;
    first_vertex_ = CreateVertex();
    max_depth_ = 0;
  }

  //Allocate a new vertex and place it into the graph. Return the memory address of the Vertex
  Vertex<Content> * CreateVertex() {
    Vertex<Content> * new_vertex_ = new Vertex<Content>;

    new_vertex_->id_ = tracking_latest_id_of_vertices_++;
    size_++;
    
    graph_.push_back(new_vertex_);
    return new_vertex_;
  }

  void SetValueInToVertex(Vertex<Content> * target, Content & value) {
    target->value_ = value;
  }

  //Allocate a new vertex and place it into the edge list of an existing one
  Vertex<Content> * PlaceNewVertexAfterExistingVertex(Vertex<Content> * parent_vertex_) {
    Vertex<Content> * new_vertex_ = CreateVertex();
    parent_vertex_->edges_.push_back(new_vertex_);
    new_vertex_->depth_ = parent_vertex_->depth_ + 1;

    if (new_vertex_->depth_ > max_depth_) {
      max_depth_ = new_vertex_->depth_;
    }

    return new_vertex_;
  }

  void CreateEdgeFromAtoB(Vertex<Content> * A,Vertex<Content> * B) {
    A->edges_.push_back(B);
    B->depth_ = A->depth_ + 1;
    if (A->depth_ > max_depth_) {
      max_depth_ = A->depth_;
    }

  }

  Vertex<Content> * GetFirstVertex() {
    return first_vertex_;
  }

  size_t GetSize() {
    return size_;
  }

  
  void TraverseAndOutputDummyAndIncomplete() {
    Vertex<Content> * temporal_handler_ = first_vertex_;
    //+1 because I want the circular nature to be clearly expressed
    for (int64_t i = max_depth_+1;i >= 0;--i) {
      std::cout << temporal_handler_->value_ << std::endl;
      temporal_handler_ = temporal_handler_->edges_[0];
    }
  }

 private:
  size_t size_;
  std::list<Vertex<Content>*> graph_;
  uint64_t tracking_latest_id_of_vertices_;
  Vertex<Content> * first_vertex_;
  uint64_t max_depth_;
};




#endif



