#include <graphing/graphing.h>

using namespace Simple_NN_library;
using namespace graphing;
using namespace std;

Graph::Graph(data_struct* data, string filepath){
  file_path=filepath;
  string file;
  ofstream f;
  ifstream template_;

  f.open(filepath);
  template_.open("template.html");
  string template_data;
  template_>>template_data;
  f<<template_data;
  template_.close();
  f.close();

  update_graph(data);
}
bool Graph::update_graph(data_struct* data){
  ifstream f;
  f.open(file_path);
  string file;
  f>>file;
  f.close();

  size_t pos=file.find("VAR: project_name")-sizeof("VAR: project_name");
  file.replace(pos, sizeof("VAR: project_name"), data.project_name);

  pos=file.find("VAR: epochs")-sizeof("VAR: epochs");
  file.replace(pos, sizeof("VAR: epochs"), data.epochs);

  pos=file.find("VAR: input")-sizeof("VAR: input");
  file.replace(pos, sizeof("VAR: input"), data.input);

  pos=file.find("VAR: output")-sizeof("VAR: output");
  file.replace(pos, sizeof("VAR: output"), data.output);

  ofstream ofs;
  ofs.open(file_path, std::ofstream::out | std::ofstream::trunc);
  ofs.close();

  ofstream f;
  f.open(file_path);
  f<<file;
  f.close();
  return true;
}
void Graph::view_graph(string browser){
  system(browser+"file://"+swap_backslashes(file_path));
}
string Graph::swap_backslashes(string filepath){
  string result;
  for(int i=0; i<filepath.length(); i++){
    if filepath[i]=="\\"&&filepath[i+1]=="\\"{result+="/";}
    else{result+=filepath[i];}
  }
  return result;
}

static bool Graph::update_graph(data_struct* data, string file_path){
  ifstream f;
  f.open(file_path);
  string file;
  f>>file;
  f.close();

  size_t pos=file.find("VAR: project_name")-sizeof("VAR: project_name");
  file.replace(pos, sizeof("VAR: project_name"), data.project_name);

  pos=file.find("VAR: epochs")-sizeof("VAR: epochs");
  file.replace(pos, sizeof("VAR: epochs"), data.epochs);

  pos=file.find("VAR: input")-sizeof("VAR: input");
  file.replace(pos, sizeof("VAR: input"), data.input);

  pos=file.find("VAR: output")-sizeof("VAR: output");
  file.replace(pos, sizeof("VAR: output"), data.output);

  ofstream ofs;
  ofs.open(file_path, ofstream::out|ofstream::trunc);
  ofs.close();

  ofstream f;
  f.open(file_path);
  f<<file;
  f.close();
  return true;
}
static void Graph::view_graph(string file_path, string browser){
  system(browser+"file://"+swap_backslashes(file_path));
}
static string Graph::swap_backslashes(string file_path){
  string result;
  for(int i=0; i<filepath.length(); i++){
    if filepath[i]=="\\"&&filepath[i+1]=="\\"{result+="/";}
    else{result+=filepath[i];}
  }
  return result;
}
