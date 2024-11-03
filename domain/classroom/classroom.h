//
// Created by lord on 03/11/2024.
//

#ifndef CLASSROOM_H
#define CLASSROOM_H
#define MAX_NAME_LENGTH 100
typedef enum {
    LICENCE, MASTER
} ClassroomLevel;

typedef struct classroom {
    int code;
    char name[MAX_NAME_LENGTH];
    ClassroomLevel level;
}* Classroom;

extern      int             classroom_max_id();
extern      Classroom       create_classroom(const char *name, ClassroomLevel level);
extern      Classroom       create_empty_classroom();
extern      void            destroy_classroom(Classroom self);
extern      void            save_classroom(Classroom self);
extern      Classroom       load_classroom_by_code(int code);
// extern      void            load_classroom_by_name(char* name);
extern      int             classroom_code(Classroom self);
extern      void            classroom_set_code(Classroom self, int code);
extern      char*           classroom_name(Classroom self);
extern      void            classroom_set_name(Classroom self, const char *name);
extern      ClassroomLevel  classroom_level(Classroom self);
extern      void            classroom_set_level(Classroom self, ClassroomLevel level);
#endif // CLASSROOM_H

