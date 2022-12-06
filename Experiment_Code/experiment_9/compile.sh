cd show
gcc -fPIC -c getCommand_parse.c
gcc -fPIC -c getCommand_readKey.c
gcc -fPIC -c showPrompt.c
gcc -shared -o libshow.so getCommand_parse.o getCommand_readKey.o showPrompt.o
cp libshow.so ../
cd ../process
gcc -fPIC -c fork.c
gcc -fPIC -c index_of_pipe.c
gcc -fPIC -c parent_process.c
gcc -shared -o libprocess.so fork.o parent_process.o index_of_pipe.o
cp libprocess.so ../
cd ../
export LD_LIBRARY_PATH=.
gcc Main.c -o google_future_shell -L. -lprocess -lshow


