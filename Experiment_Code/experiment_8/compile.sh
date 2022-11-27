cd process
gcc -fPIC -c getCommand_parse.c
gcc -fPIC -c getCommand_readKey.c
gcc -fPIC -c showPrompt.c
gcc -shared -o libprocess.so getCommand_parse.o getCommand_readKey.o showPrompt.o
cp libprocess.so ../
cd ../show
gcc -fPIC -c childDo.c
gcc -fPIC -c parentDo.c
gcc -shared -o libshow.so childDo.o parentDo.o
cp libshow.so ../
cd ../
export LD_LIBRARY_PATH=.
gcc Main.c -o our_shell -L. -lprocess -lshow


