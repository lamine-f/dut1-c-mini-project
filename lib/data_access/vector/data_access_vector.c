//
// Created by lord on 02/11/2024.
//

#include "data_access_vector.h"
#include <stdlib.h>
struct dataAccessVector
{
    GenericVector delegate;
};

DataAccessVector
create_data_access_vector (void)
{
    DataAccessVector self = malloc(sizeof(struct dataAccessVector));
    self->delegate = create_generic_vector();
    return self;
}

void
destroy_data_access_vector(DataAccessVector self)
{
    destroy_generic_vector(self->delegate);
    free(self);
}

DataAccess
data_access_vector_read_element(DataAccessVector self, DataAccessType index)
{
    return generic_vector_read_element(self->delegate, index);
}

void
data_access_vector_write_element(DataAccessVector self, DataAccessType index, DataAccess element)
{
    generic_vector_write_element(self->delegate, index, element);
}

int
data_access_vector_max_index(DataAccessVector self)
{
    return generic_vector_max_index(self->delegate);
}