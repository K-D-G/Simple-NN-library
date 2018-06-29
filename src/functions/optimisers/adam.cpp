#include <functions/optimisers/adam.h>

using namespace std;
using namespace functions;
using namespace optimisers;
using namespace further_maths;


Adam::Adam(float learning_rate=0.001, float beta=0.9, float beta2=0.999, float decay=0){
  this.iterations=0;
  this.learning_rate=learning_rate;
  this.beta=beta;
  this.beta2=beta2;
  this.init_decay=decay;
  this.decay=decay;
  this.epsilon=epsilon();
}
Adam::~Adam(){

}

float[][2] Adam::update(float cost, float params[]=0){
  float updates[][2];
  gradients=make_array(0, (int)cost);
  float x=0;
  float it=x+1;
  float fix=(float)1-((float)1-this.beta)**it;
  float fix2=(float)1-((float)1-this.beta2)**it;
  float learning_rate_temp=this.learning_rate*(sqrt(fix2)/fix);

  float zip_result[][2]=zip(params, gradients);
  for(int i=0; i<sizeof(zip_result); i++){
    float p=zip_result[i][0];
    float g=zip_result[i][1];

    float mt=(this.beta*g)+(((float)1-this.beta)*p);
    float vt=(this.beta2*(g**2))+(((float)1-this.beta2)*g);
    float gt=mt/(sqrt(vt)+this.epsilon);
    float pt=p-(learning_rate_temp*gt);

    updates[i]={m, mt};
    updates[i+1]={v, vt};
    updates[i+2]={p, pt};
  }
  updates[i]={x, it};
  return updates;
}
struct* Adam::get_variables(){
  Adam_variables* vars;
  vars.iterations=this.iterations;
  vars.learning_rate=this.learning_rate;
  vars.beta=this.beta;
  vars.beta2=this.beta2;
  vars.init_decay=this.init_decay;
  vars.decay=this.decay;
  vars.epsilon=this.epsilon;
  return vars;
}
