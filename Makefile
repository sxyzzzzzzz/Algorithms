objects = $(T).o util.o

$(T) : $(objects)
	cc -o $(T) $(objects)

$(T).o : util.h

.PHONY : clean
clean :
	rm $(T) *.o

