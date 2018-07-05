import webbrowser

class Graph:
    #Data is a dictionary
    def __init__(self, data, file_path):
        self.file_path=file_path

        f=open(self.file_path, 'w')

        template=open('template.html', 'r')
        f.write(template.readlines())
        template.close()
        f.close()

        self.update_graph(data)

    def update_graph(self, data):
        try:
            f=open(self.file_path, 'r+')
            file=f.readlines()
        except Exception as E:
            print(str(e))
            return False

        file.replace("VAR: project_name", data['project_name'])
        file.replace("VAR: epochs", data['epochs'])
        file.replace("VAR: input", data['input'])
        file.replace("VAR: output", data['output'])

        f.seek(0)
        f.truncate()

        f.write(file)
        f.close()
        return True

    def view_graph(self):
        return webbrowser.open('file://'+str(self.swap_backslashes(self.file_path)))

    def swap_backslashes(self, file_path):
        result=""
        for i in range(len(file_path)):
            if file_path[i:i+1]=="\\":result+="/"
            else:result+=file_path[i]
        return result

    @staticmethod
    def update_graph(self, data, file_path):
        try:
            f=open(file_path, 'r+')
            file=f.readlines()
        except Exception as E:
            print(str(e))
            return False

        file.replace("VAR: project_name", data['project_name'])
        file.replace("VAR: epochs", data['epochs'])
        file.replace("VAR: input", data['input'])
        file.replace("VAR: output", data['output'])

        f.seek(0)
        f.truncate()

        f.write(file)
        f.close()
        return True


    @staticmethod
    def view_graph(self, file_path):
        return webbrowser.open('file://'+str(Graph.swap_backslashes(file_path)))

    @staticmethod
    def swap_backslashes(self, file_path):
        result=""
        for i in range(len(file_path)):
            if file_path[i:i+1]=="\\":result+="/"
            else:result+=file_path[i]
        return result
