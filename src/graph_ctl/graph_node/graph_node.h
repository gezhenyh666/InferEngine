#ifndef INFER_ENGINE_GRAPHCTL_GRAPHNODE_H_
#define INFER_ENGINE_GRAPHCTL_GRAPHNODE_H_

#include <list>
#include "../../object/object.h"

class GraphNode : public Object {
 public:
  GraphNode();
  ISTATUS Init() override;
  ISTATUS Run() override;
  ISTATUS Deinit() override;
  ~GraphNode();

 public:
  std::list<GraphNode*>& GetRunBeforeList();
  ISTATUS AddDependNode(GraphNode* node);
  ISTATUS AfterRun();

  bool EnableRun() const; //依赖的内容是否被执行完成
  bool IsExecuted() const;

 protected:
  ISTATUS AddDependence(GraphNode* node);
  ISTATUS AddRunBefore(GraphNode* node);

 private:
  bool is_executed_;  //节点是否被执行
  std::list<GraphNode*> depended_nodes_; //依赖的节点
  std::list<GraphNode*> run_before_; //被依赖的节点
  int left_depend_;
};












#endif //INFER_ENGINE_GRAPHCTL_GRAPHNODE_H_
