#include "classification.h"

using namespace Simple_NN_library;
using namespace std;
using namespace functions;
using namespace loss_functions;
using namespace further_maths;

string Classification::get_func_name(float func(float*, float*)){
  string func_name="unknown";
  if(*func==binary_cross_entropy){func_name="binary cross entropy";}
  else if(*func==negative_log_likelihood){func_name="negative log likelihood";}
  return func_name;
}
Classification::pointer Classification::get_func(string name){
  if(name=="binary cross entropy"){return binary_cross_entropy;}
  else if(name=="negative log likelihood"){return negative_log_likelihood;}
}

float Classification::binary_cross_entropy(float* output, float* expected_output){
  //Algorithm=-sum_i(x[i]*log(z[i])+(1-x[i])*log(1-z[i]))
  //x=output z=expected
  float* x=output;
  float* z=expected_output;

  float result=0;

  for(int i=0; i<sizeof(x); i++){
    result+=x[i]*log(z[i])+(1-x[i])*log(1-z[i]);
  }
  return -result;
}
float Classification::negative_log_likelihood(float* output, float* expected_output){
  //Is this right?
  float result=0;
  for(int i=0; i<sizeof(expected_output); i++){
    result+=-log(expected_output[i]);
  }
  return result;
}

/*
float Classification::margin_classifier(float output[], float expected_output[]){

}
float Classification::soft_margin_classifier(float output[], float expected_output[]){

}
*/
