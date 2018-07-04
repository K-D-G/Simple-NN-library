#include <networks/node.h>

using namespace Simple_NN_library;
using namespace networks;
using namespace functions;
using namespace further_maths;

Node::Node(float* weights, float* biasses, float* activation_function(float*)){
  set_weights(weights);
  set_biasses(biasses);
  set_activation(activation_function);
}
Node::~Node(){

}

float Node::formula(float** calculation_array){
  float total=0;
  for(int i=0; i<sizeof(calculation_array); i++){
    total+=(calculation_array[i][0]*calculation_array[i][1])+calculation_array[i][2];
  }
  return total;
}

float* Node::calculate(float* inputs){
  if(sizeof(inputs)!=sizeof(weights)||sizeof(inputs)!=sizeof(biasses)){
    return (float*)NULL;
  }
  float** calculation_array;
  for(int i=0; i<sizeof(inputs); i++){
    calculation_array[i][0]=inputs[i];
    calculation_array[i][1]=weights[i];
    calculation_array[i][2]=biasses[i];
  }

  float calculation_result=formula(calculation_array);
  float* calc_result;
  calc_result[0]=calculation_result;
  return activation_function(calc_result);
}

void Node::set_weights(float* weights){
  weights=weights;
}
void Node::set_biasses(float* biasses){
  biasses=biasses;
}
bool Node::set_activation(float* activation_function(float*)){
  activation_function=activation_function;
  return true;
}
