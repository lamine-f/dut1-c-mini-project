#include <stdio.h>
#include <stdlib.h>

#include "domain/class/class_.h"
#include "ports/persistence_port.h"
#include "adapters/persistence/class_file_persistence.h"


void on_exit () {
    destroy_storage_config();
}

int main(void)
{
    /*
     *  Configs
     */
        atexit(on_exit);

    /*
     *  Main program
     */
    Class dut1_class = load_class_by_code(1);
    Class dut2_class = load_class_by_code(2);

    // save_class(dut1_class);
    // save_class(dut2_class);
    printf("%s", class_name(dut2_class));

    destroy_class(dut1_class);
    destroy_class(dut2_class);
    // destroy_class(class2);
    return EXIT_SUCCESS;
}
