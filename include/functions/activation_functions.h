#ifndef __FUNCTIONS__ACTIVATION_FUNCTIONS_H
#define __FUNCTIONS__ACTIVATION_FUNCTIONS_H
#include <math.h>
#include <further_maths.h>


class Activation_functions{
public:
  float* list_of_functions[4]={&this.sigmoid, &this.tanh, &this.ReLU, &this.softmax};

  float sigmoid(float x);
  float tanh(float x);
  float ReLU(float x);
  float softmax(float inputs[]);
};



#endif
