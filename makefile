CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
OBJ = main.o twixt.o links.o win.o
TARGET = twixt


all: $(TARGET)


$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)


main.o: main.c twixt.h links.h win.h
	$(CC) $(CFLAGS) -c main.c


twixt.o: twixt.c twixt.h
	$(CC) $(CFLAGS) -c twixt.c


links.o: links.c links.h twixt.h
	$(CC) $(CFLAGS) -c links.c


win.o: win.c win.h links.h twixt.h
	$(CC) $(CFLAGS) -c win.c


clean:
	rm -f $(OBJ) $(TARGET)

