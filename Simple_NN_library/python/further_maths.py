import math

def epsilon():
    return 1e-7

def sum(arr):
    total=0
    for i in arr:
        total+=arr
    return total

def add_constant(arr, constant):
    result=[]
    for i in arr:
        result.append(i+constant)
    return result

def subtract_arrays(arr, arr2):
    result=[]
    for i in range(len(arr)):
        result.append(arr[i]-arr2[i])
    return result

def subtract_constant(arr, constant):
    result=[]
    for i in arr:
        result.append(i-constant)
    return result

def square_array(arr):
    result=[]
    for i in arr:
        result.append(i**2)
    return result

def array_abs(arr):
    result=[]
    for i in arr:
        result.append(abs(i))
    return result

def multiply_arrays(arr, arr2):
    result=[]
    for i in range(len(arr)):
        result.append(arr[i]*arr2[i])
    return result

def mean(arr):
    divide_operand=len(arr)
    total=0
    for i in arr:
        total+=i
    return total/divide_operand

def divide_arrays(arr, arr2):
    result=[]
    for i in range(len(arr)):
        result.append(arr[i]/arr2[i])
    return result

def array_log(arr):
    result=[]
    for i in arr:
        result.append(math.log10(i))
    return result

def maximum(arr):
    result=[]
    for i in range(len(arr)):
        for j in range(len(arr[i])):
            if result[j]<arr[i][j]:result[j]=arr[i][j]
    return result

def max(arr):
    result=0
    for i in arr:
        result*=(1-i)
    return 1-result

def make_array(number, size):
    result=[]
    for i in range(size):
        result.append(number)
    return result

def ln(x):
    return math.log(x)

def sqrt(x):
    return x**0.5

def dot_product(batch, error):
    result=[]
    for i in range(len(batch)):
        for j in range(len(batch[i])):
            for x in range(len(batch[i][j])):
                result[i][j][x]=batch[i][j][x]*error
    return result

def constrain(x, y, z):
    if x<y:return y
    elif x>z:return z
    return x
