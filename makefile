all: compilar
compilar: detalleCriterio criterio persona acta posgrado main
		g++ -o a detalleCriterio.o criterio.o persona.o acta.o posgrado.o main.o
detalleCriterio: detalleCriterio.cpp detalleCriterio.h
		g++ -c detalleCriterio.cpp
criterio: criterio.cpp criterio.h
		g++ -c criterio.cpp
persona: persona.cpp persona.h
		g++ -c persona.cpp
acta: acta.cpp acta.h
		g++ -c acta.cpp
posgrado: posgrado.cpp posgrado.h
		g++ -c posgrado.cpp
main: main.cpp posgrado.h 
	  g++ -c main.cpp
