#include <functions/activation_functions.h>

using namespace Simple_NN_library;
using namespace functions;
using namespace further_maths;
using namespace std;

//Sigmoid
float* Activation_functions::sigmoid(float* x){
  float* arr;
  arr[0]=1/1+exp(-x[0]);
  return arr;
}

//Hyperbolic tangent
float* Activation_functions::tanh(float* x){
  float* arr;
  arr[0]=exp(2*x[0])+1/exp(2*x[0])-1;
  return arr;
}

//Rectified Linear Units
float* Activation_functions::ReLU(float* x){
  float* arr;
  if(x[0]<=0){arr[0]=(float)0;}
  else{arr=x;}
  return arr;
}

//Softmax
float* Activation_functions::softmax(float* x){
  float inputs_exp[sizeof(x)];
  for(int i=0; i<sizeof(x); i++){
    inputs_exp[i]=exp(x[i]);
  }

  float sum_inputs_exp=(float)sum(inputs_exp);

  float result[sizeof(inputs_exp)];
  for(int i=0; i<sizeof(inputs_exp); i++){
    result[i]=inputs_exp[i]/sum_inputs_exp;
  }
  return result;
}

string Activation_functions::get_func_name(float* func(float*)){
  string func_name="unknown";
  if(*func==sigmoid){func_name="sigmoid";}
  else if(*func==tanh){func_name="tanh";}
  else if(*func==ReLU){func_name="ReLU";}
  else if(*func==softmax){func_name="softmax";}
  return func_name;
}

Activation_functions::pointer Activation_functions::get_func(string name){
  if(name=="sigmoid"){return sigmoid;}
  else if(name=="tanh"){return tanh;}
  else if(name=="ReLU"){return ReLU;}
  else if(name=="softmax"){return softmax;}
}
