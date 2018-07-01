#include <functions/loss_functions/hinge.h>

using namespace functions;
using namespace loss_functions;
using namespace std;
using namespace further_maths;

string Hinge::get_func_name(float* func){
    string func_name="unknown";
    if(func==this.list_of_functions[0]){func_name="hinge";}
    else if(func==this.list_of_functions[1]){func_name="squared hinge";}
    else if(func==this.list_of_functions[2]){func_name="categorical hinge";}
    return func_name;
}
float* Hinge::get_func(string name){
  if(name=="hinge"){return this.list_of_functions[0];}
  else if(name=="squared hinge"){return this.list_of_functions[1];}
  else if(name=="categorical hinge"){return this.list_of_functions[2];}
}

float Hinge::hinge(float output[], float expected_output[]){
  return mean(maximum([subtract_arrays(make_array(1, sizeof(output)), multiply_arrays(expected_output, output)), make_array(0, sizeof(output))]));
}
float Hinge::squared_hinge(float output[], float expected_output[]){
  return mean(square_array(maximum([subtract_arrays(make_array(1, sizeof(output)), multiply_arrays(expected_output, output)), make_array(0, sizeof(output))])));
}
float Hinge::categorical_hinge(float output[], float expected_output[]){
  return maximum(make_array(0, sizeof(output)), subtract_constant(max(subtract_arrays(make_array(1, sizeof(output)), expected_output), output), sum(multiply_arrays(expected_output, output))+1));
}
