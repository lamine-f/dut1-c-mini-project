//
// Created by lord on 02/11/2024.
//

#ifndef DATA_ACCESS_VECTOR_H
#define DATA_ACCESS_VECTOR_H
#include "../../vector/generic_vector.h"
#include "../data_access.h"
typedef struct dataAccessVector* DataAccessVector;
extern      DataAccessVector    create_data_access_vector(void);
extern      void                destroy_data_access_vector(DataAccessVector self);
extern      DataAccess          data_access_vector_read_element(DataAccessVector self, DataAccessType index);
extern      void                data_access_vector_write_element(DataAccessVector self, DataAccessType index, DataAccess element);
extern      int                 data_access_vector_max_index(DataAccessVector self);
#endif //DATA_ACCESS_VECTOR_H
