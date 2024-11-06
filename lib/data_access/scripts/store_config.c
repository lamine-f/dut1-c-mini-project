//
// Created by lord on 02/11/2024.
//

#include <stdio.h>
#include "../data_access.h"
#include "../../../adapters/persistence/class_file_persistence.h"
#include "../../../domain/class/class_.h"
#include "../vector/data_access_vector.h"

static DataAccessVector data_access_vector_instance = NULL;

static void
load_storage_config (void)
{
    printf("STORAGE LOCATION CONFIG:\n");
    printf("\t - LOADING\n");

    data_access_vector_instance = create_data_access_vector();
    data_access_vector_write_element(
        data_access_vector_instance,
        CLASSES,
        create_data_access(CLASSES, "storage/CLASSES.csv")
    );
    data_access_vector_write_element(
        data_access_vector_instance,
        COURSES,
        create_data_access(COURSES, "storage/COURSES.csv")
    );
    data_access_vector_write_element(
        data_access_vector_instance,
        MARKS,
        create_data_access(MARKS,"storage/MARKS.csv")
    );
    data_access_vector_write_element(
        data_access_vector_instance,
        STUDENTS,
        create_data_access(STUDENTS,"storage/STUDENTS.csv")
    );
    data_access_vector_write_element(
        data_access_vector_instance,
        SUBJECTS,
        create_data_access(SUBJECTS,"storage/SUBJECTS.csv")
    );
    printf("\t - LOADED\n");
}

DataAccessVector
get_storage_config(void)
{
    if (data_access_vector_instance == NULL) load_storage_config();
    return data_access_vector_instance;
}

void
destroy_storage_config (void)
{
    if (data_access_vector_instance != NULL) {
        destroy_data_access_vector(data_access_vector_instance);
    }
}