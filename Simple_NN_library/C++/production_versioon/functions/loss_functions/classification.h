#ifndef FUNCTIONS__LOSS_FUNCTIONS__CLASSIFICATION_H
#define FUNCTIONS__LOSS_FUNCTIONS__CLASSIFICATION_H
#include <iostream>
#include <math.h>
#include "../../further_maths.h"

namespace Simple_NN_library{
  namespace functions{
    namespace loss_functions{
      class Classification{
      private:
        typedef float (*pointer)(float*, float*);
      public:

        static std::string get_func_name(float func(float*, float*));
        static pointer get_func(std::string name);

        static float binary_cross_entropy(float* output, float* expected_output);
        static float negative_log_likelihood(float* output, float* expected_output);
        //float margin_classifier(float output[], float expected_output[]);
        //float soft_margin_classifier(float output[], float expected_output[]);

      };
    }
  }
}
#endif
