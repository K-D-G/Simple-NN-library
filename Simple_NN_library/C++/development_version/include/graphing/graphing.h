#ifndef GRAPHING__GRAPHING_H
#define GRAPHING__GRAPHING_H
#include <string>
#include <fstream>
namespace Simple_NN_library{
  namespace graphing{
    class Graph{
    public:
      std::string file_path;

      Graph(data_struct* data, std::string filepath);
      bool update_graph(data_struct* data);
      void view_graph(std::string browser);
      std::string swap_backslashes(std::string filepath);

      static bool update_graph(data_struct* data, std::string file_path);
      static void view_graph(std::string file_path, std::string browser);
      static std::string swap_backslashes(std::string file_path);

    };
  }
}
#endif
