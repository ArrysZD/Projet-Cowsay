CC=clang
CFLAGS=-Wall -g

tamagoshi_cow: tamagoshi_cow.o
	$(CC) -o $@ $^

tamagoshi_cow.o: tamagoshi_cow.c
	$(CC) $(CFLAGS) -c -o $@ $^

.PHONY: clean

clean:
	rm -f tamagoshi_cow *.o
