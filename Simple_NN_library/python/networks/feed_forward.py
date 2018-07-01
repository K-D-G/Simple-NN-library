from Simple_NN_library.python.networks import*
from Simple_NN_library.python.functions import*
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

#               Fix this as C++ code was used that may not be accurate
#------------------------------------------------------------
        temp=[]
        delimeter="]]"
        pos=0
        index=0
        s=weight_data

        while s.find(delimeter)!=-1:
            pos=s.find(delimeter)
            temp[index]=s.substr(0, pos)
            index+=1
            s.erase(0, pos+len(delimeter))

        temp2=[]
        delimeter='['
        for i in range(len(temp)):
            pos=1
            index=0
            while temp[i].find(delimeter)!=-1:
                pos=temp[i].find(delimeter)
                temp2[i][index]=temp[i].substr(1, pos)
                index+=1
                temp[i].erase(1, pos+len(delimeter))

        temp3=[]
        for i in range(len(temp2)):
            temp3[i]=[]

            array_temp=temp2[i][1:-2]
            temp4=[]
            pos=0
            index=0
            delimeter="]"
            while array_temp.find(delimeter)!=-1:
                pos=array_temp.find(delimeter)
                temp4[index]=array_temp.substr(0, pos)
                index+=1
                array_temp.erase(0, pos+len(delimeter))

            for j in range(len(temp4)):
                temp4[j]=temp4[j][1:-2]

            temp5=[]
            delimeter=" "
            for j in range(len(temp4)):
                pos=0
                index=0
                while temp4[j].find(delimeter)!=-1:
                    pos=temp4[j].find(delimeter)
                    temp5[j][index]=temp4[j].substr(0, pos)
                    index+=1
                    temp4[j].erase(0, pos+len(delimeter))

            temp6=[]
            for j in range(len(temp5)):
                for x in range(len(temp5[i])):
                    temp6[j][x]=int(temp[j][x])

            for j in range(len(temp6)):
                temp3[i][j]=temp6[j]
        self.weights=temp3

        temp=[]
        delimeter="]]"
        pos=0
        index=0
        s=bias_data

        while s.find(delimeter)!=-1:
            pos=s.find(delimeter)
            temp[index]=s.substr(0, pos)
            index+=1
            s.erase(0, pos+len(delimeter))

        temp2=[]
        delimeter='['
        for i in range(len(temp)):
            pos=1
            index=0
            while temp[i].find(delimeter)!=-1:
                pos=temp[i].find(delimeter)
                temp2[i][index]=temp[i].substr(1, pos)
                index+=1
                temp[i].erase(1, pos+len(delimeter))

        temp3=[]
        for i in range(len(temp2)):
            temp3[i]=[]

            array_temp=temp2[i][1:-2]
            temp4=[]
            pos=0
            index=0
            delimeter="]"
            while array_temp.find(delimeter)!=-1:
                pos=array_temp.find(delimeter)
                temp4[index]=array_temp.substr(0, pos)
                index+=1
                array_temp.erase(0, pos+len(delimeter))

            for j in range(len(temp4)):
                temp4[j]=temp4[j][1:-2]

            temp5=[]
            delimeter=" "
            for j in range(len(temp4)):
                pos=0
                index=0
                while temp4[j].find(delimeter)!=-1:
                    pos=temp4[j].find(delimeter)
                    temp5[j][index]=temp4[j].substr(0, pos)
                    index+=1
                    temp4[j].erase(0, pos+len(delimeter))

            temp6=[]
            for j in range(len(temp5)):
                for x in range(len(temp5[i])):
                    temp6[j][x]=int(temp[j][x])

            for j in range(len(temp6)):
                temp3[i][j]=temp6[j]
        self.biasses=temp3

        self.activation_function=Activation_functions.get_func(activation_function_name)
        self.num_hiddenlayers=int(number_hl)

        npl_=npl
        temp_npl=[]
        index=0
        pos=0

        while npl_.find(delimeter)!=-1:
            pos=npl_.find(delimeter)
            temp_npl[index]=npl_.substr(0, pos)
            index+=1
            npl_.erase(0, pos+len(delimeter))

        temp_npl2=[]
        for i in range(len(temp_npl)):
            if temp_npl[i]=="]":break
            temp_npl2[i]=int(temp_npl[i])
        self.nodes_per_layer=temp_npl2
#------------------------------------------------------------
        self.setup_nodes(self.nodes_per_layer)
        return True

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
            else:
                log_file=open(text_file_path+"/"+name+".nn_log", 'w')
        while True:
            for i in training_data:
                output=self.use_network(i[0])
                result=self.backpropagation(output)
            if print_result:
                print(result)
            if text_file_path!=None:
                log_file.write(result)
        if text_file_path!=None:log_file.close()

    def calculate_layer(self, layer, inputs):
        outputs=[]
        for i in layer:
            outputs.append(i.calculate(inputs))
        return outputs

    def use_network(self, inputs):
        for i in self.nodes:
            inputs=self.calculate_layer(self.nodes[i], inputs)
        return inputs
