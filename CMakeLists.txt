cmake_minimum_required(VERSION 3.29)
project(student_management C)

set(CMAKE_C_STANDARD 11)

add_executable(student_management main.c
        lib/data_access/data_access.h
        lib/data_access/data_access.c
        lib/data_access/vector/data_access_vector.h
        lib/data_access/vector/data_access_vector.c
        lib/vector/generic_vector.c
        lib/vector/generic_vector.h
        lib/data_access/scripts/store_config.c
        application/class_service/class_service.h
        domain/class/class_.c
        domain/class/class_.h
        ports/persistence_port.h
        ports/view_port.h
        adapters/persistence/class_file_persistence.c
        adapters/persistence/class_file_persistence.h
        adapters/view/cli_view/cli_view.c
        adapters/view/cli_view/cli_view.h)
