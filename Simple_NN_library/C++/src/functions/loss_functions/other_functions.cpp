#include <functions/loss_functions/other_functions.h>

using namespace Simple_NN_library;
using namespace std;
using namespace functions;
using namespace loss_functions;
using namespace further_maths;

string Other_functions::get_func_name(float func(float*, float*)){
  string func_name="unknown";
  if(*func==log_cosh){func_name="log cosh";}
  else if(*func==kullback_leibler_divergence){func_name="kullback leibler divergence";}
  else if(*func==poisson){func_name="poisson";}
  else if(*func==cosine_proximity){func_name="cosine proximity";}
  return func_name;
}
Other_functions::pointer Other_functions::get_func(string name){
  if(name=="log cosh"){return log_cosh;}
  else if(name=="kullback leibler divergence"){return kullback_leibler_divergence;}
  else if(name=="poisson"){return poisson;}
  else if(name=="cosine proximity"){return cosine_proximity;}
}

float Other_functions::log_cosh(float* output, float* expected_output){
  return mean(actual_cosh(subtract_arrays(output, expected_output)));
}

float* Other_functions::actual_cosh(float* x){
  //x+_softplus(-2.*x)-log(2.)
  return subtract_constant(add_arrays(x, _softplus(multiply_constant(x, (float)-2))), log10((float)2));
}

float* Other_functions::_softplus(float* x){
  float* result;

  for(int i=0; i<sizeof(x); i++){
    result[i]=ln((float)1+exp(x[i]));
  }
  return result;
}

float Other_functions::kullback_leibler_divergence(float* output, float* expected_output){
  return sum(multiply_arrays(expected_output, array_log(divide_arrays(expected_output, output))));
}
float Other_functions::poisson(float* output, float* expected_output){
  return mean(subtract_arrays(output, multiply_arrays(expected_output, array_log(add_constant(output, get_epsilon())))));
}
float Other_functions::cosine_proximity(float* output, float* expected_output){
  return -sum(multiply_arrays(expected_output, output));
}
