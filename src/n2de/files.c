#include "./files.h"

void getDataPath(char *path, const char *type, const uint8_t index)
{
    char str[50];
    memset(str, 0, 50);
    uint8_t num_width = floor(log10(index) + 1);
    snprintf(path, 
            strlen(type) + 1 + 
            strlen(str) + 1 + 
            num_width + 4, 
            "%s%s%u.dat", type, str, index);
}

#ifdef _WIN32
void removeDir(const char *path)
{
    char cmd[255];
    sprintf(cmd, "RMDIR /S /Q %s", path);
    system(cmd);
}
#else
void removeDir(const char *path)
{
    char cmd[255];
    sprintf(cmd, "rm -rf %s", path);
    system(cmd);
}
#endif

#ifdef _WIN32
void touch(const char *path)
{
    char cmd[255];
    sprintf(cmd, "copy /y nul \"%s\"", path);
    system(cmd);
}
#else
void touch(const char *path)
{
    char cmd[255];
    sprintf(cmd, "touch %s", path);
    system(cmd);
}
#endif

int fileno(FILE *stream);

uint32_t fileSize(FILE *fp)
{
    uint32_t size = 0;
    rewind(fp);
    fpos_t position;
    fgetpos(fp, &position);
    fseek(fp, 0L, SEEK_END);
    size = ftell(fp);
    fsetpos(fp, &position);
    return size;
}

long int fileToStr(FILE *fp, char *str)
{
    if ( !fp ){
        return 0;
    }

    rewind(fp);
    fpos_t position;
    fgetpos(fp, &position);

    fseek(fp,0, SEEK_END);
    long int size = ftell(fp);

    fsetpos(fp, &position);
    fread(str, size, 1, fp);
    str += size;
    *str++ = 0;

    return size;
}
