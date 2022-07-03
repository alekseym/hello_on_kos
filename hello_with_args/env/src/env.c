#include <env/env.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    const char* HelloArgs[] = {
        "Hello", "World"
    };
    const char* HelloEnvs[] = {
        "_HELLO_HOME=//data//",
        "_HELLO_HOME=day"
    };
    ENV_REGISTER_PROGRAM_ENVIRONMENT("Hello", HelloArgs, HelloEnvs);

    envServerRun();

    return EXIT_SUCCESS;
}
