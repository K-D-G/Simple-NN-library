from Simple_NN_library.python.further_maths import*

class Other_functions:

    def get_func_name(self, func):
        self.list_of_functions=[self.log_cosh, self.kullback_leibler_divergence, self.poisson, self.cosine_proximity]
        func_name="unknown"
        if func==self.list_of_functions[0]:func_name="log cosh"
        elif func==self.list_of_functions[1]:func_name="kullback leibler divergence"
        elif func==self.list_of_functions[2]:func_name="poisson"
        elif func==self.list_of_functions[3]:func_name="cosine proximity"
        return func_name

    def get_func(self, name):
        self.list_of_functions=[self.log_cosh, self.kullback_leibler_divergence, self.poisson, self.cosine_proximity]
        if name=="log cosh":return self.list_of_functions[0]
        elif name=="kullback leibler divergence":return self.list_of_functions[1]
        elif name=="poisson":return self.list_of_functions[2]
        elif name=="cosine proximity":return self.list_of_functions[3]

    def log_cosh(self, output, expected_output):
        return mean(self.actual_cosh(subtract_arrays(output, expected_output)))

    def actual_cosh(self, x):
        return sum([x, subtract_arrays(this._softplus(multiply_arrays(make_array(-2, len(x)), x)), array_log(make_array(2, len(x))))])

    def _softplus(self, x):
        result=[]
        for i in x:
            result.append(ln(1+e**x[i]))
        return result

    def kullback_leibler_divergence(self, output, expected_output):
        return sum(multiply_arrays(expected_output, array_log(divide_arrays(expected_output, output))))

    def poisson(self, output, expected_output):
        return mean(subtract_arrays(output, multiply_arrays(expected_output, array_log(add_constant(output, epsilon())))))

    def cosine_proximity(self, output, expected_output):
        return -sum(multiply_arrays(expected_output, output))
