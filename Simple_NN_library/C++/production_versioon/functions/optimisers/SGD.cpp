#include "SGD.h"

using namespace Simple_NN_library;
using namespace functions;
using namespace optimisers;
using namespace further_maths;
using namespace std;

SGD::SGD(float*** training_data, float alpha){
  data=training_data;
  alpha=alpha;
}
SGD::~SGD(){

}
float* SGD::update(float error, float* weight_array){
  float* updates;
  float*** batch=_new_random_batch(256);
  float gradient=_get_gradient(error);
  updates=add_constant(weight_array, (-alpha*gradient));
  return updates;
}

//float*** batch
float SGD::_get_gradient(float error){
  return 2*error-4;
  //return divide_arrays_(dot_product(batch, make_array(error, sizeof(batch))), (float)2+sizeof(batch[0][0])));
}

float*** SGD::_new_random_batch(int batch_size, bool from_this_data){
  if(sizeof(data)<=batch_size){
    return NULL;
  }

  int random_numbers[batch_size];
  for(int i=0; i<batch_size; i++){
    float number=rand()%batch_size;
    random_numbers[i]=constrain(number, 0, sizeof(data));
  }
  float*** batch;
  for(int i=0; i<sizeof(random_numbers); i++){
    batch[i]=data[random_numbers[i]];
  }
  return batch;
}

SGD_variables* SGD::get_variables(){
  SGD_variables* vars;
  vars->data=data;
  vars->alpha=alpha;
  return vars;
}
