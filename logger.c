#include <stdio.h>
#include <string.h>
#include "logger.h"

void logCommand(char cmd[]) {
    FILE *fp = fopen("log.txt", "a");
    if (!fp) return;
    fputs(cmd, fp);
    fclose(fp);
}

void showLog() {
    FILE *fp = fopen("log.txt", "r");
    if (!fp) {
        printf("No log found.\n");
        return; 
    }

    char line[200];
    while (1) {
        int c = fgetc(fp);
        if (c == EOF) {
            break;
        }
        
        int i = 0;
        while (c != '\n' && c != EOF) {
            line[i++] = c;
            c = fgetc(fp);
        }
        line[i] = '\0';

        if (i > 0){
            printf("%s\n", line);
        }
    }

    fclose(fp);
}
