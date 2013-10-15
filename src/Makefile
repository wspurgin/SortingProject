#########################################################
#  Makefile
#
#  Will Spurgin 
#  Data Structures
#  CSE 2341
#  2 October 2013
#########################################################

main.out : SortingCompetition.o Word.o CompetitionMain.cpp
	g++ -O2 -std=c++11 $^ -o $@

SortingCompetition.o : SortingCompetition.cpp SortingCompetition.h
	g++ -O2 -c SortingCompetition.cpp -o $@

test.out : Word.o SortingCompetition.o test.cpp
	g++ -O2 $^ -o $@

Word.o : Word.cpp Word.h
	g++ -O2 -c Word.cpp -o $@

clean :
	\rm -f *.o

realclean : clean
	\rm -f *.out *~

##########  End of Makefile  ##########
