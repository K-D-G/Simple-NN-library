from .further_maths import*
from functions.activation_functions import*

class Node:
    def __init__(self, weights, biasses, activation_function):
        self.set_weights(weights)
        self.set_biasses(biasses)
        self.set_activation(activation_function)

    def formula(self, calculation_array):
        total=0
        for i in calculation_array:
            total+=(i[0]*i[1])+i[2]
        return total

    def calculate(self, inputs):
        if(len(inputs)!=len(self.weights) or len(inputs)!=len(biasses)):
            return None

        calculation_array=[]
        for i in range(len(inputs)):
            calculation_array[i]=[inputs[i], self.weights[i], self.biasses[i]]

        calculation_result=sum(self.formula(calculation_array))
        return self.activation_function(calculation_result)

    def set_weights(self, weights):
        self.weights=weights

    def set_biasses(self, biasses):
        self.biasses=biasses

    def set_activation_function(self, activation_function):
        for i in range(len(Activation_functions.list_of_functions)):
            if(Activation_functions.list_of_functions[i]==activation_function):
                self.activation_function=activation_function
                return True
        return False
