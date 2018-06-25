#ifndef __FUNCTIONS__LOSS_FUNCTIONS__HINGE_H
#define __FUNCTIONS__LOSS_FUNCTIONS__HINGE_H
#include <iostream>
#include <further_maths.h>

class Hinge{
public:
  float* list_of_functions[3]={&this.hinge, &this.squared_hinge, &this.categorical_hinge};

  std::string get_func_name(float* func);
  float* get_func(std::string name);

  float hinge(float output[], float expected_output[]);
  float squared_hinge(float output[], float expected_output[]);
  float categorical_hinge(float output[], float expected_output[]);

};
#endif
