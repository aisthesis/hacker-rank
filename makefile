# Call using program name as argument.
# Example:
# > make hello
# This command will compile 'src/hello.c' and create
# an executable file, 'bin/hello'
vpath %.c src

%: %.c
	gcc -Wall $< -o bin/$@
