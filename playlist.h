#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "songs.h"
#include "albums.h"

typedef struct PlaylistNode {
    Song *song;
    struct PlaylistNode *next;
    struct PlaylistNode *prev;
} PlaylistNode;

extern PlaylistNode *playlistHead;
extern PlaylistNode *currentSong;

void addSongToPlaylist(int songID);
void addAlbumToPlaylist(int albumIndex);
void showPlaylist();
void playFirst();
void playNext();
void playPrev();

#endif
