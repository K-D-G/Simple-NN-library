#ifndef __FUNCTIONS__LOSS_FUNCTIONS__HINGE_H
#define __FUNCTIONS__LOSS_FUNCTIONS__HINGE_H
#include <iostream>
#include <further_maths.h>

namespace Simple_NN_library{
  namespace functions{
    namespace loss_functions{
      class Hinge{
      private:
        typedef float (*pointer)(float*, float*);
      public:

        static std::string get_func_name(float func(float*, float*));
        static pointer get_func(std::string name);

        static float hinge(float* output, float* expected_output);
        static float squared_hinge(float* output, float* expected_output);
        static float categorical_hinge(float* output, float* expected_output);

      };
    }
  }
}
#endif
