#include <stdio.h>
#include <unistd.h>

int main() {
	for (int i = 0; i < 5; i++) {
		fork();
		printf("%d\n", getpid());
		sleep(5);
	}
	return 0;
}
/*
 * ex2-+-ex2-+-ex2---ex2
    |     `-ex2
    |-ex2---ex2
    `-ex2
 * 8 processes because we call fork 3 times which is 2^3=8
 */
/*
 * ex2-+-ex2-+-ex2-+-ex2-+-ex2---ex2
    |     |     |     `-ex2
    |     |     |-ex2---ex2
    |     |     `-ex2
    |     |-ex2-+-ex2---ex2
    |     |     `-ex2
    |     |-ex2---ex2
    |     `-ex2
    |-ex2-+-ex2-+-ex2---ex2
    |     |     `-ex2
    |     |-ex2---ex2
    |     `-ex2
    |-ex2-+-ex2---ex2
    |     `-ex2
    |-ex2---ex2
    `-ex2
 * I did not count but I suppose that it is 32 because 2^5=32
 */
