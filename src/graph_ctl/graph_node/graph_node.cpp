#include <iostream>
#include "graph_node.h"

GraphNode::GraphNode() {
    this->left_depend_ = 0;
    this->is_executed_ = false;
}

GraphNode::~GraphNode() = default;

ISTATUS GraphNode::Init() {

}

ISTATUS GraphNode::Deinit() {

}

ISTATUS GraphNode::Run() {
    std::cout << "Run node" << std::endl;
}

ISTATUS GraphNode::AddDependence(GraphNode* node) {
    this->depended_nodes_.push_back(node);
}

ISTATUS GraphNode::AddDependNode(GraphNode* node) {
    this->AddDependence(node);
    node->AddRunBefore(this);
}

ISTATUS GraphNode::AddRunBefore(GraphNode* node) {
    this->run_before_.push_back(node);
    node->left_depend_++;
}

bool GraphNode::EnableRun() const {
    return this->left_depend_ == 0;
}

bool GraphNode::IsExecuted() const{
    return this->is_executed_;
}

ISTATUS GraphNode::AfterRun() {
    for (GraphNode *node : this->run_before_) {
        node->left_depend_--;
    }
    this->is_executed_ = true;
}