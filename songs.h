#ifndef SONGS_H
#define SONGS_H

typedef struct Song {
    int id;              
    char name[50];
    char artist[50];
    char duration[10];
    struct Song *next;
} Song;

extern Song *songHead;
extern int songIDCounter;

void loadSongs();
void listSongs(Song *head);
Song* findSongByID(int id);
Song* findSongByName(char name[]);

#endif
