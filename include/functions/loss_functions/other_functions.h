#ifndef __FUNCTIONS__LOSS_FUNCTIONS__OTHER_FUNCTIONS_H
#define __FUNCTIONS__LOSS_FUNCTIONS__OTHER_FUNCTIONS_H
#include <iostream>
#include <further_maths.h>

class Other_functions{
public:
  float* list_of_functions[4]={&this.log_cosh, &this.kullback_leibler_divergence, &this.poisson, &this.cosine_proximity};

  std::string get_func_name(float* func);
  float* get_func(std::string name);

  float log_cosh(float output[], float expected_output[]);
  float kullback_leibler_divergence(float output[], float expected_output[]);
  float poisson(float output[], float expected_output[]);
  float cosine_proximity(float output[], float expected_output[]);
};

#endif
