#ifndef __FUNCTIONS__OPTIMISERS__SGD_H
#define __FUNCTIONS__OPTIMISERS__SGD_H
#include <further_maths.h>

struct SGD_variables{
  float data[][2][];
  float alpha;
};

class SGD{
protected:
  float data[][2][];
  float alpha;
public:
  SGD(float training_data[][2][], float alpha=0.01);
  ~SGD();
  float[][2] update(float error, float weight_array[]);
  struct* get_variables();
};



#endif
