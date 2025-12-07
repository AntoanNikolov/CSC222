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
