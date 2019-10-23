#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>

#define MAX_OP 100
#define MAX_INODE 30
#define MAX_NAME 30

char BUF[MAX_OP];
char pattern[] = "find ~ -inum ";

int main() {
    struct dirent *d;
    DIR *dir = opendir(".");
    struct stat stats;

    char name[MAX_NAME];

    while ((d = readdir(dir)) != NULL) {
        strcpy(name, d->d_name);
        stat(d->d_name,&stats);
        if (stats.st_nlink >= 2) {
            char inode[MAX_INODE];
            snprintf(inode, MAX_INODE, "%ld", stats.st_ino);
            strcat(BUF, pattern);
            strcat(BUF, inode);
            system(BUF);
            BUF[0] = '\0';
        }
        name[0] = '\0';
    }
    closedir(dir);
    return 0;
}
