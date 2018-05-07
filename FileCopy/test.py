import os
os.chdir('Debug')
#os.system('cd debug')
os.system('FileCopy.exe 1.txt 2.txt')
os.system('FileCopy.exe 3.txt 2.txt')
os.system('ping www.baidu.com')
raw_input("put any key to quit")