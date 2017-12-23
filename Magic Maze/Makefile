run: main.cpp Girl.o tree.o Room.o
	g++ main.cpp Girl.o tree.o Room.o
tree.o: tree.cpp tree.h Treend.h
	g++ -c tree.cpp 
Girl.o: Girl.cpp Girl.h Room.o
	g++ -c Girl.cpp Room.o
Room.o: Room.h Room.cpp
	g++ -c Room.cpp 
