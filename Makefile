all: sakura_card

sakura_card: main.cpp rand.h rand.cpp card_info.h card.h card.cpp deck.h deck.cpp player.h player.cpp game.h game.cpp
	g++ -std=c++11 main.cpp -o sakura_card

clean:
	rm sakura_card
