from zipfile import*
import os

def create_a_zip_file():
    name=input("What would you like to call it ")
    files=input("Which files would you like to enter into it ")
    zip_file=ZipFile(name, "w")
    if files=='current dir':
        current_directory=os.getcwd()
        file_names=os.listdir(current_directory)
        for i in file_names:
            try:
                check=os.path.isfile(i)
                if check==True:
                    zip_file.write(i)
                else:
                    print(i, "doesn't exist")
            except Exception as e:
                print(str(e))
    else:
        files=files.split(" ")
        for i in files:
            try:
                check=os.path.isfile(i)
                if check==True:
                    zip_file.write(i)
                else:
                    print(i, "doesn't exist")
            except Exception as e:
                print(str(e))
    zip_file.close()
    print("All files have been added")
def extract_from_a_zip_file():
    name=input("What file would you like to extract from ")
    files=input("Which files would you like to extract ")
    directory=input("What directory would you like to put the files in ")
    if files=='all':
        try:
            check=os.path.isfile(name)
            if check==True:
                zip_file=ZipFile(name, "r")
                data=zip_file.namelist()
                for i in data:
                    zip_file.extract(i, directory)
                print("All files have been extracted")
                zip_file.close()
            elif check==False:
                print(i ,"doesn't exsist")
            else:
                pass
        except Exception as e:
            print(str(e))
    else:
        try:
            check=os.path.isfile(name)
            if check==True:
                zip_file=ZipFile(name, "r")
                files=files.split(" ")
                for i in files:
                    zip_file.extract(i, directory)
                print("All files have been extracted")
                zip_file.close()
            elif check==False:
                print(i, "doesn't exsist")
            else:
                pass
        except Exception as e:
            print(str(e))
def run_script():
    choice=int(input("What would you like to do: 1=create a zip file 2=extract from a zip file "))
    if choice==1:
        create_a_zip_file()
    elif choice==2:
        extract_from_a_zip_file()
    else:
        run_script()
        
if __name__=='__main__':
    run_script()
