


def read():
    f_obj = open('test.txt','r')
    file = f_obj.readlines()
    f_obj.close()
    return file

def append(new):
    f_obj = open('test.txt','a')
    file = f_obj.write(new+'\n')
    f_obj.close()
    return file

def update(line,text):
    file = read()
    f_obj = open('test.txt','w')
    for i,j in enumerate(file):
        if i==line:
            print(text)
            f_obj.write(text+'\n')
        else:
            f_obj.write(j)
    f_obj.close()
    return 0
