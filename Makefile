target=DuckSoup
objects=main.o window_manager.o
librarys=-lncurses
CC=g++

$(target): $(objects)
	$(CC) $(objects) $(librarys) -o $(target)

window_manager.o: window_manager/window_manager.h
	$(CC) -c window_manager/window_manager.cc

.PHNOY:clean
clean:
	-rm $(objects)