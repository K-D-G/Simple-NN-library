#ifndef __FUNCTIONS__LOSS_FUNCTIONS__REGRESSIVE_H
#define __FUNCTIONS__LOSS_FUNCTIONS__REGRESSIVE_H
#include <iostream>
#include <further_maths.h>

class Regressive{
public:
  float[]* list_of_functions[3]={&this.mean_square_error, &this.absolute_error, &this.smooth_absolute_error};

  std::string get_func_name(float[]* func);
  float[]* get_func(std::string name);

  float mean_square_error(float output[], float expected_output[]);
  float absolute_error(float output[], float expected_output[]);
  float mean_absolute_percentage_error(float output[], float expected_output[]);
};
#endif
