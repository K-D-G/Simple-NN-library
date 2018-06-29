#ifndef __UTIL_H
#define __UTIL_H
#include <stdio.h>

char* __version__;
char* __author__;
std::string __all__[][][]

void give_util_data(char* version, char* author, std::string all[][][]){
  __version__=version;
  __author__=author;
  __all__=all;
}

std::string[] _get_function_names(class* class_object){
  std::string result[];

  float* function_list=class_object.list_of_functions;
  for(int i=0; i<sizeof(function_list); i++){
    result[i]=class_object.get_func_name(function_list[i]);
  }
  return result;
}

int help(){
  printf("Version: %s\n", __version__);
  printf("Author: %s\n", __author__);
  printf("All functions and classes\n");
  printf("%s\n", __all__);
  return 0;
}

#endif
