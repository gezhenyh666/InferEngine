#ifndef INFERENGINE_GRAPHCTL_GRAPHIC_H_
#define INFERENGINE_GRAPHCTL_GRAPHIC_H_

#include <queue>
#include <list>

#include "../../object/object.h"
#include "../graph_node/graph_node.h"

class Graphic : public Object {
 public:
  Graphic();
  ISTATUS Init() override;
  ISTATUS Run() override;
  ISTATUS Deinit() override;
  ~Graphic() override;

 public:
  ISTATUS AddNode(GraphNode* node);

 private:
  std::queue<GraphNode*> queue_;
  std::list<GraphNode*> nodes_;
};

#endif //INFERENGINE_GRAPHCTL_GRAPHIC_H_
