//
// Created by lord on 03/11/2024.
//

#include "classroom_file_persistence.h"
#include <stdio.h>
#define FORMAT "%d\t%s\t%d\n"

static DataAccess access = NULL;
DataAccess get_data_access() {
    if (access == NULL)
        access = data_access_vector_read_element(
            get_storage_config(),
            CLASSROOMS
        );
    return access;
}

Classroom
loadFromFile(int code)
{
    Classroom classroom = create_empty_classroom();
    FILE *file = data_access_open_file(get_data_access(), "r");
    if (file) {
        while (!feof(file)) {
            char line[1024];
            fgets(line,1023,file);
            int current_code;
            char name[MAX_NAME_LENGTH];
            ClassroomLevel level;
            sscanf(line, FORMAT, &current_code , name, &level);

            if (current_code == code) {
                classroom_set_code(classroom, current_code);
                classroom_set_name(classroom, name);
                classroom_set_level(classroom, level);
                return classroom;
            }
        }
        data_access_close_file(access);
    }
    return NULL;
}

int
max_id(void)
{
    FILE *file = data_access_open_file(get_data_access(), "r");
    int code = 0;
    if (file) {
        while (!feof(file)) {
            char line[1024];
            fgets(line,1023,file);
            sscanf(line, FORMAT, &code, NULL, NULL);
        }
        data_access_close_file(access);
    }
    printf("%d\n", code);
    return code;
}

void
saveToFile(Classroom classroom)
{
    if (loadFromFile (classroom_code(classroom)) != NULL) {
        fprintf(stderr,"Classroom with code=%d is already saved \n", classroom_code(classroom));
        return;
    }
    FILE* file = data_access_open_file(get_data_access(), "a");
    if (file) {
        fprintf(file, FORMAT,
            classroom_code(classroom),
            classroom_name(classroom),
            classroom_level(classroom)
        );
        data_access_close_file(access);
    }
}

ClassroomPersistencePort create_classroom_persistence_port() {
    ClassroomPersistencePort persistence;
    persistence.save = saveToFile;
    persistence.load = loadFromFile;
    persistence.max_id = max_id;
    return persistence;
}
