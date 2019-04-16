euler: euler.o
	gcc -o euler euler.o	
euler.o: euler.asm
	nasm -f elf64 -g -F stabs euler.asm
clean:
	rm *.o
	rm euler
run: euler
	/usr/bin/time -f "%e real, %U user, %S sys" ./euler
