#include <functions/optimisers/SGD.h>

using namespace functions;
using namespace optimisers;
using namespace further_maths;
using namespace std;

SGD::SGD(float training_data[][2][], float alpha=0.01){
  this.data=training_data;
  this.alpha=alpha;
}
SGD::~SGD(){

}
float[][2] SGD::update(float error, float weight_array[]){
  float updates[];
  float batch[][2][]=_new_random_batch(256);
  float gradient=_get_gradient(error, batch);
  updates=add_constant(weight_array, (-this.alpha*gradient));
  return updates;
}

float SGD::_get_gradient(float error, float batch[][2][]){
  return divide_arrays(dot_product(batch, error), 2+sizeof(batch[0][0])));
}

float[][2][]SGD::_new_random_batch(int batch_size, bool from_this_data=true){
  if(sizeof(this.data)<=batch_size){
    return {{{0, 0}}, {{0, 0}}};
  }

  int random_numbers[batch_size];
  for(int i=0; i<batch_size; i++){
    random_numbers[i]=constrain(rand()%batch_size);
  }
  float batch[][2][];
  for(int i=0; i<sizeof(random_numbers); i++){
    batch[i]=this.data[random_numbers[i]];
  }
  return batch;
}

struct* SGD::get_variables(){
  SGD_variables* vars;
  vars.data=this.data;
  vars.alpha=this.alpha;
  return vars;
}
