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