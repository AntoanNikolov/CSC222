### Intro  
- Makefiles are used to help decide which parts of a large program need to be recompiled  
- A Makefile consists of a set of rules. A rule generally looks like this:
```targets: prerequisites
	command
	command
	command
```  
- The targets are file names, commands are series of steps (must start with a tab character)  
    - The prerequisites are also file names, separated by spaces. These files need to exist before the commands for the target are run. These are also called dependencies
    - in other words, the target is the file you create through compilation commands, the prerequisite is the context for that
- make clean will never run unless you explicitly call ``` make clean ```  
    - you'd use make to create something, and then make clean to delete something  
### Variables can only be strings  
- Variables can only be strings. You'll typically want to use :=, but = also works
```blah: blah.o
	cc blah.o -o blah # Runs third

blah.o: blah.c
	cc -c blah.c -o blah.o # Runs second

# Typically blah.c would already exist, but I want to limit any additional required files
blah.c:
	echo "int main() { return 0; }" > blah.c # Runs first
```  
### The all target  
- ```all targets``` are for when you have multiple targets and you want all of them to run. Since this is the first rule listed, it will run by default if make is called without specifying a target.  
``` all: one two three

one:
	touch one
two:
	touch two
three:
	touch three

clean:
	rm -f one two three
```
### Wildcards  
#### * Wildcard
- ```*``` searches for files. Example: *.cpp will find all cpp files.  
- Danger: ```*``` may not be directly used in a variable definitions  
- Danger: When ```*``` matches no files, it is left as it is (unless run in the wildcard function)  
```
thing_wrong := *.o # Don't do this! '*' will not get expanded
thing_right := $(wildcard *.o)

all: one two three four

# Fails, because $(thing_wrong) is the string "*.o"
one: $(thing_wrong)

# Stays as *.o if there are no files that match this pattern :(
two: *.o 

# Works as you would expect! In this case, it does nothing.
three: $(thing_right)

# Same as rule three
four: $(wildcard *.o)
```  
#### % Wildcard  
- When used in "matching" mode, it matches one or more characters in a string. This match is called the stem.
- When used in "replacing" mode, it takes the stem that was matched and replaces that in a string.
- ```%``` is most often used in rule definitions and in some specific functions.
### Automatic Variables
```
hey: one two
	# Outputs "hey", since this is the target name
	echo $@

	# Outputs all prerequisites newer than the target
	echo $?

	# Outputs all prerequisites
	echo $^

	# Outputs the first prerequisite
	echo $<

	touch hey

one:
	touch one

two:
	touch two

clean:
	rm -f hey one two
```
### Default bash  
- The default shell is /bin/sh. You can change this by changing the variable SHELL:  
'''SHELL=/bin/bash'''  
### Error handling
- Add -k when running make to continue running even in the face of errors. Helpful if you want to see all the errors of Make at once.
- Add a - before a command to suppress the error
- Add -i to make to have this happen for every command.
### Recursive use of make
- To recursively call a makefile, use the special $(MAKE) instead of make because it will pass the make flags for you and won't itself be affected by them.
### Export, environments, recursive make  
- When Make starts, it automatically creates Make variables out of all the environment variables that are set when it's executed.
- The export directive takes a variable and sets it the environment for all shell commands in all the recipes:  
``` shell_env_var=Shell env var, created inside of Make
export shell_env_var
all:
	echo $(shell_env_var)
	echo $$shell_env_var
```  
### Conditionals  
- Conditional if/else
```
foo = ok

all:
ifeq ($(foo), ok)
	echo "foo equals ok"
else
	echo "nope"
endif
```  
- Check if a variable is empty
```
nullstring =
foo = $(nullstring) # end of line; there is a space here

all:
ifeq ($(strip $(foo)),)
	echo "foo is empty after being stripped"
endif
ifeq ($(nullstring),)
	echo "nullstring doesn't even have spaces"
endif
```  
- Check if a variable is defined
```
bar =
foo = $(bar)

all:
ifdef foo
	echo "foo is defined"
endif
ifndef bar
	echo "but bar is not"
endif
```
### Functions  
- functions are mainly used for processing text
- Call functions with ```$(fn, arguments)``` or ```${fn, arguments}```.