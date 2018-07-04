#include "hinge.h"

using namespace Simple_NN_library;
using namespace functions;
using namespace loss_functions;
using namespace std;
using namespace further_maths;

string Hinge::get_func_name(float func(float*, float*)){
    string func_name="unknown";
    if(*func==hinge){func_name="hinge";}
    else if(*func==squared_hinge){func_name="squared hinge";}
    else if(*func==categorical_hinge){func_name="categorical hinge";}
    return func_name;
}
Hinge::pointer Hinge::get_func(string name){
  if(name=="hinge"){return hinge;}
  else if(name=="squared hinge"){return squared_hinge;}
  else if(name=="categorical hinge"){return categorical_hinge;}
}

float Hinge::hinge(float* output, float* expected_output){
  return mean(maximum({subtract_arrays(make_array(1, sizeof(output)), multiply_arrays(expected_output, output)), make_array(0, sizeof(output))}));
}
float Hinge::squared_hinge(float* output, float* expected_output){
  return mean(square_array(maximum({subtract_arrays(make_array(1, sizeof(output)), multiply_arrays(expected_output, output)), make_array(0, sizeof(output))})));
}
float Hinge::categorical_hinge(float* output, float* expected_output){
  return maximum({make_array(0, sizeof(output)), subtract_constant(max(subtract_arrays(make_array(1, sizeof(output)), expected_output), output), sum(multiply_arrays(expected_output, output))+1)}));
  //{make_array(0, sizeof(output)), subtract_constant(max(subtract_arrays(make_array(1, sizeof(output)), expected_output), output), sum(multiply_arrays(expected_output, output))+1}
}
