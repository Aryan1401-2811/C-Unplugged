#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "albums.h"

Album *albumHead = NULL;
int albumIDCounter = 1;


void addAlbum(char albumName[]) { 
    Album *newAlbum = malloc(sizeof(Album));
    newAlbum->id = albumIDCounter++;        
    strcpy(newAlbum->name, albumName);
    newAlbum->songs = NULL;
    newAlbum->next = NULL;

    if (albumHead == NULL){
        albumHead = newAlbum;
    }
    else {
        Album *t = albumHead;
        while (t->next != NULL)
            t = t->next;
        t->next = newAlbum;
    }

    printf("Album '%s' created\n", albumName);

}


void listAlbums() {
    Album *t = albumHead;
    int index = 1;

    if (t == NULL) {
        printf("No albums found.\n");
        return;
    }

    while (t != NULL) {
        printf("%d. %s\n", index, t->name);
        index++;
        t = t->next;
    }
}


Album* getAlbumByIndex(int index) {
    Album *t = albumHead;
    int i = 1;

    while (t != NULL) {
        if (i == index){
            return t;
        }
        i++;
        t = t->next;
    }
    return NULL;
}


void viewAlbum(int albumIndex) {
    Album *album = getAlbumByIndex(albumIndex);
    if (!album) {
        printf("Album not found.\n");
        return;
    }

    printf("\nAlbum: %s\n", album->name);

    Song *s = album->songs;
    int index = 1;

    if (s==NULL) {
        printf("No songs in this album.\n");
        return;
    }

    while (s != NULL) {
        printf("%d. %s - %s (%s)\n", index, s->name, s->artist, s->duration);
        s = s->next;
        index++;
    }

}

void addSongToAlbum(int albumIndex, int songID) {
    Album *album = getAlbumByIndex(albumIndex);
    if (!album) {
        printf("Album not found.\n");
        return;
    }

    Song *libSong = findSongByID(songID);
    if (libSong==NULL) {
        printf("Song ID not found.\n");
        return;
    }
    
    Song *newSong = malloc(sizeof(Song));
    *newSong = *libSong;       
    newSong->next = album->songs;
    album->songs = newSong;

    printf("Song added to album\n");
}


void deleteSongFromAlbum(int albumIndex, int songID) {
    Album *album = getAlbumByIndex(albumIndex);
    if (!album) {
        printf("Album not found.\n");
        return;
    }

    Song *curr = album->songs;
    Song *prev = NULL;

    while (curr != NULL) {
        if (curr->id == songID) {
            if (prev == NULL)
                album->songs = curr->next;
            else{
                prev->next = curr->next;
            }

            free(curr);
            printf("Song removed from album.\n");
            return;
        }

        prev = curr;
        curr = curr->next;
    }

    printf("Song ID not found in album.\n");
}


void saveAlbums() {
    FILE *fp = fopen("albums.txt", "w");
    if (!fp) return;

    Album *a = albumHead;

    while (a != NULL) {
      
        fprintf(fp, "#%d|%s\n", a->id, a->name);

        Song *s = a->songs;
        while (s != NULL) {
            
        fprintf(fp, "%d|%s|%s|%s\n", s->id, s->name, s->artist, s->duration);
         s = s->next;
        }

        fprintf(fp, ";\n");  
        a = a->next;
    }

    fclose(fp);
}


void loadAlbums() {
    FILE *fp = fopen("albums.txt", "r");
    if (!fp) return;

    char line[200];
    Album *currentAlbum = NULL;

    while (1) {

 
        int ch = fgetc(fp);
        if (ch == EOF) break;

        int i = 0;
        while (ch != '\n' && ch != EOF) {
            line[i++] = ch;
            ch = fgetc(fp);
        }
        line[i] = '\0';

        if (i == 0) continue;

 
        if (line[0] == '#') {

            int albumID = 0;
            char albumName[50];

            int k = 1;
            int field = 0;
            int j = 0;

            while (line[k] != '\0') {
                if (line[k] == '|') {
                    albumName[j] = '\0';
                    break;
                }

                if (field == 0) {
                    albumID = albumID * 10 + (line[k] - '0');
                }

                k++;
            }

            k++; 
            j = 0;

        
            while (line[k] != '\0') {
                albumName[j++] = line[k++];
            }
            albumName[j] = '\0';

          
            Album *newAlbum = malloc(sizeof(Album));
            newAlbum->id = albumID;      
            strcpy(newAlbum->name, albumName);
            newAlbum->songs = NULL;
            newAlbum->next = NULL;

            if (albumHead == NULL)
                albumHead = newAlbum;
            else {
                Album *t = albumHead;
                while (t->next != NULL)
                    t = t->next;
                t->next = newAlbum;
            }

            currentAlbum = newAlbum;

            if (albumIDCounter <= albumID)
                albumIDCounter = albumID + 1;
        }

   
        else if (line[0] == ';') {
            currentAlbum = NULL;
        }

        
        else if (currentAlbum != NULL) {

            int songID = 0;
            char name[50], artist[50], duration[10];

            int field = 0, j = 0;

            for (int k = 0; line[k] != '\0'; k++) {

                if (line[k] == '|') {
                    if (field == 0) name[j] = '\0';
                    else if (field == 1) artist[j] = '\0';
                    field++;
                    j = 0;
                }

                else {
                    if (field == 0) {
                        songID = songID * 10 + (line[k] - '0');
                    }
                    else if (field == 1 && j < 49) name[j++] = line[k];
                    else if (field == 2 && j < 49) artist[j++] = line[k];
                    else if (field == 3 && j < 9) duration[j++] = line[k];
                }
            }
            duration[j] = '\0';

            Song *newSong = malloc(sizeof(Song));
            newSong->id = songID;
            strcpy(newSong->name, name);
            strcpy(newSong->artist, artist);
            strcpy(newSong->duration, duration);
            newSong->next = currentAlbum->songs;
            currentAlbum->songs = newSong;
        }
    }

    fclose(fp);
}
