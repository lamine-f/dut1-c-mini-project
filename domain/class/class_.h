//
// Created by lord on 03/11/2024.
//

#ifndef CLASS_H
#define CLASS_H
#define MAX_NAME_LENGTH 100
typedef enum {
    LICENCE, MASTER
} ClassLevel;

typedef struct class_ {
    int code;
    char name[MAX_NAME_LENGTH];
    ClassLevel level;
}* Class;

extern      int             class_max_id();
extern      Class       create_class(const char *name, ClassLevel level);
extern      Class       create_empty_class();
extern      void            destroy_class(Class self);
extern      void            save_class(Class self);
extern      Class       load_class_by_code(int code);
// extern      void            load_class_by_name(char* name);
extern      int             class_code(Class self);
extern      void            class_set_code(Class self, int code);
extern      char*           class_name(Class self);
extern      void            class_set_name(Class self, const char *name);
extern      ClassLevel  class_level(Class self);
extern      void            class_set_level(Class self, ClassLevel level);
#endif // CLASS_H

