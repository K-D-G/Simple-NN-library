from further_maths import*
import random

class SGD:
    def __init__(self, training_data, alpha=0.01):
        self.data=training_data
        self.alpha=alpha

    def update(self, error, weight_array):
        updates=[]
        batch=_new_random_batch(256)
        gradient=_get_gradient(error, batch)
        updates=add_constant(weight_array, (-self.alpha*gradient))
        return updates

    def _get_gradient(self, error, batch):
        return divide_arrays(dot_product(batch, error), 2+len(batch[0][0]))

    def _new_random_batch(batch_size, from_this_data=True):
        if(len(self.data)<=batch_size):
            return [[[0, 0]], [[0, 0]]]

        random_numbers=[]
        for i in range(batch_size):
            random_numbers.append(random.randint(0, batch_size))

        batch=[]
        for i in range(len(random_numbers)):
            batch[i]=self.data[random_numbers[i]]
        return batch

    def get_variables():
        return {
            'data':self.data,
            'alpha': self.alpha
        }
