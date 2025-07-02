#include <stdio.h>
#include "memwatch.h"

#define MAX_ALLOC 1000

typedef struct {
	void *ptr;
	size_t size;
	int freed;
} MemBlock;

static MemBlock mem_list[MAX_ALLOC];
static int mem_count = 0;

void *my_malloc(size_t size) {
	if (mem_count >= MAX_ALLOC)
		return NULL;
	void *ptr = malloc(size);
	if (ptr) {
		mem_list[mem_count].ptr = ptr;
		mem_list[mem_count].size = size;
		mem_list[mem_count].freed = 0;
		mem_count++;
	}
	return ptr;
}

void my_free(void *ptr) {
	for (int i = 0; i < mem_count; i++) {
		if (mem_list[i].ptr == ptr && mem_list[i].freed == 0) {
			mem_list[i].freed = 1;
			free(ptr);
			return;
		}
	}
	printf("⚠️  Geçersiz veya double free: %p\n", ptr);
}

void print_unfreed(void) {
	printf("\n🔍 Free edilmemiş malloclar:\n");
	for (int i = 0; i < mem_count; i++) {
		if (!mem_list[i].freed)
			printf("🧠 Adres: %p | Boyut: %zu byte\n", mem_list[i].ptr, mem_list[i].size);
	}
}
