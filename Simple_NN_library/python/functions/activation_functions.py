from Simple_NN_library.python.further_maths import*

class Activation_functions:

    def get_func_name(self, func):
        self.list_of_functions=[self.sigmoid, self.tanh, self.ReLU, self.softmax]
        func_name="unknown"
        if func==self.list_of_functions[0]:func_name="sigmoid"
        elif func==self.list_of_functions[1]:func_name="tanh"
        elif func==self.list_of_functions[2]:func_name="ReLU"
        elif func==self.list_of_functions[3]:func_name="softmax"
        return func_name

    def get_func(self, name):
        self.list_of_functions=[self.sigmoid, self.tanh, self.ReLU, self.softmax]
        if name=="sigmoid":return this.list_of_functions[0]
        elif name=="tanh":return this.list_of_functions[1]
        elif name=="ReLU":return this.list_of_functions[2]
        elif name=="softmax":return this.list_of_functions[3]

    def sigmoid(self, x):
        return 1/1+exp(-x)

    def tanh(self, x):
        return exp(2*x)+1/exp(2*x)-1

    def ReLU(self, x):
        if(x<=0):return float(0)
        else:return x

    def softmax(self, inputs):
        inputs_exp=[]
        for i in inputs:
            inputs_exp.append(exp(i))

        sum_inputs_exp=float(sum(inputs_exp))

        result=[]
        for i in inputs_exp:
            result.append(inputs_exp[i]/sum_inputs_exp)
        return result
