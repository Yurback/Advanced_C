1 Step: create a object file for library
gcc -c StringFunctions.c -o lib_stringfunctions.o

2 Step: create a archiv of static library
ar rcs lib_stringfunctions.a lib_stringfunctions.o

3 Step: assembly an object file for driver 
(-I ../Lib/ - для  head file, можно указать в с_срр_properties.json)
gcc -I ../l/  -c main.c -o main.o

3.1 Step Linking with static library
gcc -g -Wall main.c l../l/ -o main


3+3.1 is able to do through 1 command
gcc -g -Wall -I ../Lib/  main.c  ../l/lib_stringfunctions.a -o main
