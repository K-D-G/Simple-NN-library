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
bool Feed_forward::set_weights(float weights[][][]){
  this.weights=weights;
  for(int i=0; i<sizeof(this.nodes); i++){
    for(int j=0; j<sizeof(this.nodes[i]); j++){
      this.nodes[i][j].set_weights(this.weights[i][j]);
    }
  }
  return true;
}
bool Feed_forward::set_biasses(float biasses[][][]){
  this.biasses=biasses;
  for(int i=0; i<sizeof(this.nodes); i++){
    for(int j=0; j<sizeof(this.nodes[i]); j++){
      this.nodes[i][j].set_biasses(this.biasses[i][j]);
    }
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
bool Feed_forward::save_network(string path, string name){
  ofstream network_file;
  network_file.open(path+"/"+name+".nn");

  network_file<<"WEIGHTS"<<endl;
  for(int i=0; i<sizeof(this.weights); i++){
    network_file<<"[";
    for(int j=0; j<sizeof(this.weights[i]); j++){
      network_file<<"[";
      for(int x=0; x<sizeof(this.weights[i][j]); x++){
        network_file<<this.weights[i][j][x]<<" ";
      }
      network_file<<"]";
    }
    network_file<<"]"<<endl;
  }
  network_file<<"END"<<endl;

  network_file<<"BIASSES"<<endl;
  for(int i=0; i<sizeof(this.biasses); i++){
    network_file<<"[";
    for(int j=0; j<sizeof(this.biasses[i]); j++){
      network_file<<"[";
      for(int x=0; x<sizeof(this.biasses[i][j]); x++){
        network_file<<this.biasses[i][j]<<" ";
      }
      network_file<<"]";
    }
    network_file<<"]"<<endl;
  }
  network_file<<"END"<<endl;

  network_file<<"ACTIVATION FUNCTION: "<<Activation_functions::get_func_name(this.activation_function)<<endl;
  network_file<<"NUM HIDDEN LAYERS: "<<this.num_hiddenlayers<<endl;

  network_file<<"NODES PER LAYER"<<endl;
  network_file<<"[";
  for(int i=0; i<sizeof(this.nodes_per_layer); i++){
    network_file<<this.nodes_per_layer[i]<<" ";
  }
  network_file<<"]"<<endl;
  network_file<<"END"<<endl;

  network_file<<"ENDFILE"<<endl;
  network_file.close();
  return true;
}
bool Feed_forward::load_network(string full_path){
  string weight_data;
  string bias_data;
  string activation_function_name;
  //Number of hidden layers
  string number_hl;
  //Nodes per layer
  string npl;

  ifstream network_file;
  try{
    network_file.open(full_path);
  }catch(e){
    return false;
  }
  network_file>>data;
  network_file.close();

  for(int i=0; i<sizeof(data); i++){
    if(data[i:i+9]=="WEIGHTS\n"){
      for(int j=i+9; j<sizeof(data[i+9:]); j++){
        if(data[j:j+3]=="END"){
          break;
        }else{
          weight_data=weight_data+data[j];
        }
      }
    }else if(data[i:i+9]=="BIASSES\n"){
      for(int j=i+9; j<sizeof(data[i+9:]); j++){
        if(data[j:j+3]=="END"){
          break;
        }else{
          bias_data=bias_data+data[j];
        }
      }
    }else if(data[i:i+21]=="ACTIVATION FUNCTION: "){
      for(int j=i+21; j<sizeof(data[i+21:]); j++){
        if(data[j:j+2]=="\n"){
          break;
        }else{
          activation_function_name=activation_function_name+data[j];
        }
      }
    }else if(data[i:i+19]=="NUM HIDDEN LAYERS: "){
      for(int j=i+19; j<sizeof(data[i+19:]); j++){
        if(data[j:j+2]=="\n"){
          break;
        }else{
          number_hl=number_hl+data[j];
        }
      }
    }else if(data[i:i+15]=="NODES PER LAYER\n"){
      for(int j=i+15; j<sizeof(data[i+15:]); j++){
        if(data[j:j+3]=="END"){
          break;
        }else{
          npl=npl+data[j];
        }
      }
    }else if(data[i:i+7]=="ENDFILE"){
      break;
    }
  }


  string temp[];
  string delimeter="]]";
  size_t pos=0;
  int index=0;
  string s=weight_data;

  while((pos=s.find(delimeter))!=string::npos){
    temp[index]=s.substr(0, pos);
    index++;
    s.erase(0, pos+delimeter.length());
  }



  string temp2[][];
  delimeter="[";
  for(int i=0; i<sizeof(temp); i++){
    pos=1;
    index=0;
    while((pos=temp[i].find(delimeter))!=string::npos){
      temp2[i][index]=temp[i].substr(1, pos);
      index++;
      temp[i].erase(1, pos+delimeter.length());
    }
  }

  int temp3[][][];
  for(int i=0; i<sizeof(temp2); i++){
    temp3[i]={};

    string array_temp=temp2[i][1:-2];
    string temp4[];
    pos=0;
    index=0;
    delimeter="]";
    while((pos=array_temp.find(delimeter))!=string::npos){
      temp4[index]=array_temp.substr(0, pos);
      index++;
      array_temp.erase(0, pos+delimeter.length());
    }

    for(int j=0; j<sizeof(temp4); j++){
      temp4[j]=temp4[j][1:-2];
    }

    string temp5[][];
    delimeter=" ";
    for(int j=0; j<sizeof(temp4); j++){
      pos=0;
      index=0;
      while((pos=temp4[j].find(delimeter))!=string::npos){
        temp5[j][index]=temp4[j].substr(0, pos);
        index++;
        temp4[j].erase(0, pos+delimeter+length());
      }
    }

    int temp6[][];
    for(int j=0; j<sizeof(temp5); j++){
      for(int x=0; x<sizeof(temp5[j]); j++){
        temp6[j][x]=(int)temp[j][x];
      }
    }

    for(int j=0; j<sizeof(temp6); j++){
      temp3[i][j]=temp6[j];
    }
  }

  this.weights=temp3;


  string temp[];
  string delimeter="]]";
  size_t pos=0;
  int index=0;
  string s=bias_data;

  while((pos=s.find(delimeter))!=string::npos){
    temp[index]=s.substr(0, pos);
    index++;
    s.erase(0, pos+delimeter.length());
  }



  string temp2[][];
  delimeter="[";
  for(int i=0; i<sizeof(temp); i++){
    pos=1;
    index=0;
    while((pos=temp[i].find(delimeter))!=string::npos){
      temp2[i][index]=temp[i].substr(1, pos);
      index++;
      temp[i].erase(1, pos+delimeter.length());
    }
  }

  int temp3[][][];
  for(int i=0; i<sizeof(temp2); i++){
    temp3[i]={};

    string array_temp=temp2[i][1:-2];
    string temp4[];
    pos=0;
    index=0;
    delimeter="]";
    while((pos=array_temp.find(delimeter))!=string::npos){
      temp4[index]=array_temp.substr(0, pos);
      index++;
      array_temp.erase(0, pos+delimeter.length());
    }

    for(int j=0; j<sizeof(temp4); j++){
      temp4[j]=temp4[j][1:-2];
    }

    string temp5[][];
    delimeter=" ";
    for(int j=0; j<sizeof(temp4); j++){
      pos=0;
      index=0;
      while((pos=temp4[j].find(delimeter))!=string::npos){
        temp5[j][index]=temp4[j].substr(0, pos);
        index++;
        temp4[j].erase(0, pos+delimeter+length());
      }
    }

    int temp6[][];
    for(int j=0; j<sizeof(temp5); j++){
      for(int x=0; x<sizeof(temp5[j]); j++){
        temp6[j][x]=(int)temp[j][x];
      }
    }

    for(int j=0; j<sizeof(temp6); j++){
      temp3[i][j]=temp6[j];
    }
  }

  this.biasses=temp3;


  this.activation_function=Activation_functions::get_func(activation_function_name);
  this.num_hiddenlayers=(int)number_hl;


  string npl_=npl
  string temp_npl[];
  index=0;
  pos=0;

  while((pos=npl_.find(delimeter))!=string::npos){
    temp_npl[index]=npl_.substr(0, pos);
    index++;
    npl_.erase(0, pos+delimeter.length());
  }

  int temp_npl2[];
  for(int i=0; i<sizeof(temp_npl); i++){
    if(temp_npl[i]=="]"){break;}
    temp_npl2[i]=(int)temp_npl[i];
  }
  this.nodes_per_layer=temp_npl2;

  this.setup_nodes(this.nodes_per_layer);
  return true;
}

bool set_activation_function(float* activation_function){
  return this.set_activation(activation_function);
}

//Write once finished with the optimisers
string Feed_forward::backpropagation(float output[]){

}
void Feed_forward::train(float training_data[][2][], bool print_result=true, string text_file_path=NULL, string name=NULL){
  float output[];
  string result;
  if(name!=NULL&&text_file_path==NULL){printf("You have not provided a path for the file therefore the result will not be recorded. However the network will still run\n");}
  if(text_file_path!=NULL){
    if(name==NULL){
      printf("You have not provided a name for the text file therefore the result will not be recorded. However the network will still run\n");
      text_file_path=NULL;
    }else{
      ofstream log_file;
      log_file.open(text_file_path+"/"+name+".nn_log");
    }
  }
  while(true){
    for(int i=0; i<sizeof(training_data); i++){
      output=this.use_network(training_data[i][0]);
      result=this.backpropagation(output);
    }
    if(print_result){
      printf("%s\n", result);
    }
    if(text_file_path!=NULL){
      log_file<<result<<endl;
    }
  }
  if(text_file_path!=NULL){log_file.close();}
}

float[] Feed_forward::calculate_layer(Node layer[], float inputs[]){
  float outputs[];
  for(int i=0; i<sizeof(layer); i++){
    outputs[i]=layer[i].calculate(inputs);
  }
  return outputs;
}

float[] Feed_forward::use_network(float inputs[]){
  for(int x=0; x<sizeof(this.nodes); x++){
    inputs=this.calculate_layer(this.nodes[i], inputs);
  }
  return inputs;
}
