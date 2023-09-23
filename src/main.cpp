#include <iostream>
#include "graph_ctl/graphic/graphic.h"
#include "graph_ctl/graph_node/graph_node.h"

using namespace std;

void TestFunc() {
    Graphic* graphic = new Graphic();

   
    GraphNode* a = new GraphNode();
    GraphNode* b = new GraphNode();
    GraphNode* c = new GraphNode();
    GraphNode* d = new GraphNode();

    b->AddDependNode(a);
    c->AddDependNode(b);
    c->AddDependNode(a);
    d->AddDependNode(c);

    graphic->AddNode(a);
    graphic->AddNode(b);
    graphic->AddNode(c);
    graphic->AddNode(d);

    graphic->Run();
}

int main()
{
    std::cout << "Hello Infer Engine!" << std::endl;

    TestFunc();

    return 0;
}
