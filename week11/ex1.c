#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <unistd.h>

int main() {
    int file = open("ex1.txt", O_RDWR);
    char text[19] = "This is a nice day";
    ftruncate(file, 19);
    char *m = mmap(0, 18, PROT_READ | PROT_WRITE, MAP_SHARED, file, 0);
    memcpy(m, text, 18);
    munmap(m, 18);
    close(file);
}
