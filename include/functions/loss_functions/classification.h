#ifndef __FUNCTIONS__LOSS_FUNCTIONS__CLASSIFICATION_H
#define __FUNCTIONS__LOSS_FUNCTIONS__CLASSIFICATION_H
#include <iostream>
#include <math.h>
#include <further_maths.h>

class Classification{
public:
  float* list_of_functions[4]={&this.binary_cross_entropy, &this.negative_log_likelihood};

  std::string get_func_name(float* func);
  float* get_func(std::string name);

  float binary_cross_entropy(float output[], float expected_output[]);
  float negative_log_likelihood(float output[], float expected_output[]);
  //float margin_classifier(float output[], float expected_output[]);
  //float soft_margin_classifier(float output[], float expected_output[]);

};
#endif
