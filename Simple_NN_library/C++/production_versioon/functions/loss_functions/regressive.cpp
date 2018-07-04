#include "regressive.h"

using namespace Simple_NN_library;
using namespace std;
using namespace functions;
using namespace loss_functions;
using namespace further_maths;

string Regressive::get_func_name(float func(float*, float*)){
  string func_name="unknown";
  if(*func==mean_square_error){func_name="mean square error";}
  else if(*func==absolute_error){func_name="absolute error";}
  else if(*func==mean_absolute_percentage_error){func_name="mean absolute percentage error";}
  else if(*func==mean_squared_logarithmic_error){func_name="mean squared logarithmic error";}
  return func_name;
}
Regressive::pointer Regressive::get_func(string name){
  if(name=="mean square error"){return mean_square_error;}
  else if(name=="absolute error"){return absolute_error;}
  else if(name=="mean absolute percentage error"){return mean_absolute_percentage_error;}
  else if(name=="mean squared logarithmic error"){return mean_squared_logarithmic_error;}
}

float Regressive::mean_square_error(float* output, float* expected_output){
  return mean(square_array(subtract_arrays(output, expected_output)));
}

float Regressive::absolute_error(float* output, float* expected_output){
  return mean(array_abs(subtract_arrays(output, expected_output)));
}

float Regressive::mean_absolute_percentage_error(float* output, float* expected_output){
  //return 100*mean(divide_arr(array_abs(subtract_arrays(expected_output, output)), array_abs()));
  float* result;
  for(int i=0; i<sizeof(output); i++){
    result[i]=abs((expected_output[i]-output[i])/expected_output[i]);
  }
  return (100/sizeof(output))*sum(result);
}

float Regressive::mean_squared_logarithmic_error(float* output, float* expected_output){
  return mean(square_array(subtract_arrays(array_log(output), array_log(expected_output))));
}
