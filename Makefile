# C compiler
CC=/usr/bin/gcc



# Output Path
OUT=./Bin


# Prefix Path
PREFIX=/usr/local


# Additionary Sources Path
F= ../Functions
M= ../Menus
I= ../ntegrals
R= ../Roots

VPATH =${F} ${M} ${I} ${R}


# Software Name
NAME=num_diploma


# Compiler Flags:
# -O3  =>  Maximum Optimisation Level
# -finline_functions =>  Consider All Functions For Inlining
# -findirect-inlining => 
# -fexpensive-optimizations => Add More Minor TIme Consuming Optimisations
# -g => Adds Debug Informations To The Executable File
# -Wall => Turns On Most Of Compiler Warnings
# -iquote => Add The Following Dir To The Source Code Path
CFLAGS=-O3 -finline-functions -findirect-inlining -fexpensive-optimizations #-g -Wall


# Add Math Library
LIB=-lm


# Functions Source Code Files
FUNCTIONS=./Functions/convergence.c ./Functions/function.c ./Functions/deriv1.c ./Functions/deriv2.c ./Functions/deriv4.c 
MENUS=./Menus/menu_function.c ./Menus/menu_root.c ./Menus/menu_integ.c
INTEGRALS=./Integrals/integ_rect.c ./Integrals/integ_trap.c ./Integrals/integ_cav_simpson.c
ROOTS=./Roots/dicotomic.c ./Roots/cords.c ./Roots/newton.c

SOURCE=num_diploma.c ${FUNCTIONS} ${MENUS} ${INTEGRALS} ${ROOTS}


# Make
all:
	${CC} -o ${OUT}/${NAME} ${SOURCE} ${CFLAGS} ${LIB}
	
clean:
	-rm -f ${NAME}
	-rm -f ${OUT}/${NAME}

install:
	install -s ${OUT}/${NAME} ${PREFIX}/bin

uninstall:
	-rm -f ${PREFIX}/bin/${NAME}
