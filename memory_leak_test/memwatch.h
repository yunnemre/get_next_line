#ifndef MEMWATCH_H
# define MEMWATCH_H

# include <stdlib.h>

void	*my_malloc(size_t size);
void	my_free(void *ptr);
void	print_unfreed(void);

#endif