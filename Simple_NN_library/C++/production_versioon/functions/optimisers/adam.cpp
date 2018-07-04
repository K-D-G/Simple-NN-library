#include "adam.h"

using namespace Simple_NN_library;
using namespace std;
using namespace functions;
using namespace optimisers;
using namespace further_maths;


Adam::Adam(float learning_rate_, float beta_, float beta2_, float decay_){
  iterations=0;
  learning_rate=learning_rate_;
  beta=beta_;
  beta2=beta2_;
  init_decay=decay_;
  decay=decay_;
  epsilon=get_epsilon();
}
Adam::~Adam(){

}

float** Adam::update(float cost, float* params){
  float** updates;
  float gradients=2*cost-4;
  float x=0;
  float it=x+1;
  float fix=(float)1-pow(((float)1-beta), it);
  float fix2=(float)1-pow(((float)1-beta2), it);
  float learning_rate_temp=learning_rate*(sqrt(fix2)/fix);

  float** zip_result=zip(params, make_array(gradients, sizeof(params)));
  int index=0;
  for(int i=0; i<sizeof(zip_result); i++){
    float p=zip_result[i][0];
    float g=zip_result[i][1];

    float mt=(beta*g)+(((float)1-beta)*p);
    float vt=(beta2*(g*g))+(((float)1-beta2)*g);
    float gt=mt/(sqrt(vt)+epsilon);
    float pt=p-(learning_rate_temp*gt);

    //updates[i]={m, mt};
    updates[i][0]=p;
    updates[i][1]=mt;

    updates[i+1][0]=g;
    updates[i+1][1]=vt;

    updates[i+2][0]=p;
    updates[i+2][1]=pt;
    index=i;
  }
  updates[index+3][0]=x;
  updates[index+3][1]=it;
  return updates;
}
Adam_variables* Adam::get_variables(){
  Adam_variables* vars;
  vars->iterations=iterations;
  vars->learning_rate=learning_rate;
  vars->beta=beta;
  vars->beta2=beta2;
  vars->init_decay=init_decay;
  vars->decay=decay;
  vars->epsilon=epsilon;
  return vars;
}
