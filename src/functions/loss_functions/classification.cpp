#include <functions/loss_functions/classification.h>

using namespace std;
using namespace functions;
using namespace the_network;
using namespace further_maths;

string Classification::get_func_name(float* func){
  string func_name="unknown";
  if(func==this.list_of_functions[0]){func_name="binary cross entropy";}
  else if(func==this.list_of_functions[1]){func_name="negative log likelihood";}
  else if(func==this.list_of_functions[2]){func_name="margin classifier";}
  else if(func==this.list_of_functions[3]){func_name="soft margin classifier";}
  return func_name;
}
float* Classification::get_func(string name){
  if(name=="binary cross entropy"){return this.list_of_functions[0];}
  else if(name=="negative log likelihood"){return this.list_of_functions[1];}
  else if(name=="margin classifier"){return this.list_of_functions[2];}
  else if(name=="soft margin classifier"){return this.list_of_functions[3];}
}

float Classification::binary_cross_entropy(float output[], float expected_output[]){

}
float Classification::negative_log_likelihood(float output[], float expected_output[]){

}
float Classification::margin_classifier(float output[], float expected_output[]){

}
float Classification::soft_margin_classifier(float output[], float expected_output[]){

}
