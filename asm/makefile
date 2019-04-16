euhler: euhler.o
	gcc -o euhler euhler.o	
euhler.o: euhler.asm
	nasm -f elf64 -g -F stabs euhler.asm
clean:
	rm *.o
	rm euhler
run: euhler
	/usr/bin/time -f "%e real, %U user, %S sys" ./euhler
