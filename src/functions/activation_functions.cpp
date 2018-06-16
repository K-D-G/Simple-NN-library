#include <functions/activation_functions.h>

using namespace the_network;
using namespace functions;
using namespace std;

//Sigmoid
float Activation_functions::sigmoid(float x){
  return 1/1+exp(-x);
}

//Hyperbolic tangent
float Activation_functions::tanh(float x){
  return exp(2*x)+1/exp(2*x)-1;
}

//Rectified Linear Units
float Activation_functions::ReLU(float x){
  if(x<=0){return (float)0;}
  else{return x;}
}

//Softmax
float Activation_functions::softmax(float inputs[]){
  float inputs_exp[sizeof(inputs)];
  for(int i=0; i<sizeof(inputs); i++){
    inputs_exp[i]=exp(inputs[i]);
  }

  float sum_inputs_exp=(float)sum(inputs_exp);

  float result[sizeof(inputs_exp)];
  for(int i=0; i<sizeof(inputs_exp); i++){
    result[i]=inputs_exp[i]/sum_inputs_exp;
  }
  return result;
}
string get_func_name(float* func){
  string func_name="unknown";
  if(func==this.list_of_functions[0]){func_name="sigmoid";}
  else if(func==this.list_of_functions[1]){func_name="tanh";}
  else if(func==this.list_of_functions[2]){func_name="ReLU";}
  else if(func==this.list_of_functions[3]){func_name="softmax";}
  return func_name;
}
