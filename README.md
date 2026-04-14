# File Manager (C)

a simple file manager that you can use it to navigate
through the shell and its use is amlost the same as bash

---

## Features
- changing directorys
- creating directorys
- deleting directorys
- creating files
- deleting files
- seeing the contents of a file
- copying files
- seeing the current directory path
- clearing the terminal
- printing messages for fun (echo)

---

## Requirments:
`gcc` compiler `git` and `GNU MAKE`

### Get the reposetory:
```bash
git clone https://github.com/skinwalker3654/file-manager
cd file-manager
```

### build and run:
```bash
make 
./file_manager
```

### when you want to delete the executable:
```bash
make clean
```

### if you want to install it on your system so you can use it everywere
```bash
make install
```

### and to remove if from your system you run
```bash
make remove
```

---

## SCREENSHOT
![alt text](https://github.com/skinwalker3654/file-manager/blob/main/.github/screenshot.png?raw=true)

---

## extending the functionality of the program is simple

you should think with this way.
is the new function a `util function` or an `operation function`?

if its a util function then you define it to **include/util.h**
and the source code is puted on **src/util.c**

if the function is an operation function then you define it to **include/operations.h**
and the source code goes to **src/operations.c**

when you add your new operation then you go to then of the execte_command function on **src/executer.c**
and do call the operation when the command is called. See how the other operations are handled and do the same with your new one

and at the end you should write a simple description and the syntax of the command on the print_help function from **src/util.c**
# file-manager
