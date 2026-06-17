#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "playlist.h"

PlaylistNode *playlistHead = NULL;
PlaylistNode *currentSong = NULL;

void addSongToPlaylist(int songID) {
    Song *song = findSongByID(songID);
    if (song==NULL) {
        printf("Song not found.\n");
        return;
    }

    PlaylistNode *newNode = malloc(sizeof(PlaylistNode));
    newNode->song = song;

    if (playlistHead == NULL) {
        playlistHead = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    } 
    else {
        PlaylistNode *last = playlistHead->prev;
        last->next = newNode;
        newNode->prev = last;
        newNode->next = playlistHead;
        playlistHead->prev = newNode;
    }

    printf("Song added to playlist.\n");
}

void addAlbumToPlaylist(int albumIndex) {
    Album *album = getAlbumByIndex(albumIndex);
    if (album==NULL) {
        printf("Album not found.\n");
        return;
    }

    Song *t = album->songs;
    if (t == NULL) {
        printf("No songs in this album.\n");
        return;
    }
    
    while (t != NULL) {
        PlaylistNode *newNode = malloc(sizeof(PlaylistNode));
        newNode->song = t;

        if (playlistHead == NULL) {
            playlistHead = newNode;
            newNode->next = newNode;
            newNode->prev = newNode;
        } 
        else {
            PlaylistNode *last = playlistHead->prev;
            last->next = newNode;
            newNode->prev = last;
            newNode->next = playlistHead;
            playlistHead->prev = newNode;
        }

        t = t->next;
    }

    printf("Album added to playlist.\n");
}


void showPlaylist() {//done
    if (playlistHead==NULL) {
        printf("Playlist is empty.\n");
        return;
    }

    PlaylistNode *t = playlistHead;
    do {
        printf("%s - %s\n", t->song->name, t->song->artist);
        t = t->next;
    } while (t != playlistHead);
}

void playFirst() {
    if (!playlistHead) {
        printf("Playlist is empty.\n");
        return;
    }

    currentSong = playlistHead;
    printf("Now Playing: %s\n", currentSong->song->name);
}

void playNext() {
    if (!currentSong) {
        printf("Start playback with playFirst.\n");
        return;
    }
    currentSong = currentSong->next;
    printf("Now Playing: %s\n", currentSong->song->name);
}

void playPrev() {
    if (!currentSong) {
        printf("Start playback with playFirst.\n");
        return;
    }
    currentSong = currentSong->prev;
    printf("Now Playing: %s\n", currentSong->song->name);
}
