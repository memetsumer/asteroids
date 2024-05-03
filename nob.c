#define NOB_IMPLEMENTATION
#include "nob.h"

int main(int argc, char **argv)
{
    NOB_GO_REBUILD_URSELF(argc, argv);

    nob_log(NOB_INFO, "--- STAGE 1 ---");

    const char *program = nob_shift_args(&argc, &argv);

    Nob_Cmd cmd = {0};
    nob_cmd_append(&cmd, "cc");
    nob_cmd_append(&cmd, "-Wall", "-Wextra", "-ggdb", "-pedantic");

    nob_cmd_append(&cmd, "-I./raylib/raylib-5.0_macos/include");
    // nob_cmd_append(&cmd, "-L./raylib-5.0_macos/lib");
    nob_cmd_append(&cmd, "./raylib/raylib-5.0_macos/lib/libraylib.a");
    nob_cmd_append(&cmd, "-framework", "CoreVideo");
    nob_cmd_append(&cmd, "-framework", "IOKit");
    nob_cmd_append(&cmd, "-framework", "Cocoa");
    nob_cmd_append(&cmd, "-framework", "GLUT");
    nob_cmd_append(&cmd, "-framework", "OpenGL");

    nob_cmd_append(&cmd, "-o", "main", "./src/main.c");

    if (!nob_cmd_run_sync(cmd))
        return 1;

    cmd.count = 0;
    nob_cmd_append(&cmd, "./main");
    if (!nob_cmd_run_sync(cmd))
        return 1;

    return 0;
}