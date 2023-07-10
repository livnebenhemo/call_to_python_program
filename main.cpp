#include <stdio.h>
#include <stdlib.h>
#include <python3.8/Python.h>

int main(int argc, char** argv)
{
    FILE* fp;

    Py_Initialize();

    // Convert the command-line arguments to wide strings
    wchar_t** argv_wide = new wchar_t*[argc];
    for (int i = 0; i < argc-1; ++i) {
        argv_wide[i] = Py_DecodeLocale(argv[i], nullptr);
    }

    // Set the wide string arguments using PySys_SetArgv
    PySys_SetArgv(argc, argv_wide);

    fp = _Py_fopen(argv[argc-1], "r");
    PyRun_SimpleFile(fp, argv[argc-1]);

    Py_Finalize();

    return 0;
}