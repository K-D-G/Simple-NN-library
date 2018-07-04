#ifndef FUNCTIONS__LOSS_FUNCTIONS__REGRESSIVE_H
#define FUNCTIONS__LOSS_FUNCTIONS__REGRESSIVE_H
#include <iostream>
#include <further_maths.h>

namespace Simple_NN_library{
  namespace functions{
    namespace loss_functions{
      class Regressive{
      private:
        typedef float (*pointer)(float*, float*);
      public:

        static std::string get_func_name(float func(float*, float*));
        static pointer get_func(std::string name);

        static float mean_square_error(float* output, float* expected_output);
        static float absolute_error(float* output, float* expected_output);
        static float mean_absolute_percentage_error(float* output, float* expected_output);
        static float mean_squared_logarithmic_error(float* output, float* expected_output);
      };
    }
  }
}
#endif
