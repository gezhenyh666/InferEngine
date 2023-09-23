#include "graphic.h"

Graphic::~Graphic() = default;
Graphic::Graphic() = default;

ISTATUS Graphic::Init() {

}

ISTATUS Graphic::Deinit() {

}

ISTATUS Graphic::AddNode(GraphNode* node) {
    this->nodes_.push_back(node);
}

ISTATUS Graphic::Run() {
    int worked_size = 0;

    for (GraphNode* node : this->nodes_) {
        if (!node->EnableRun()) {
            continue;
        }
        queue_.push(node);
    } 

   while (!queue_.empty()) {
    GraphNode* node = queue_.front();
    queue_.pop();
    worked_size++;
    node->Run();
    node->AfterRun();
   }
}

