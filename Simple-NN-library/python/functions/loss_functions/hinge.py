from further_maths import*

class Hinge:

    def get_func_name(self, func):
        self.list_of_functions=[self.hinge, self.squared_hinge, self.categorical_hinge]
        func_name="unknown"
        if func==self.list_of_functions[0]:func_name="hinge"
        elif func==self.list_of_functions[1]:func_name="squared hinge"
        elif func==self.list_of_functions[2]:func_name="categorical hinge"
        return func_name

    def get_func(self, name):
        self.list_of_functions=[self.hinge, self.squared_hinge, self.categorical_hinge]
        if name=="hinge":return self.list_of_functions[0]
        elif name=="squared hinge":return self.list_of_functions[1]
        elif name=="categorical hinge":return self.list_of_functions[2]

    def hinge(self, output, expected_output):
        return mean(maximum([subtract_arrays(make_array(1, len(output)), multiply_arrays(expected_output, output)), make_array(0, len(output))]))

    def squared_hinge(self, output, expected_output):
        return mean(square_array(maximum([subtract_arrays(make_array(1, len(output)), multiply_arrays(expected_output, output)), make_array(0, len(output))])))

    def categorical_hinge(self, output, expected_output):
        return maximum(make_array(0, len(output)), subtract_constant(max(subtract_arrays(make_array(1, len(output)), expected_output), output), sum(multiply_arrays(expected_output, output))+1))
