#ifndef __FUNCTIONS__OPTIMISERS__ADAGRAD_H
#define __FUNCTIONS__OPTIMISERS__ADAGRAD_H
#include <further_maths.h>

struct AdaGrad_variables{
  
};

class AdaGrad{
public:
  AdaGrad();
  ~AdaGrad();

  float[][2] update();
  struct* get_variables();
};
#endif
