//
// Created by lord on 02/11/2024.
//

#include "generic_vector.h"
#include <assert.h>
#include <stdlib.h>
static const int DEFAULT_SIZE = 5;
struct genericVector
{
    void **tab;
    int maxIndex;
};
static void
extend_vector(GenericVector self, int index)
{
    self->tab = realloc(self->tab, (index + DEFAULT_SIZE) * sizeof(void *));
    for(int i = self->maxIndex + 1; i < index + DEFAULT_SIZE; i++)
        self->tab[i] = 0;
    self->maxIndex = (index + DEFAULT_SIZE)- 1;
}

GenericVector
create_generic_vector (void)
{
    GenericVector self = malloc(sizeof(struct genericVector));
    self->tab = malloc(sizeof(void *) * DEFAULT_SIZE);
    self->maxIndex = DEFAULT_SIZE- 1;
    for(int i = 0; i <= self->maxIndex; i++)
        self->tab[i] = (void *) 0;
    return self;
}

void
destroy_generic_vector(GenericVector self)
{
    free(self->tab);
    free(self);
}

void*
generic_vector_read_element(GenericVector self, int index)
{
    assert(!(index < 0 || index > self->maxIndex));
    return self->tab[index];
}

void
generic_vector_write_element(GenericVector self, int index, void* element)
{
    assert(! (index < 0));
    if(index >= self->maxIndex)
        extend_vector(self, index);
    self->tab[index] = element;
}

int
generic_vector_max_index(GenericVector self)
{
    return self->maxIndex;
}