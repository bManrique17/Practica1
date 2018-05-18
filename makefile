temp:	mainPractica.o
	g++ mainPractica.o -o temp

mainPractica.o:	mainPractica.cpp
	g++ -c mainPractica.cpp
