##
## EPITECH PROJECT, 2018
## PSU_2017_nmobjdump
## File description:
##        Makefile
##

all: nm objdump


objdump:
	make -C src-objdump/
	mv src-objdump/my_objdump ./
nm:
	make -C src-nm/
	mv src-nm/my_nm ./

re:
	make re -C src-nm/
	make re -C src-objdump/
	mv src-nm/my_nm ./
	mv src-objdump/my_objdump ./

clean:

	make clean -C src-nm/
	make clean -C src-objdump/

fclean:
	make fclean -C src-nm/
	make fclean -C src-objdump/
	rm -f my_nm my_objdump
