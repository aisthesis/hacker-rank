# Call using program name as argument.
# Example:
# > make hello
# This command will compile 'src/hello.c' and create
# an executable file, 'bin/hello'
#
# Debugging with gdb:
# First, you have to add debugging support while compiling:
# > gcc -Wall -g src/hello.c -o bin/hello
# 
# Second, you have to codesign the binary:
# > codesign -s gdb-cert bin/hello
# Then confirm with root that gdb-cert should be granted 
# the appropriate privileges.
# 
# Third, debug:
# > gdb
# (gdb) file bin/hello
vpath %.c src

%: %.c
	gcc -Wall $< -o bin/$@
