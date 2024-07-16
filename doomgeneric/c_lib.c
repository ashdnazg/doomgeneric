#include "c_lib.h"

#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <errno.h>

#include <sys/stat.h>

void *C_malloc(size_t size)
{
    return malloc(size);
}

void *C_realloc(void* ptr, size_t size)
{
    return realloc(ptr, size);
}

void *C_calloc(size_t num, size_t size)
{
    return calloc(num, size);
}

void C_free(void *ptr)
{
    free(ptr);
}

void C_exit(int status)
{
    exit(status);
}

int C_atoi(const char *str)
{
    return atoi(str);
}

double C_atof(const char *str)
{
    return atof(str);
}

int C_system(const char *command)
{
    return system(command);
}

unsigned long C_strlen(const char *str)
{
    return strlen(str);
}

char *C_strdup(const char *str)
{
    return strdup(str);
}

char *C_strncpy(char *destination, const char *source, size_t num)
{
    return strncpy(destination, source, num);
}

int C_strcmp(const char *str1, const char *str2)
{
    return strcmp(str1, str2);
}

int C_strncmp(const char *str1, const char *str2, size_t num)
{
    return strncmp(str1, str2, num);
}

char *C_strchr(const char *str, int c)
{
    return strchr(str, c);
}

char *C_strrchr(const char *str, int c)
{
    return strrchr(str, c);
}

char *C_strstr(const char *str1, const char *str2)
{
    return strstr(str1, str2);
}

int C_strcasecmp(const char *s1, const char *s2)
{
    return
#ifdef _WIN32
    _stricmp
#else
    strcasecmp
#endif
    (s1, s2);
}

int C_strncasecmp(const char *s1, const char *s2, size_t n)
{
    return
#ifdef _WIN32
    _strnicmp
#else
    strncasecmp
#endif
    (s1, s2, n);
}

void *C_memset(void *ptr, int value, size_t num)
{
    return memset(ptr, value, num);
}

void *C_memcpy(void *destination, const void *source, size_t num)
{
    return memcpy(destination, source, num);
}

void *C_memmove(void * destination, const void *source, size_t num)
{
    return memmove(destination, source, num);
}

int C_printf(const char *format, ...)
{
    va_list argp;
    int ret;
    va_start(argp, format);
    ret = vprintf(format, argp);
    va_end(argp);

    return ret;
}

int C_puts(const char *s)
{
    return puts(s);
}

int C_putchar(int c)
{
    return putchar(c);
}

int C_snprintf(char *s, size_t n, const char *format, ...)
{
    va_list argp;
    int ret;
    va_start(argp, format);
    ret = vsnprintf(s, n, format, argp);
    va_end(argp);

    return ret;
}

int C_vsnprintf(char *s, size_t n, const char *format, va_list argp)
{
    return vsnprintf(s, n, format, argp);
}

int C_sscanf(const char *s, const char *format, ...)
{
    va_list argp;
    int ret;
    va_start(argp, format);
    ret = vsscanf(s, format, argp);
    va_end(argp);

    return ret;
}

file_t *C_stdout(void)
{
    return (file_t *) stdout;
}

file_t *C_stderr(void)
{
    return (file_t *) stderr;
}

file_t *C_fopen(const char *filename, const char *mode)
{
    return (file_t *) fopen(filename, mode);
}

int C_fclose(file_t* stream)
{
    return fclose((FILE *)stream);
}

int C_fflush(file_t* stream)
{
    return fflush((FILE *)stream);
}

int C_fread(void *ptr, size_t size, size_t num, file_t *stream)
{
    return fread(ptr, size, num, (FILE *)stream);
}

int C_fwrite(const void *ptr, size_t size, size_t num, file_t *stream)
{
    return fwrite(ptr, size, num, (FILE *)stream);
}

int C_ftell(file_t* stream)
{
    return ftell((FILE *)stream);
}

int C_fseek(file_t* stream, long offset, int whence)
{
    return fseek((FILE *)stream, offset, whence);
}

int C_seek_set(void)
{
    return SEEK_SET;
}

int C_seek_end(void)
{
    return SEEK_END;
}

int C_fprintf(file_t *stream, const char *format, ...)
{
    va_list argp;
    int ret;
    va_start(argp, format);
    ret = vfprintf((FILE *)stream, format, argp);
    va_end(argp);

    return ret;
}

int C_vfprintf(file_t *stream, const char *format, va_list argp)
{
    return vfprintf((FILE *)stream, format, argp);
}

int C_rename(const char *oldname, const char *newname)
{
    return rename(oldname, newname);
}

int C_remove(const char *filename)
{
    return remove(filename);
}

int C_toupper(int c)
{
    return toupper(c);
}

int C_isspace(int c)
{
    return isspace(c);
}

int C_errno(void)
{
    return errno;
}

int C_e_is_dir(void)
{
    return EISDIR;
}

int C_mkdir(const char *path)
{
    return mkdir(path, 0755);
}
