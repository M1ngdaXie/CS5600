# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99

# Targets
TARGETS = caesar queue ciphered_queue

# Default rule
all: $(TARGETS)

# Caesar cipher
caesar: caesar_main.o caesar.o
	$(CC) $(CFLAGS) -o $@ $^

# Queue
queue: queue_main.o queue.o
	$(CC) $(CFLAGS) -o $@ $^

# Ciphered queue
ciphered_queue: ciphered_queue_main.o queue.o caesar.o
	$(CC) $(CFLAGS) -o $@ $^

# Rule to compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f *.o $(TARGETS)

.PHONY: all clean