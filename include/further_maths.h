#ifndef __FURTHER_MATHS_H
#define __FURTHER_MATHS_H
#include <cmath>

float sum(float array[]){
  float total=0;
  for(int i=0; i<sizeof(array); i++){
    total+=array[i];
  }
  return total;
}

float[] subtract_arrays(float arr[], float arr2[]){
  float result[];
  for(int i=0; i<sizeof(arr); i++){
    result[i]=arr[i]-arr2[i];
  }
  return result;
}

float[] square_array(float arr[]){
  float result[];
  for(int i=0; i<sizeof(arr); i++){
    result[i]=arr**2;
  }
  return result;
}

float[] array_abs(float arr[]){
  float result[];
  for(int i=0; i<sizeof(arr); i++){
    result[i]=std::abs(arr[i]);
  }
  return result;
}

float mean(float arr[]){
  int divide_operand=sizeof(arr);
  float total=0;
  for(int i=0; i<sizeof(arr); i++){
    total+=arr[i];
  }
  return total/divide_operand;
}
#endif
