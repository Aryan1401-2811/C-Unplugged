#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "songs.h"

Song *songHead = NULL;
int songIDCounter = 1;     

void loadSongs() {
    FILE *fp = fopen("songs.txt", "r");
    if (fp == NULL) {
        printf("songs.txt not found!\n");
        return;
    }

    char line[200];

    while (1) {
        int c = fgetc(fp);
        if (c == EOF) break;

        int i = 0;

     
        while (c != '\n' && c != EOF) {
            line[i++] = c;
            c = fgetc(fp);
        }
        line[i] = '\0';

        if (i == 0) continue;

       
        char name[50], artist[50], duration[10];
        int field = 0;
        int j = 0;

        for (int k = 0; line[k] != '\0'; k++) {
            if (line[k] == '|') {
                if (field == 0) name[j] = '\0';
                else if (field == 1) artist[j] = '\0';
                field++;
                j = 0;
            } else {
                if (field == 0 && j < 49) name[j++] = line[k];
                else if (field == 1 && j < 49) artist[j++] = line[k];
                else if (field == 2 && j < 9) duration[j++] = line[k];
            }
        }
        duration[j] = '\0';

 
        Song *newSong = malloc(sizeof(Song));
        if (!newSong) {
            fclose(fp);
            return;
        }

        newSong->id = songIDCounter++;   
        strcpy(newSong->name, name);
        strcpy(newSong->artist, artist);
        strcpy(newSong->duration, duration);
        newSong->next = NULL;

        if (songHead == NULL)
            songHead = newSong;
        else {
            Song *temp = songHead;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newSong;
        }
    }

    fclose(fp);
}

void listSongs(Song *temp) {
    int index = 1;

    if (temp == NULL) {
        printf("No songs available.\n");
        return;
    }

    while (temp != NULL) {
        printf("%d. %s - %s (%s)\n", index, temp->name,temp->artist, temp->duration);
        temp = temp->next;
        index++;
    }
}

Song* findSongByID(int id) {
    Song *t = songHead;
    while (t != NULL) {
        if (t->id == id)
            return t;
        t = t->next;
    }
    return NULL;
}

Song* findSongByName(char name[]) {
    Song *t = songHead;
    while (t != NULL) {
        if (strcmp(t->name, name) == 0)
            return t;
        t = t->next;
    }
    return NULL;
}
