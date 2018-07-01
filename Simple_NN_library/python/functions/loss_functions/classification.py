from Simple_NN_library.python.further_maths import*

class Classification:

    def get_func_name(self, func):
        self.list_of_functions=[self.binary_cross_entropy, self.negative_log_likelihood]
        func_name="unknown"
        if func==self.list_of_functions[0]:func_name="binary cross entropy"
        elif func==self.list_of_functions[1]:func_name="negative log likelihood"
        return func_name

    def get_func(self, name):
        self.list_of_functions=[self.binary_cross_entropy, self.negative_log_likelihood]
        if name=="binary cross entropy":return self.list_of_functions[0]
        elif name=="negative log likelihood":return self.list_of_functions[1]

    def binary_cross_entropy(self, output, expected_output):
        x=output
        z=expected_output

        result=0

        for i in range(len(x)):
            result+=x[i]*log(z[i])+(1-x[i])*log(1-z[i])
        return -result

    def negative_log_likelihood(self, output, expected_output):
        result=0
        for i in expected_output:
            result+=-log(i)
        return result
