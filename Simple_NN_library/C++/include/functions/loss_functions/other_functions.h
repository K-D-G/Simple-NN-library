#ifndef __FUNCTIONS__LOSS_FUNCTIONS__OTHER_FUNCTIONS_H
#define __FUNCTIONS__LOSS_FUNCTIONS__OTHER_FUNCTIONS_H
#include <iostream>
#include <further_maths.h>

namespace Simple_NN_library{
  namespace functions{
    namespace loss_functions{
      class Other_functions{
      private:
        typedef float (*pointer)(float*, float*);
      public:
        std::string get_func_name(float func(float*, float*));
        pointer get_func(std::string name);

        static float log_cosh(float* output, float* expected_output);
        static float kullback_leibler_divergence(float* output, float* expected_output);
        static float poisson(float* output, float* expected_output);
        static float cosine_proximity(float* output, float* expected_output);

        static float* actual_cosh(float* x);
        static float* _softplus(float* x);
      };
    }
  }
}
#endif
