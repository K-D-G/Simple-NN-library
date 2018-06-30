from .networks import Node
from .functions import Activation_functions
import random

class Feed_forward:
    def __init__(self, new_network=True, nodes_per_layer=None, activation_function=None):
        if new_network and nodes_per_layer!=None and activation_function!=None:
            self.num_hiddenlayers=len(nodes_per_layer)
            self.nodes_per_layer=nodes_per_layer
            self.set_activation(activation_function)
            self.set_weights_randomly()
            self.set_biasses_randomly()
            self.setup_nodes(nodes_per_layer)

    def set_weights(self, weights):
        self.weights=weights
        for i in range(len(self.nodes)):
            for j in range(len(self.nodes[i])):
                self.nodes[i][j].set_weights(self.weights[i][j])
        return True

    def set_biasses(self, biasses):
        self.biasses=biasses
        for i in range(len(self.nodes)):
            for j in range(len(self.nodes[i])):
                self.nodes[i][j].set_biasses(self.biasses[i][j])
        return True

    def set_activation(self, activation_function):
        self.activation_function=activation_function
        return True

    def set_weights_randomly(self):
        for i in range(len(self.weights)):
            for j in range(len(self.weights[i])):
                self.weights[i][j]=random.uniform(1, 100)
        return True

    def set_biasses_randomly(self):
        for i in range(len(self.biasses)):
            for j in range(len(self.biasses[i])):
                self.biasses[i][j]=random.uniform(0, 100)
        return True

    def setup_nodes(self, nodes_per_layer):
        self.nodes_per_layer=nodes_per_layer
        self.num_hiddenlayers=len(self.nodes_per_layer)

        for i in range(len(self.num_hiddenlayers)):
            for j in range(len(self.nodes_per_layer[i])):
                self.nodes[i][j]=Node(self.weightsi[i][j], self.biasses[i][j], self.activation_function)

    def save_network(self, path, name):
        network_file=open(path+"/"+name+".nn", "w")

        network_file.write('WEIGHTS\n')
        for i in range(len(self.weights)):
            network_file.write('[')
            for j in range(len(self.weights[i])):
                network_file.write('[')
                for x in range(len(self.weights[i][j])):
                    network_file.write(str(self.weights[i][j])+" ")
                network_file.write(']')
            network_file.write(']\n')
        network_file.write("END\n")

        network_file.write("BIASSES\n")
        for i in range(len(self.biasses)):
            network_file.write('[')
            for j in range(len(self.biasses[i])):
                network_file.write('[')
                for x in range(len(self.biasses[i][j])):
                    network_file.write(str(self.biasses[i][j])+" ")
                network_file.write("]")
            network_file.write(']\n')
        network_file.write("END\n")

        network_file.write("ACTIVATION FUNCTION: "+Activation_functions.get_func_name(self.activation_function)+"\n")
        network_file.write("NUM HIDDEN LAYERS: "+str(self.num_hiddenlayers)+"\n")

        network_file.write("NODES PER LAYER\n")
        network_file.write('[')
        for i in range(len(self.nodes_per_layer)):
            network_file.write(str(self.nodes_per_layer[i])+" ")
        network_file.write("]\n")
        network_file.write('END\n')

        network_file.write("ENDFILE\n")
        network_file.close()
        return True

    def load_network(self, full_path):
        weight_data=""
        bias_data=""
        activation_function_name=""
        number_hl=""
        npl=""

        try:
            network_file=open(full_path, "r")
        except Exception as e:
            print(str(e))
            return False

        data=network_file.readlines()
        network_file.close()

        for i in range(len(data)):
            if data[i:i+9]=="WEIGHTS\n":
                for j in range(i+9, len(data[i+9:])):
                    if data[j:j+3]=="END":
                        break
                    else:
                        weight_data=weight_data+data[j]
            elif data[i:i+9]=="BIASSES\n":
                for j in range(i+9, len(data[i+9:])):
                    if data[j:j+3]=="END":
                        break
                    else:
                        bias_data=bias_data+data[j]
            elif data[i:i+21]=="ACTIVATION FUNCTION: ":
                for j in range(i+21, len(data[i+21:])):
                    if data[j:j+2]=="\n":
                        break
                    else:
                        activation_function_name=activation_function_name+data[j]
            elif data[i:i+19]=="NUM HIDDEN LAYERS: ":
                for j in range(i+19, len(data[i+19:])):
                    if data[j:j+2]=="\n":
                        break
                    else:
                        number_hl=number_hl+data[j]
            elif data[i:i+15]=="NODES PER LAYER\n":
                for j in range(i+15, len(data[i+15:])):
                    if data[j:j+3]=="END":
                        break
                    else:
                        npl=npl+data[j]
            elif data[i:i+7]=="ENDFILE":
                break

        temp=[]
        delimeter="]]"
        pos=0
        index=0
        s=weight_data
        #Finish

    def backpropagation(self, output):
        pass

    def train(self, training_data, print_result=True, text_file_path=None, name=None):
        output=[]
        result=""
        if name!=None and text_file_path==None:
            print("You have not provided a path for the file therefore the result will not be recorded. However the network will still run\n")
            name=None
        if text_file_path!=None:
            if name==None:
                print("You have not provided a name for the text file therefore the result will not be recorded. However the network will still run\n")
                text_file_path=None
            else:log_file=open(text_file_path+"/"+name+".nn_log")
        while True:
            #Continue
            pass
