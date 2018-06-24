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
  else if(func==this.list_of_functions[2]){func_name="smooth absolute error";}
  return func_name;
}
float* Regressive::get_func(string name){
  if(name=="mean square error"){return this.list_of_functions[0];}
  else if(name=="absolute error"){return this.list_of_functions[1];}
  else if(name=="smooth absolute error"){return this.list_of_functions[2];}
}

float Regressive::mean_square_error(float output[], float expected_output[]){
  return mean(square(subtract_arrays(output, expected_output)));
}

float Regressive::absolute_error(float output[], float expected_output[]){
  return mean(array_abs(subtract_arrays(output, expected_output)));
}
