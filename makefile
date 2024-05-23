all: compile link

compile:
	g++ -Isrc/include -c equipaggiamento.cpp
	g++ -Isrc/include -c personaggio.cpp
	g++ -Isrc/include -c NPC.cpp
	g++ -Isrc/include -c aiutante.cpp
	g++ -Isrc/include -c medico.cpp
	g++ -Isrc/include -c quiz.cpp
	g++ -Isrc/include -c nemico.cpp
	g++ -Isrc/include -c mercante.cpp
	g++ -Isrc/include -c cassa.cpp
	g++ -Isrc/include -c casella.cpp
	g++ -Isrc/include -c menu.cpp
	g++ -Isrc/include -c arma.cpp
	g++ -Isrc/include -c giocatore.cpp
	g++ -Isrc/include -c grafica.cpp
	g++ -Isrc/include -c gioco.cpp
	g++ -Isrc/include -c main.cpp
link: 
	g++ main.o equipaggiamento.o personaggio.o npc.o aiutante.o casino.o medico.o cassa.o quiz.o nemico.o mercante.o casella.o menu.o arma.o giocatore.o grafica.o gioco.o -o main -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system