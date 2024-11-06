//
// Created by lord on 02/11/2024.
//
#ifndef DATA_ACCESS_H
#define DATA_ACCESS_H
#include <stdio.h>

typedef enum {
    CLASSES,
    COURSES,
    MARKS,
    STUDENTS,
    SUBJECTS,
} DataAccessType;

typedef struct dataAccess {
    DataAccessType entity;
    char* path;
    FILE* file;
}* DataAccess;

extern      DataAccess      create_data_access(DataAccessType type, const char* path);
extern      void            destroy_data_access(DataAccess self);
extern      char*           data_access_path(DataAccess self);
extern      void            data_access_set_path(DataAccess self, const char* location);
extern      FILE*           data_access_open_file(DataAccess self, const char* mode);
extern      void            data_access_close_file(DataAccess self);
extern      DataAccessType  data_access_type(DataAccess self);
extern      void            data_access_set_type(DataAccess self, DataAccessType entity);
#endif //DATA_ACCESS_H