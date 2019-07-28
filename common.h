//
// Created by advance on 12/9/18.
//

#ifndef AAI_COMMON_H
#define AAI_COMMON_H

namespace aai {
unsigned char * read_file_to_buffer(const char * path, long &size);
FILE * file_to_memf(const char *source_file);
}
#endif //AAI_COMMON_H
