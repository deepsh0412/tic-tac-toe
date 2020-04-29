CC=g++
CFLAGS=-I.
DEPS = Board.h \
	GameClass.h \
	Player.h
OBJ = Board.o \
	Player.o \
	GameClass.o \
	main.o

%.o : %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

game : $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean :
	rm -rf *.o game
