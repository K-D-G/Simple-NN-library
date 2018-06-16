#include <networks/feed_forward.h>

using namespace the_network;
using namespace networks;
using namespace functions;

//Public stuff
//Set arguments for this function when I can be bothered
Feed_forward::Feed_forward(bool new_network=true, int nodes_per_layer[]=NULL, float* activation_function=NULL){
  if(new_network&&nodes_per_layer!=NULL&&activation_function!=NULL){
    this.set_activation(activation_function);
    this.set_weights_randomly();
    this.set_biasses_randomly();
    this.setup_nodes(nodes_per_layer);
  }
}
Feed_forward::~Feed_forward(){

}

//Protected stuff so make friend classes with back propagation and stuff
/*REWRITE SET_WEIGHTS AND SET_BIASES SO THEY WORK WITH ARRAY DEPTH*/
bool Feed_forward::set_weights(float weights[][][]){
  this.weights=weights;
  for(int i=0; i<sizeof(this.nodes); i++){
    this.nodes[i].set_weights(this.weights[i]);
  }
  return true;
}
bool Feed_forward::set_biasses(float biasses[][][]){
  this.biasses=biasses;
  for(int i=0; i<sizeof(this.nodes); i++){
    this.nodes[i].set_biasses(this.biasses[i]);
  }
  return true;
}
bool Feed_forward::set_activation(float* activation_function){
  this.activation_function=activation_function;
  return true;
}

bool Feed_forward::set_weights_randomly(){
  for(int i=0; i<sizeof(this.weights); i++){
    for(int j=0; j<sizeof(this.weights[i]); j++){
      //Figure out the rand stuff
      this.weights[i][j]=
    }
  }
  return true;
}
bool Feed_forward::set_biasses_randomly(){
  return true;
}

void Feed_forward::setup_nodes(int nodes_per_layer[]){
  this.nodes_per_layer=nodes_per_layer;
  this.num_hiddenlayers=sizeof(this.nodes_per_layer);

  for(int i=0; i<sizeof(this.num_hiddenlayers); i++){
    for(int j=0; j<this.nodes_per_layer[i]; j++){
      Node node(this.weights[i][j], this.biasses[i][j], this.activation_function);
      this.nodes[i][j]=node;
    }
  }
}

//Public stuff
void Feed_forward::train(float training_data[][2]){

}

bool Feed_forward::save_network(){
  return true;
}
bool Feed_forward::load_network(char* path){
  return true;
}

bool set_activation_function(float* activation_function){
  return this.set_activation(activation_function);
}

float Feed_forward::use_network(float inputs[]){

}
