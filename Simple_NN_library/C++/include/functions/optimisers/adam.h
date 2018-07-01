#ifndef __FUNCTIONS__OPTIMISERS__ADAM_H
#define __FUNCTIONS__OPTIMISERS__ADAM_H
#include <further_maths.h>

struct Adam_variables{
  int iterations;
  float learning_rate;
  float beta;
  float beta2;
  float init_decay;
  float decay;
  float epsilon;
};

class Adam{
protected:
  int iterations;
  float learning_rate;
  float beta;
  float beta2;
  float init_decay;
  float decay;
  float epsilon;
public:
  Adam(float learning_rate=0.001, float beta=0.9, float beta2=0.999, float decay=0);
  ~Adam();
  float[][2] update(float cost, float params[]=0);
  struct* get_variables();
};
#endif
