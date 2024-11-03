#include <stdio.h>
#include <stdlib.h>

#include "domain/classroom/classroom.h"
#include "ports/persistence_port.h"
#include "adapters/persistence/classroom_file_persistence.h"


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
    Classroom dut1_classroom = load_classroom_by_code(1);
    Classroom dut2_classroom = load_classroom_by_code(2);

    // save_classroom(dut1_classroom);
    // save_classroom(dut2_classroom);
    printf("%s", classroom_name(dut2_classroom));

    destroy_classroom(dut1_classroom);
    destroy_classroom(dut2_classroom);
    // destroy_classroom(classroom2);
    return EXIT_SUCCESS;
}
