# C compiler
CC=gcc

PREFIX=/usr/local

NAME=num_diploma

# Compiler Flags:
# -O3  =>  Maximum Optimisation Level
# -finline_functions =>  Consider All Functions For Inlining
# -findirect-inlining => 
# -fexpensive-optimizations => Add More Minor TIme Consuming Optimisations
# -g => Adds Debug Informations To The Executable File
# - Wall => Turns On Most Of Compiler Warnings
CFLAGS=-O3 -finline-functions -findirect-inlining -fexpensive-optimizations -g -Wall

# Add Math Library
LIB=-lm

# C Source Code Files To Compile
SOURCE=num_diploma.c convergence.c function.c deriv1.c deriv2.c deriv4.c dicotomic.c cords.c newton.c integ_rect.c integ_trap.c integ_cav_simpson.c menu_function.c menu_root.c menu_integ.c

all:
	${CC} -o ${NAME}  ${SOURCE} ${CFLAGS} ${LIB}
clean:
	-rm -f ${NAME}
install:
	install -s ${NAME} ${PREFIX}/bin
uninstall:
	-rm -f ${PREFIX}/bin/${NAME}
