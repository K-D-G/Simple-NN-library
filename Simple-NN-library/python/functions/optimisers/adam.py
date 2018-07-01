from further_maths import*

class Adam:
    def __init__(self, learning_rate=0.001, beta=0.9, beta2=0.999, decay=0):
        self.iterations=0
        self.learning_rate=learning_rate
        self.beta=beta
        self.beta2=beta2
        self.init_decay=decay
        self.decay=decay
        self.epsilon=epsilon()

    def update(self, cost, params=[]):
        updates=[]
        gradients=make_array(0, int(cost))
        x=0
        it=x+1
        fix=float(1)-(float(1)-self.beta)**it
        fix2=float(1)-(float(1)-self.beta2)**it
        learning_rate_temp=self.learning_rate*(sqrt(fix2)/fix)

        zip_result=zip(params, gradients)
        for i in range(len(zip_result)):
            p=zip_result[i][0]
            g=zip_result[i][1]

            mt=(self.beta*g)+((float(1)-self.beta)*p)
            vt=(self.beta2*(g**2))+((float(1)-self.beta2)*g)
            gt=mt/(sqrt(vt)+self.epsilon)
            pt=p-(learning_rate_temp*gt)

            updates.append((m, mt))
            updates.append((v, vt))
            updates.append((p, pt))
        updates.append((i, it))
        return updates

    def get_variables(self):
        return {
        'iterations':self.iterations,
        'learning_rate':self.learning_rate,
        'beta':self.beta, 'beta2':self.beta2,
        'init_decay':self.init_decay,
        'decay':self.decay,
        'epsilon':self.epsilon
        }
