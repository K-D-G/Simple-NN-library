#include <functions/loss_functions/regressive.h>

using namespace std;
using namespace functions;
using namespace loss_functions;
using namespace the_network;
using namespace further_maths;

string Regressive::get_func_name(float* func){
  string func_name="unknown";
  if(func==this.list_of_functions[0]){func_name="mean square error";}
  else if(func==this.list_of_functions[1]){func_name="absolute error";}
  else if(func==this.list_of_functions[2]){func_name="mean absolute percentage error";}
  else if(func==this.list_of_functions[3]){func_name="mean squared logarithmic error";}
  return func_name;
}
float* Regressive::get_func(string name){
  if(name=="mean square error"){return this.list_of_functions[0];}
  else if(name=="absolute error"){return this.list_of_functions[1];}
  else if(name=="mean absolute percentage error"){return this.list_of_functions[2];}
  else if(name=="mean squared logarithmic error"){return this.list_of_functions[3];}
}

float Regressive::mean_square_error(float output[], float expected_output[]){
  return mean(square_array(subtract_arrays(output, expected_output)));
}

float Regressive::absolute_error(float output[], float expected_output[]){
  return mean(array_abs(subtract_arrays(output, expected_output)));
}

float Regressive::mean_absolute_percentage_error(float output[], float expected_output[]){
  //return 100*mean(divide_arr(array_abs(subtract_arrays(expected_output, output)), array_abs()));
  float result[];
  for(int i=0; i<sizeof(output); i++){
    result[i]=abs((expected_output[i]-output[i])/expected_output[i])
  }
  return (100/sizeof(output))*sum(result);
}

float Regressive::mean_squared_logarithmic_error(float output[], float expected_output){
  return mean(square_array(subtract_arrays(array_log(output), array_log(expected_output))));
}
