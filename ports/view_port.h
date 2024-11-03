//
// Created by lord on 03/11/2024.
//

#ifndef VIEW_PORT_H
#define VIEW_PORT_H

typedef struct {
    void (*display)(const void* entity);
} ViewPort;

#endif //VIEW_PORT_H
