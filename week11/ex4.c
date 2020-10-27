#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>

int main() {
    int file = open("ex1.txt", O_RDONLY);
    struct stat buffer;
    fstat(file, &buffer);
    char *map = mmap(NULL, buffer.st_size, PROT_READ, MAP_PRIVATE, file, 0);
    int file_copy = open("ex1.memcpy.txt", O_RDWR | O_CREAT, (mode_t)0666);
    ftruncate(file_copy, buffer.st_size);
    char *map_copy = mmap(NULL, buffer.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, file_copy, 0);
    memcpy(map_copy, map, buffer.st_size);
    munmap(map, buffer.st_size);
    munmap(map_copy, buffer.st_size);
    close(file);
    close(file_copy);
}
