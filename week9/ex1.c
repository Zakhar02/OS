#include <stdlib.h>
#include <stdio.h>

struct page_t {
    int id;
    int count;
};

struct page_t *find(struct page_t *pages, int id, int n) {
    for (int i = 0; i < n; i++)
        if (pages[i].id == id)
            return pages + i;
    return NULL;
}

struct page_t *place(struct page_t *pages, int n) {
    int count = 1 << 31;
    int id = 0;
    for (int i = 0; i < n; i++) {
        if (pages[i].id == 0)
            return pages + i;
        if (pages[i].count < count) {
            count = pages[i].count;
            id = i;
        }
    }
    return pages + id;
}

int main(int argc, char *argv[]) {
    int n = strtol(argv[1], NULL, 10);
    struct page_t *pages = calloc(n, sizeof(struct page_t));
    FILE *input = fopen("input.txt", "r");
    int id, hits = 0, miss = 0;
    while (fscanf(input, "%d", &id) == 1) {
        struct page_t *page = find(pages, id, n);
        if (page != NULL)
            hits += 1;
        else {
            miss += 1;
            page = place(pages, n);
            page->id = id;
            page->count = 0;
        }
        for (int i = 0; i < n; i++)
            pages[i].count >>= 1;
        page->count |= 1 << (sizeof(((struct page_t *) NULL)->count) * 8 - 1);
    }
    printf("Hits: %d, Miss: %d\n Hits/Miss: %f\n", hits, miss, (float) hits / miss);
    free(pages);
    fclose(input);
}
