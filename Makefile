CC=gcc
PREFIX=/usr/local

all:
	${CC} -o num_diploma num_diploma.c convergence.c function.c deriv1.c deriv2.c deriv4.c dicotomic.c cords.c newton.c integ_rect.c integ_trap.c integ_cav_simpson.c menu_function.c menu_root.c menu_integ.c -lm
clean:
	-rm -f num_diploma
install:
	install -s num_diploma ${PREFIX}/bin
uninstall:
	-rm -f ${PREFIX}/bin/num_diploma
