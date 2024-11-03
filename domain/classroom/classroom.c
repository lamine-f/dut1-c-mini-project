//
// Created by lord on 03/11/2024.
//

#include "classroom.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../adapters/persistence/classroom_file_persistence.h"
#include "../../ports/persistence_port.h"
int MAX_ID = 0;
int
classroom_max_id()
{
    if (MAX_ID == 0) {
        ClassroomPersistencePort port = create_classroom_persistence_port();
        MAX_ID = port.max_id();
    }
    return MAX_ID;
}

Classroom
create_classroom(const char *name, ClassroomLevel level)
{
    Classroom instance = malloc(sizeof(struct classroom));
    if (instance == NULL) {
        fprintf(stderr, "Error in allocating memory for classroom\n");
        exit(EXIT_FAILURE);
    }
    classroom_set_code(instance, classroom_max_id() + 1);
    classroom_set_name(instance, name);
    classroom_set_level(instance, level);
    return instance;
}

Classroom
create_empty_classroom()
{
    Classroom instance = malloc(sizeof(struct classroom));
    if (instance == NULL) {
        fprintf(stderr, "Error in allocating memory for classroom\n");
        exit(EXIT_FAILURE);
    }
    return instance;
}
void
destroy_classroom(Classroom self)
{
    free(self);
}

void
save_classroom(Classroom self)
{
    ClassroomPersistencePort port = create_classroom_persistence_port();
    port.save(self);
}

Classroom
load_classroom_by_code(int code)
{
    ClassroomPersistencePort port = create_classroom_persistence_port();
    return port.load(code);
}

int
classroom_code(Classroom self)
{
    return self->code;
}

void
classroom_set_code(Classroom self, int code)
{
    self->code = MAX_ID = code;
}

char*
classroom_name(Classroom self)
{
    return self->name;
}

void
classroom_set_name(Classroom self, const char *name)
{
    strcpy(self->name, name);
}

ClassroomLevel
classroom_level(Classroom self)
{
    return self->level;
}

void
classroom_set_level(Classroom self, ClassroomLevel level)
{
    self->level = level;
}