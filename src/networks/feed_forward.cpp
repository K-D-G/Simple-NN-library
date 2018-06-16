#include <networks/feed_forward.h>

using namespace the_network;
using namespace networks;
using namespace functions;
using namespace std;

//Public stuff
//Set arguments for this function when I can be bothered
Feed_forward::Feed_forward(bool new_network=true, int nodes_per_layer[]=NULL, float* activation_function=NULL){
  if(new_network&&nodes_per_layer!=NULL&&activation_function!=NULL){
    this.num_hiddenlayers=sizeof(nodes_per_layer);
    this.nodes_per_layer=nodes_per_layer;
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
      this.weights[i][j]=rand()%100+1;
    }
  }
  return true;
}
bool Feed_forward::set_biasses_randomly(){
  for(int i=0; i<sizeof(this.biasses); i++){
    for(int j=0; j<sizeof(this.biasses[i]); j++){
      this.biasses[i][j]=rand()%100+1;
    }
  }
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

bool Feed_forward::save_network(string path, string name){
  ofstream network_file;
  network_file.open(path+"/"+name+".nn");

  //Not needed however use for load
  /*string weight_data;
  string bias_data;
  string activation_function_name;
  //Number of hidden layers
  string number_hl;
  //Nodes per layer
  string npl;
  */
  network_file<<"WEIGHTS"<<endl;
  for(int i=0; i<sizeof(this.weights); i++){
    network_file<<"[";
    for(int j=0; j<sizeof(this.weights[i]); j++){
      network_file<<this.weights[i][j]<<" ";
    }
    network_file<<"]"<<endl;
  }
  network_file<<"END"<<endl;

  network_file<<"BIASSES"<<endl;
  for(int i=0; i<sizeof(this.biasses); i++){
    network_file<<"[";
    for(int j=0; j<sizeof(this.biasses[i]); j++){
      network_file<<this.biasses[i][j]<<" ";
    }
    network_file<<"]"<<endl;
  }
  network_file<<"END"<<endl;

  network_file<<"ACTIVATION FUNCTION: "<<Activation_functions::get_func_name(this.activation_function)<<endl;
  network_file<<"NUM HIDDEN LAYERS: "<<this.num_hiddenlayers<<endl;

  network_file<<"NODES PER LAYER"<<endl;
  for(int i=0; i<sizeof(this.nodes_per_layer); i++){
    network_file<<this.nodes_per_layer[i]<<" ";
  }
  network_file<<"END"<<endl;

  network_file<<"ENDFILE"<<endl;
  return true;
}
bool Feed_forward::load_network(string full_path){
  return true;
}

bool set_activation_function(float* activation_function){
  return this.set_activation(activation_function);
}

float Feed_forward::use_network(float inputs[]){

}
