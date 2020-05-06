CC=g++
CFLAGS=-I.
DEPS = Board.h \
	GameClass.h \
	Player.h \
	utility.h
OBJ = Board.o \
	Player.o \
	GameClass.o \
	utility.o \
	main.o

%.o : %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

game : $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean :
	rm -rf *.o game
