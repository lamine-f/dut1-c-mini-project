//
// Created by lord on 03/11/2024.
//

#ifndef CLASS_FILE_PERSISTENCE_H
#define CLASS_FILE_PERSISTENCE_H
#include "../../ports/persistence_port.h"
#include "../../lib/data_access/vector/data_access_vector.h"

extern DataAccessVector get_storage_config (void);
extern void destroy_storage_config (void);

ClassPersistencePort create_class_persistence_port();
#endif //CLASS_FILE_PERSISTENCE_H
