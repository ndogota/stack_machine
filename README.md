# stack_machine

> AVM interpreter connected to a stack machine implementation with linked list in c language

### Required

* Make
* GCC

### Explication

We have the program cuted in three part : 

* The first one is the file dumper : lines.c
* The second is the interpreter where we have functions being called : core.c
* The third is the file where we have linked list function : linked.c

> The program starts reading the file in the album folder, after he analyze the syntax he start to call functions from the linked list.

### Use

To make the compilable start the make command (calling the Makefile) :

```
$ make
```

You just have to launch the executable and give the path of the AVM file to interpret.

```
$ ./abstractvm avm/example.avm
```
