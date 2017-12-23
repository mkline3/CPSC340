run: main.cpp linked_list.o single_node.o Deck.o gameController.o
	g++  main.cpp linked_list.o single_node.o Deck.o gameController.o
linked_list.o: linked_list.h linked_list.cpp single_node.o
	g++ -c linked_list.cpp single_node.o
single_node.o: single_node.h single_node.cpp
	g++ -c single_node.cpp
Deck.o: Deck.h Deck.cpp
	g++ -c Deck.cpp
gameController.o: gameController.h gameController.cpp Deck.o linked_list.o
	g++ -c gameController.cpp Deck.o linked_list.o

