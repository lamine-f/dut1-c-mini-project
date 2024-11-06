//
// Created by lord on 03/11/2024.
//

#ifndef CLASS_SERVICE_H
#define CLASS_SERVICE_H

#include "../../domain/class/class_.h"
#include "../../ports/persistence_port.h"
#include "../../ports/view_port.h"

// Service pour gérer la logique des salles de classe
// void addStudentToClass(Class class, Student student);
void saveClass(Class class, PersistencePort *persistence);
void displayClass(const Class class, ViewPort *view);

#endif // CLASS_SERVICE_H
