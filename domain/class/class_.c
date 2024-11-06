//
// Created by lord on 03/11/2024.
//

#include "class_.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../adapters/persistence/class_file_persistence.h"
#include "../../ports/persistence_port.h"
int MAX_ID = 0;
int
class_max_id()
{
    if (MAX_ID == 0) {
        ClassPersistencePort port = create_class_persistence_port();
        MAX_ID = port.max_id();
    }
    return MAX_ID;
}

Class
create_class(const char *name, ClassLevel level)
{
    Class instance = malloc(sizeof(struct class_));
    if (instance == NULL) {
        fprintf(stderr, "Error in allocating memory for class\n");
        exit(EXIT_FAILURE);
    }
    class_set_code(instance, class_max_id() + 1);
    class_set_name(instance, name);
    class_set_level(instance, level);
    return instance;
}

Class
create_empty_class()
{
    Class instance = malloc(sizeof(struct class_));
    if (instance == NULL) {
        fprintf(stderr, "Error in allocating memory for class\n");
        exit(EXIT_FAILURE);
    }
    return instance;
}
void
destroy_class(Class self)
{
    free(self);
}

void
save_class(Class self)
{
    ClassPersistencePort port = create_class_persistence_port();
    port.save(self);
}

Class
load_class_by_code(int code)
{
    ClassPersistencePort port = create_class_persistence_port();
    return port.load(code);
}

int
class_code(Class self)
{
    return self->code;
}

void
class_set_code(Class self, int code)
{
    self->code = MAX_ID = code;
}

char*
class_name(Class self)
{
    return self->name;
}

void
class_set_name(Class self, const char *name)
{
    strcpy(self->name, name);
}

ClassLevel
class_level(Class self)
{
    return self->level;
}

void
class_set_level(Class self, ClassLevel level)
{
    self->level = level;
}