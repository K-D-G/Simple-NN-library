#ifndef __NETWORKS__NODE_H
#define __NETWORKS__NODE_H
#include <further_maths.h>
#include <functions/activation_functions.h>

class Node{
protected:
  float weights[];
  float biasses[];
  float inputs[];

  float* activation_function;
public:
  Node(float weights[], float biasses[], float* activation_function);
  ~Node();

  float formula(float calculation_array[][3]);
  float calculate(float inputs[]);

  void set_weights(float weights[]);
  void set_biasses(float biasses[]);
  bool set_activation(float* activation_function);

};

#endif
