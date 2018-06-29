//Yes This is pythonic
//It is becuase python is my strongest language :)

//Utilities
#include <util.h>

//Extension of the C++ libraries
#include <further_maths.h>

//Loss functions
#include <functions/loss_functions/classification.h>
#include <functions/loss_functions/hinge.h>
#include <functions/loss_functions/other_functions.h>
#include <functions/loss_functions/regressive.h>

//Optimisers
#include <functions/optimisers/adam.h>
#include <functions/optimisers/SGD.h>

//Activation functions
#include <functions/activation_functions.h>

//The network types and the node
#include <networks/node.h>
#include <networks/feed_forward.h>

using namespace functions;
using namespace loss_functions;
using namespace optimisers;
using namespace networks;
using namespace std;
using namespace util;

string[][][] get_all(){
  int index=0;
  int type=0;
  string all[][][];

  all[type][i]={"Type: Loss functions"};
  i++;

  all[type][i]=_get_function_names(Classification);
  i++;

  all[type][i]=_get_function_names(Hinge);
  i++;

  all[type][i]=_get_function_names(Other_functions);
  i++;

  all[type][i]=_get_function_names(Regressive);
  i++;

  i=0;
  type++;
  all[type][i]={"Type: Activation functions"};
  i++;

  all[type][i]=_get_function_names(Activation_functions);
  i++;

  i=0;
  type++;
  all[type][i]={"Type: Networks"};
  i++;

  all[type][i]=_get_function_names(Node);
  i++;

  all[type][i]=_get_function_names(Feed_forward);
}


char* __version__="1.0";
char* __author__="K-D-G (https://k-d-g.github.io/ or https://github.com/K-D-G)";
string[][][] __all__=get_all();

give_util_data(__version__, __author__, __all__);
