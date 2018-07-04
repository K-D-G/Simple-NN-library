#ifndef __NETWORKS__FEED_FORWARD_H
#define __NETWORKS__FEED_FORWARD_H
#include <functions/activation_functions.h>
#include <networks/node.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>

namespace Simple_NN_library{
  namespace networks{
    class Feed_forward{
    private:
      typedef float* (*pointer)(float*);
      //2D arrays because the first depth refers to the hidden layer number
      //And the second refers to the node
      float*** weights;
      float*** biasses;
      pointer activation_function;

      //Per hidden layer
      //2D array
      Simple_NN_library::networks::Node*** nodes;
      int num_hiddenlayers;
      int* nodes_per_layer;

      //Input and then output data
      //[][2][]
      float*** training_data;
    protected:
      bool set_weights(float*** weights);
      bool set_biasses(float*** biasses);
      bool set_activation(std::string activation_function);

      bool set_weights_randomly();
      bool set_biasses_randomly();
    public:
      Feed_forward(bool new_network=true, int* nodes_per_layer=NULL, std::string activation_function="");
      ~Feed_forward();

      bool save_network(std::string path, std::string name);
      bool load_network(std::string path);

      bool set_activation_function(std::string activation_function);

      std::string backpropagation(float output[]);
      //[][2][]
      void train(float*** training_data, bool print_result=true, std::string text_file_path=NULL);
      void setup_nodes(int* nodes_per_layer);
      //1D array for 1st arg 2 pointers for identifying the pointer
      float* calculate_layer(Simple_NN_library::networks::Node** layer, float* inputs);
      float* use_network(float* inputs);
    };

  }
}
#endif
