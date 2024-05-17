all: compile link

compile:
	g++ -Isrc/include -c Base/personaggio.cpp
	g++ -Isrc/include -IBase -c Personaggi/aiutante.cpp
	g++ -Isrc/include -IBase -c Personaggi/NPC.cpp
	g++ -Isrc/include -IPersonaggi -c Base/casella.cpp
	g++ -Isrc/include -c Base/equipaggiamento.cpp
	g++ -Isrc/include -c Base/menu.cpp
	g++ -Isrc/include -IPersonaggi -ICaselle -IEquipaggiamento -IBase -c main.cpp
link: 
	g++ main.o personaggio.o menu.o -o main -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system