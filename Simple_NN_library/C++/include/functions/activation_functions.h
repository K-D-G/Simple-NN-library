#ifndef __FUNCTIONS__ACTIVATION_FUNCTIONS_H
#define __FUNCTIONS__ACTIVATION_FUNCTIONS_H
#include <math.h>
#include <further_maths.h>
#include <iostream>

namespace Simple_NN_library{
  namespace functions{
    class Activation_functions{
    private:
      typedef float* (*pointer)(float*);
    public:

      static std::string get_func_name(float* func(float*));
      static pointer get_func(std::string name);

      static float* sigmoid(float* x);
      static float* tanh(float* x);
      static float* ReLU(float* x);
      static float* softmax(float* inputs);
    };
  }
}
#endif
