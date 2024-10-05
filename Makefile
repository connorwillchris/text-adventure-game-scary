all: main.cpp
	g++ -o text-adventure-game-scary \
		main.cpp \
		game.cpp \
		-lraylib -lGL -lm -lpthread -ldl -lrt -lX11

clean:
	rm -rf text-adventure-game-scary
