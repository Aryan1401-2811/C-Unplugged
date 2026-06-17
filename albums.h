#ifndef ALBUMS_H
#define ALBUMS_H

#include "songs.h"

typedef struct Album {
    int id;              
    char name[50];
    Song *songs;
    struct Album *next;
} Album;

extern Album *albumHead;
extern int albumIDCounter;


void addAlbum(char albumName[]);
void listAlbums();
Album* getAlbumByIndex(int index);
void viewAlbum(int albumIndex);


void addSongToAlbum(int albumIndex, int songID);
void deleteSongFromAlbum(int albumIndex, int songID);


void saveAlbums();
void loadAlbums();

#endif
