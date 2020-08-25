#include <stdio.h>
#include <stdlib.h>

void print_space(int space) {
    for (int i = 0; i < space; i++)
        printf(" ");
}

void print_star(int star) {
    for (int i = 0; i < star; i++)
        printf("*");
}

void triangle(int n) {
    int space = n - 1;
    int star = 1;
    for (int i = 0; i < n; i++) {
        print_space(space);
        print_star(star);
        print_space(space);
        printf("\n");
        star += 2;
        space -= 1;
    }
}

void reversed_triangle(int n, int flag) {
    int star = 2 * n - 1;
    int space;
    if (flag == 1)
        space = 1;
    else space = 0;
    for (int i = 0; i < n; i++) {
        print_space(space);
        print_star(star);
        print_space(space);
        printf("\n");
        star -= 2;
        space += 1;
    }
}

void diamond(int n) {
    triangle(n / 2 + 1);
    if (n % 2 == 1)
        reversed_triangle(n / 2, 1);
    else
        reversed_triangle(n / 2 + 1, 0);
}

void square(int n) {
    for (int i = 0; i < n; i++) {
        print_star(n);
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc == 2) {
        printf("Chose your figure: (1)triangle, (2)diamond, (3)square\n");
        int n = strtol(argv[1], NULL, 0);
        char num;
        scanf("%c", &num);
        int type = strtol(&num, NULL, 0);
        switch (type) {
            case 1:
                triangle(n);
                break;
            case 2:
                diamond(n);
                break;
            case 3:
                square(n);
                break;
        }
    }
}
