# About the Project
The project is to implement transform from high-level language Ada to high-level language C or others. It is the author's undergraduate graduation design.

## TimeLine

- 2023.10.1 ~ 2023.10.31: rganize Ada Synatx Grammer and Write cases.  
- 2023.11.1 ~ 2023.11.31: build benchmark of the program.
- 2023.12.1 ~ 2023.12.31: explore the implement frame of Ada to C.
- 2024.1.1 ~ 2024.1.31: try to implement the synax analysize of Ada to Ast.
- 2024.2.1 ~ 2024.2.15: try to implement the translate from Ada to ir.
- 2024.2.16 ~ 2024.2.29: try to implement the translation from Ada to C.

## How to Run Cases

```shell
# 1. git clone the repo
git clone 
# 2. If you want to run all Ada procedures in PhaseOne_Case directory.
make testadb
# 3. If you want to run all cases with our Ada2Compiler in PhaseOne_Case directory.
make test-all
# 4. If you want to run case in example directory(you can design your program in it).
make run
# 5. If you want to run case with our Ada2Compiler in example directory(you can design your program in it).
make test-example
# 6. clean all output
make clean-all
```

## Todo AND List

### PhaseOne Features

- procedure
- if
- for 
- while
- case
- var
- Interger
- comment

PhaseOne will not include grammar like input and output. Just exercise!

### Benchmark of Ada grammar Cases:
- [x] print
- [x] if else
- [x] loop
- [x] switch case
- [x] function
- [x] expression
- [x] nest
- [x] declare and define
- [x] week
- [x] package
- [x] self-define-type
- [x] integer
- [x] float
- [x] enum
- [ ] derived type
- [ ] subtypes
- [ ] record
- [ ] array
- [ ] index
- [ ] String
- [ ] aggregate
- [ ] Character
- [ ] Point
- [ ] allocation
- [ ] dereferencing
- [ ] dynamically sized
- [ ] discriminant
- [ ] variant records
- [ ] fixed-point type
- [ ] encapsulation
- [ ] abstract data types
- [ ] generi
- [ ] exceptions
- [ ] tasking
- [ ] protected object
- [ ] pre- and postconditions
- [ ] interfacing with C
- [ ] Standard library