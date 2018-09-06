objects = $(T).o util.o
CC=gcc

$(T) : $(objects)
	$(CC) -o $(T) $(objects)

$(T).o : util.h

.PHONY : clean
clean :
	rm $(T) *.o

