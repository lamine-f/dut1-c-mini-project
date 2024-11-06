//
// Created by lord on 03/11/2024.
//

#include "class_file_persistence.h"
#include <stdio.h>
#define FORMAT "%d\t%s\t%d\n"

static DataAccess access = NULL;
DataAccess get_data_access() {
    if (access == NULL)
        access = data_access_vector_read_element(
            get_storage_config(),
            CLASSES
        );
    return access;
}

Class
loadFromFile(int code)
{
    Class class = create_empty_class();
    FILE *file = data_access_open_file(get_data_access(), "r");
    if (file) {
        while (!feof(file)) {
            char line[1024];
            fgets(line,1023,file);
            int current_code;
            char name[MAX_NAME_LENGTH];
            ClassLevel level;
            sscanf(line, FORMAT, &current_code , name, &level);

            if (current_code == code) {
                class_set_code(class, current_code);
                class_set_name(class, name);
                class_set_level(class, level);
                return class;
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
saveToFile(Class class)
{
    if (loadFromFile (class_code(class)) != NULL) {
        fprintf(stderr,"Class with code=%d is already saved \n", class_code(class));
        return;
    }
    FILE* file = data_access_open_file(get_data_access(), "a");
    if (file) {
        fprintf(file, FORMAT,
            class_code(class),
            class_name(class),
            class_level(class)
        );
        data_access_close_file(access);
    }
}

ClassPersistencePort create_class_persistence_port() {
    ClassPersistencePort persistence;
    persistence.save = saveToFile;
    persistence.load = loadFromFile;
    persistence.max_id = max_id;
    return persistence;
}
