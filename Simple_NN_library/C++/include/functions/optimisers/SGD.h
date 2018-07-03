#ifndef __FUNCTIONS__OPTIMISERS__SGD_H
#define __FUNCTIONS__OPTIMISERS__SGD_H
#include <further_maths.h>

namespace Simple_NN_library{
  namespace functions{
    namespace optimisers{
      struct SGD_variables{
        float*** data;
        float alpha;
      };

      class SGD{
      protected:
        //[][2][]
        float*** data;
        float alpha;
      public:
        SGD(float*** training_data, float alpha=0.01);
        ~SGD();
        float* update(float error, float* weight_array);
        float _get_gradient(float error);
        float*** _new_random_batch(int batch_size, bool from_this_data=true);
        SGD_variables* get_variables();
      };
    }
  }
}
#endif
