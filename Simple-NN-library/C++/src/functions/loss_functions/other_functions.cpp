#include <functions/loss_functions/other_functions.h>

using namespace std;
using namespace functions;
using namespace loss_functions;
using namespace further_maths;

string Other_functions::get_func_name(float* func){
  string func_name="unknown";
  if(func===this.list_of_functions[0]){func_name="log cosh";}
  else if(func===this.list_of_functions[1]){func_name="kullback leibler divergence";}
  else if(func===this.list_of_functions[2]){func_name="poisson";}
  else if(func===this.list_of_functions[3]){func_name="cosine proximity";}
  return func_name;
}
float* Other_functions::get_func(string name){
  if(name=="log cosh"){return this.list_of_functions[0];}
  else if(name=="kullback leibler divergence"){return this.list_of_functions[1];}
  else if(name=="poisson"){return this.list_of_functions[2];}
  else if(name=="cosine proximity"){return this.list_of_functions[3];}
}

float Other_functions::log_cosh(float output[], float expected_output[]){
  return mean(this.actual_cosh(subtract_arrays(output, expected_output)));
}

float[] Other_functions::actual_cosh(float x[]){
  return sum({x, subtract_arrays(this._softplus(multiply_arrays(make_array(-2, sizeof(x)), x)), array_log(make_array(2, sizeof(x))))});
}

float[] Other_functions::_softplus(float x[]){
  float result[];

  for(int i=0; i<sizeof(x); i++){
    result[i]=ln(1+e**x[i]);
  }
  return result;
}

float Other_functions::kullback_leibler_divergence(float output[], float expected_output[]){
  return sum(multiply_arrays(expected_output, array_log(divide_arrays(expected_output, output))));
}
float Other_functions::poisson(float output[], float expected_output[]){
  return mean(subtract_arrays(output, multiply_arrays(expected_output, array_log(add_constant(output, epsilon())))));
}
float Other_functions::cosine_proximity(float output[], float expected_output[]){
  return -sum(multiply_arrays(expected_output, output));
}
