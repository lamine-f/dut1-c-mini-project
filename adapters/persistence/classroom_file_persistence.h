//
// Created by lord on 03/11/2024.
//

#ifndef CLASSROOM_FILE_PERSISTENCE_H
#define CLASSROOM_FILE_PERSISTENCE_H
#include "../../ports/persistence_port.h"
#include "../../lib/data_access/vector/data_access_vector.h"

extern DataAccessVector get_storage_config (void);
extern void destroy_storage_config (void);

ClassroomPersistencePort create_classroom_persistence_port();
#endif //CLASSROOM_FILE_PERSISTENCE_H
