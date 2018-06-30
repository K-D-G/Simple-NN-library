#include <networks/node.h>

using namespace the_network;
using namespace networks;
using namespace functions;

Node::Node(float weights[], float biasses[], float* activation_function){
  this.set_weights(weights);
  this.set_biasses(biasses);
  this.set_activation(activation_function);
}
Node::~Node(){

}

float Node::formula(float calculation_array[][3]){
  float total=0;
  for(int i=0; i<sizeof(calculation_array); i++){
    total+=(calculation_array[i][0]*calculation_array[i][1])+calculation_array[i][2];
  }
  return total;
}

float Node::calculate(float inputs[]){
  if(sizeof(inputs)!=sizeof(this.weights)||sizeof(inputs)!=sizeof(this.biasses)){
    return (float)NULL;
  }
  float calculation_array[sizeof(inputs)][3];
  for(int i=0; i<sizeof(inputs); i++){
    calculation_array[i]={inputs[i], this.weights[i], this.biasses[i]};
  }

  float calculation_result=sum(this.formula(calculation_array));
  return this.activation_function(calculation_result);
}

void Node::set_weights(float weights[]){
  this.weights=weights;
}
void Node::set_biasses(float biasses[]){
  this.biasses=biasses;
}
bool Node::set_activation(float* activation_function){
  for(int i=0; i<sizeof(Activation_functions.list_of_functions); i++){
    if(Activation_functions.list_of_functions[i]==activation_function){
      this.activation_function=activation_function;
      return true;
    }
  }
  return false;
}
