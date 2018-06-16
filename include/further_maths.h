#ifndef __FURTHER_MATHS_H
#define __FURTHER_MATHS_H


float sum(float array[]){
  float total=0;
  for(int i=0; i<sizeof(array); i++){
    total+=array[i];
  }
  return total;
}
