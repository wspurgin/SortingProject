#########################################################
#  Makefile
#
#  Will Spurgin 
#  Data Structures
#  CSE 2341
#  2 October 2013
#########################################################

test.out : Word.o test.cpp
	g++ $^ -o $@

Word.o : Word.cpp Word.h
	g++ -g -c Word.cpp -o $@

clean :
	\rm -f *.o

realclean : clean
	\rm -f *.out *~

##########  End of Makefile  ##########
