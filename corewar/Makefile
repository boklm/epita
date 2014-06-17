all:
	(cd kasm; make; mv asm ../asm)
	(cd vm; make; mv corewar ../corewar)

clean:
	rm -f *~ \#*
	(cd kasm; make clean)
	(cd vm; make clean)

distclean: clean
	rm -f asm corewar
	(cd kasm; make distclean)
	(cd vm; make distclean)

re: distclean all

