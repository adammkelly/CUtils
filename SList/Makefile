HEADERS = slist.h slist_priv.h
OBJECTS = test.o slist.o
PROGRAM = test

default: $(PROGRAM)

%.o: %.c $(HEADERS)
		gcc -c $< -o $@

test: $(OBJECTS)
		gcc $(OBJECTS) -o $@

clean:
		-rm -f $(OBJECTS)
