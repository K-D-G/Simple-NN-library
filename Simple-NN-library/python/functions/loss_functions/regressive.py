from further_maths import*

class Regressive:

    def get_func_name(self, func):
        self.list_of_functions=[self.mean_square_error, self.absolute_error, self.mean_absolute_percentage_error, self.mean_squared_logarithmic_error]
        func_name="unknown";
        if func==self.list_of_functions[0]:func_name="mean square error"
        elif func==self.list_of_functions[1]:func_name="absolute error"
        elif func==self.list_of_functions[2]:func_name="mean absolute percentage error"
        elif func==self.list_of_functions[3]:func_name="mean squared logarithmic error"
        return func_name

    def get_func(self, name):
        self.list_of_functions=[self.mean_square_error, self.absolute_error, self.mean_absolute_percentage_error, self.mean_squared_logarithmic_error]
        if name=="mean square error":return self.list_of_functions[0]
        elif name=="absolute error":return self.list_of_functions[1]
        elif name=="mean absolute percentage error":return self.list_of_functions[2]
        elif name=="mean squared logarithmic error":return self.list_of_functions[3]

    def mean_square_error(self, output, expected_output):
        return mean(square_array(subtract_arrays(output, expected_output)))

    def absolute_error(self, output, expected_output):
        return mean(array_abs(subtract_arrays(output, expected_output)))

    def mean_absolute_percentage_error(self, output, expected_output):
        result=[]
        for i in range(len(output)):
            result.append(abs((expected_output[i]-output[i])/expected_output[i]))
        return (100/len(output))*sum(result)

    def mean_squared_logarithmic_error(self, output, expected_output):
        return mean(square_array(subtract_arrays(array_log(output), array_log(expected_output))))
