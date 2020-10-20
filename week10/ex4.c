#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

struct file {
    unsigned long inode;
    char names[10][50];
    int count;
};

int main() {
    DIR *dir = opendir("./tmp");
    struct dirent *entry;
    struct file files[10];
    int count = 0;
    for (int i = 0; i < 10; i++) {
        files[i].inode = 0;
        files[i].count = 0;
    }
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] != '.') {
            printf("%s\n", entry->d_name);
            struct stat s = {};
            char dirname[54] = "tmp/";
            stat(strcat(dirname, entry->d_name), &s);
            if (s.st_nlink > 1) {
                int found = 0;
                for (int i = 0; i < 10; i++) {
                    if (files[i].inode == s.st_ino) {
                        strncpy(files[i].names[files[i].count], entry->d_name, 50);
                        files[i].inode = s.st_ino;
                        files[i].count += 1;
                        found = 1;
                        break;
                    }
                }
                if (found == 0) {
                    files[count].inode = s.st_ino;
                    strncpy(files[count].names[0], entry->d_name, 50);
                    files[count].count += 1;
                    count += 1;
                }
            }
        }
    }
    closedir(dir);
    printf("Found %d\n", count);
    for (int i = 0; i < count; i++) {
        printf("%lu (%d files)\n", files[i].inode, files[i].count);
        for (int j = 0; j < files[i].count; ++j)
            printf("\t%s\n", files[i].names[j]);
        printf("\n");
    }
}
