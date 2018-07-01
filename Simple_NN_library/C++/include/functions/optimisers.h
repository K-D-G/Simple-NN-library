#ifndef __FUNCTIONS__OPTIMISERS_H
#define __FUNCTIONS__OPTIMISERS_H

//Class for manipulating the weights
class Optimisation_functions{
public:
  SGD();
  Momentum();
  Nesterov_Momentum();
  AdaGrad();
  RMSProp();
  Adam();
};
