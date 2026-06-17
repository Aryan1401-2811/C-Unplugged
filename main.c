#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "songs.h"
#include "albums.h"
#include "playlist.h"
#include "logger.h"


int main() {

    loadSongs();
    loadAlbums();

    while (1) {

        printf("\n1. List Songs\n");
        printf("2. List Albums\n");
        printf("3. View Album\n");
        printf("4. Add Album\n");
        printf("5. Add Song To Album\n");
        printf("6. Delete Song From Album\n");
        printf("7. Add Song To Playlist\n");
        printf("8. Add Album To Playlist\n");
        printf("9. Show Playlist\n");
        printf("10. Play First\n");
        printf("11. Play Next\n");
        printf("12. Play Previous\n");
        printf("13. Show Log\n");
        printf("14. exit\n");
        printf("enter choice: ");

        int choice;
        scanf("%d", &choice);

        while (getchar() != '\n'); 

        char logbuf[50];
        sprintf(logbuf, "%d\n", choice);
        logCommand(logbuf);

        if (choice == 1) {
            listSongs(songHead);
        }

        else if (choice == 2) {
            listAlbums();
        }

        else if (choice == 3) {
            int a;
            printf("Album number: ");
            scanf("%d", &a);
            viewAlbum(a);
        }

        else if (choice == 4) {
            char name[50];
            printf("Album name: ");
            scanf("%s", name);
            addAlbum(name);
        }

        else if (choice == 5) {
            int a, s;
            printf("Album number: ");
            scanf("%d", &a);
            printf("Song ID: ");
            scanf("%d", &s);
            addSongToAlbum(a, s);
        }

        else if (choice == 6) {
            int a, s;
            printf("Album number: ");
            scanf("%d", &a);
            printf("Song ID: ");
            scanf("%d", &s);
            deleteSongFromAlbum(a, s);
        }

        else if (choice == 7) {
            int s;
            printf("Song ID: ");
            scanf("%d", &s);
            addSongToPlaylist(s);
        }

        else if (choice == 8) {
            int a;
            printf("Album number: ");
            scanf("%d", &a);
            addAlbumToPlaylist(a);
        }

        else if (choice == 9) {
            showPlaylist();
        }

        else if (choice == 10) {
            playFirst();
        }

        else if (choice == 11) {
            playNext();
        }

        else if (choice == 12) {
            playPrev();
        }

        else if (choice == 13) {
            showLog();
        }
        
        else if (choice == 14) {
            saveAlbums();
            printf("babye\n");
            break;
        }

        else {
            printf("invalid choice.\n");
        }
    }

    return 0;
}
