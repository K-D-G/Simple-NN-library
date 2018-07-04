#ifndef FUNCTIONS__OPTIMISERS__ADAM_H
#define FUNCTIONS__OPTIMISERS__ADAM_H
#include "../../further_maths.h"

namespace Simple_NN_library{
  namespace functions{
    namespace optimisers{
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
        Adam(float learning_rate_=0.001, float beta_=0.9, float beta2_=0.999, float decay_=0);
        ~Adam();
        float** update(float cost, float* params=NULL);
        Adam_variables* get_variables();
      };
    }
  }
}
#endif
