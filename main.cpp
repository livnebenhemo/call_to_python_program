#include <stdio.h>
#include <stdlib.h>
#include <python3.8/Python.h>

int main(int argc, char** argv)
{
    char filename[] = "/home/livne/PycharmProjects/Polygon-coreset/get_coreset_one_file.py";
    FILE* fp;

    // Set the working directory to the root directory of your Python project
    chdir("/home/livne/PyCharmProjects/Polygon-coreset/");

    Py_Initialize();

    // Convert the command-line arguments to wide strings
    wchar_t** argv_wide = new wchar_t*[argc];
    for (int i = 0; i < argc; ++i) {
        argv_wide[i] = Py_DecodeLocale(argv[i], nullptr);
    }

    // Set the wide string arguments using PySys_SetArgv
    PySys_SetArgv(argc, argv_wide);

    fp = _Py_fopen(filename, "r");
    PyRun_SimpleFile(fp, filename);

    Py_Finalize();

    // Set the working directory to the original root directory of the CPP project
    chdir("/home/livne/CLionProjects/callToPythonProgram/");

    return 0;
}