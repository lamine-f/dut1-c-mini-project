//
// Created by lord on 02/11/2024.
//

#include "data_access.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

DataAccess
create_data_access(DataAccessType type, const char* path)
{
    DataAccess instance = malloc(sizeof(struct dataAccess));
    if (instance == NULL)
        exit(EXIT_FAILURE);
    instance->path = malloc(sizeof(char) * PATH_MAX);
    data_access_set_type(instance, type);
    data_access_set_path(instance, path);
    return instance;
}

void
destroy_data_access(DataAccess self)
{
    free(self->path);
    free(self);
}

char*
data_access_path(DataAccess self) { return self->path; }

void
data_access_set_path(DataAccess self, const char* location) {strcpy(self->path, location);}

FILE*
data_access_open_file(DataAccess self, const char* mode) {return self->file = fopen( data_access_path(self) , mode);}

void
data_access_close_file(DataAccess self) { fclose(self->file); }

DataAccessType
data_access_type(DataAccess self) {return self->entity;}

void
data_access_set_type(DataAccess self, DataAccessType entity) { self->entity = entity; }