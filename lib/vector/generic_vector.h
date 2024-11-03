//
// Created by lord on 02/11/2024.
//

#ifndef GENERIC_VECTOR_H
#define GENERIC_VECTOR_H
typedef struct genericVector* GenericVector;
extern      GenericVector       create_generic_vector(void);
extern      void                destroy_generic_vector(GenericVector self);
extern      void*               generic_vector_read_element(GenericVector self, int index);
extern      void                generic_vector_write_element(GenericVector self, int index, void* element);
extern      int                 generic_vector_max_index(GenericVector self);
#endif //GENERIC_VECTOR_H
