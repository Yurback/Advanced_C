1 Step: create a shared object file for library
gcc -g -fPIC StringFunctions.c -shared -o lib_stringfunctions.so



2 Step: assembly an object file for driver 
(-I ../Lib/ - для  head file, чтобы не подчеркивал VSCODE - можно указать в с_срр_properties.json)
gcc -I ../Lib/  -c main.c -o main.o


2.1 Step Linking with static library
gcc -o main main.o -L ../D_lib/ -l _stringfunctions


2+2.1 is able to do through 1 command
gcc -g -Wall -I ../Lib/  main.c  ../D_lib/lib_stringfunctions.so -o main

### 
Если ./main не запускается нужно прописать в терминале
export LD_LIBRARY_PATH=/home/yurback/C_projects/Advanced_C/ASSIGNMENTS/20_Challenge_Dynamic_lib/D_lib:$LD_LIBRARY_PATH