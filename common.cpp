

#include "common.h"
#include "fmemopen.h"

unsigned char * aai::read_file_to_buffer(const char * path, long &size) {
    FILE * file = fopen(path, "rb");
    if (file == NULL) {
        LOG("File not found");
    }
    fseek(file, 0, SEEK_END);
    size = ftell(file);
    fseek(file, 0, SEEK_SET);

    unsigned char *out = new unsigned char[size];
    fread(out, sizeof(unsigned char), size, file);
    fclose(file);

    return out;
}


FILE * aai::file_to_memf(const char *source_file, unsigned char key[32]) {
    long size;
    unsigned char * buff = read_file_to_buffer(source_file, size);
    LOG("file: %s", source_file);

    FILE * in_mem_file = NULL;
    in_mem_file = fmemopen(buff, size, "rb");

    return in_mem_file;
}
