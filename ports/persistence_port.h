//
// Created by lord on 03/11/2024.
//

#ifndef PERSISTENCE_PORT_H
#define PERSISTENCE_PORT_H

#include "../domain/classroom/classroom.h"

typedef struct {
    void (*save)(const Classroom classroom);
    Classroom (*load)(int code);
    int (*max_id)(void);
} ClassroomPersistencePort;

#endif // PERSISTENCE_PORT_H
