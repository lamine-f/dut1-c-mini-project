//
// Created by lord on 03/11/2024.
//

#ifndef CLASSROOM_SERVICE_H
#define CLASSROOM_SERVICE_H

#include "../../domain/classroom/classroom.h"
#include "../../ports/persistence_port.h"
#include "../../ports/view_port.h"

// Service pour gérer la logique des salles de classe
// void addStudentToClassroom(Classroom classroom, Student student);
void saveClassroom(Classroom classroom, PersistencePort *persistence);
void displayClassroom(const Classroom classroom, ViewPort *view);

#endif // CLASSROOM_SERVICE_H
