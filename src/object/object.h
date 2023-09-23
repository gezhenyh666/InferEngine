#ifndef INFER_ENGINE_OBJECT_H_
#define INFER_ENGINE_OBJECT_H_

#include "object_define.h"

class Object {
 public:

  Object();
  virtual ISTATUS Init();
  virtual ISTATUS Run() = 0;
  virtual ISTATUS Deinit();
  virtual ~Object();
};
#endif //INFER_ENGINE_OBJECT_H_

