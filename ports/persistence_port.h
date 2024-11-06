//
// Created by lord on 03/11/2024.
//

#ifndef PERSISTENCE_PORT_H
#define PERSISTENCE_PORT_H

#include "../domain/class/class_.h"

typedef struct {
    void (*save)(const Class class);
    Class (*load)(int code);
    int (*max_id)(void);
} ClassPersistencePort;

#endif // PERSISTENCE_PORT_H
