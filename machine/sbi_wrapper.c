#include "bootstrap.h"
#include "console.h"
#include "tinycstd.h"

int main(int argc, char** argv);
void usermode_test();


void bootstrap() {
    early_init();
    console_init();

    kernel_environ_init();

    char* args[] = {
        "./selfie",
        "-c",
        "selfie.c",
        "-m",
        "32",
        "-l",
        "selfie.m",
        "-y",
        "16",
        "-c",
        "hello-world.c",
        (char*)0,
    };
    int argc = 0;

    puts("Booting selfie with args: \n");

    while (args[argc] != (char *)0) {
      printf("    %s\n", args[argc]);
      argc++;
    }
    printf("    <END>\n\n");

    start_init_process(argc, args);
}
