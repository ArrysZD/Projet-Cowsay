CC=clang
CFLAGS=-Wall -g

all: reading_cow wildcow new_cow_qst3

reading_cow: reading_cow.o
	$(CC) -o $@ $^

wildcow: wildcow.o
	$(CC) -o $@ $^

new_cow_qst3: new_cow_qst3.o
	$(CC) -o $@ $^

reading_cow.o: reading_cow.c
	$(CC) $(CFLAGS) -c -o $@ $^

wildcow.o: wildcow.c
	$(CC) $(CFLAGS) -c -o $@ $^

new_cow_qst3.o: new_cow_qst3.c
	$(CC) $(CFLAGS) -c -o $@ $^

.PHONY: clean

clean:
	rm -f reading_cow wildcow new_cow_qst3 *.o
