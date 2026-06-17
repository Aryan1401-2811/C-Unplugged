CC = gcc
CFLAGS = -Wall

all:
	$(CC) $(CFLAGS) main.c songs.c albums.c playlist.c logger.c -o a.exe
	$(CC) $(CFLAGS) main.c songs.c albums.c playlist.c logger.c -o a.out
