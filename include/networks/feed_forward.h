#ifndef __NETWORKS__FEED_FORWARD_H
#define __NETWORKS__FEED_FORWARD_H
#include <functions/activation_functions.h>
#include <networks/node.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>

class Feed_forward{
private:
  //2D arrays because the first depth refers to the hidden layer number
  //And the second refers to the node
  float weights[][][];
  float biasses[][][];
  float* activation_function;

  //Per hidden layer
  networks::Node* nodes[][];
  int num_hiddenlayers;
  int nodes_per_layer[];

  //Input and then output data
  float training_data[][2];
protected:
  bool set_weights(float weights[][][]);
  bool set_biasses(float biasses[][][]);
  bool set_activation(float* activation_function);

  bool set_weights_randomly();
  bool set_biasses_randomly();
public:
  Feed_forward(bool new_network=true, int nodes_per_layer[]=NULL, float* activation_function=NULL);
  ~Feed_forward();

  void train(float training_data[][2]);
  bool save_network(string path);
  bool load_network(string path);
  bool set_activation_function(float* activation_function);
  void setup_nodes(int nodes_per_layer[]);
  float use_network(float inputs[]);
};



#endif
