#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    int a = INT_MAX;
    float b = FLT_MAX;
    double c = DBL_MAX;
    printf("Integer: size = %llu, value = %d\n"
           "Float: size = %llu, value = %f\n"
           "Double: size = %llu, value = %f", sizeof(a), a, sizeof(b), b, sizeof(c), c);
}
