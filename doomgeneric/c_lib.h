#ifndef __C_LIB__
#define __C_LIB__

#include <stdarg.h>
#include <stddef.h>

// stdlib.h

void *C_malloc(size_t size);

void *C_realloc(void* ptr, size_t size);

void *C_calloc(size_t num, size_t size);

void C_free(void *ptr);

void C_exit(int status);

int C_atoi(const char *str);

double C_atof(const char *str);

static inline int C_abs (int n) { return n >= 0 ? n : -n; }

int C_system(const char *command);


// string.h

unsigned long C_strlen (const char *str);

char *C_strdup(const char *str);

char *C_strncpy (char *destination, const char *source, size_t num);

int C_strcmp(const char *str1, const char *str2);

int C_strncmp(const char *str1, const char *str2, size_t num);

char *C_strchr(const char *str, int c);

char *C_strrchr(const char *str, int c);

char *C_strstr(const char *str1, const char *str2);

int C_strcasecmp(const char *s1, const char *s2);

int C_strncasecmp(const char *s1, const char *s2, size_t n);

void *C_memset(void *ptr, int value, size_t num);

void *C_memcpy(void *destination, const void *source, size_t num);

void *C_memmove(void * destination, const void *source, size_t num);


// stdio.h

typedef struct file_t file_t;

int C_printf(const char *format, ...);

int C_puts(const char *s);

int C_putchar(int c);

int C_snprintf(char *s, size_t n, const char *format, ...);

int C_vsnprintf(char *s, size_t n, const char *format, va_list argp);

int C_sscanf(const char *s, const char *format, ...);

file_t *C_stdout(void);

file_t *C_stderr(void);

file_t *C_fopen(const char *filename, const char *mode);

int C_fclose(file_t* stream);

int C_ftell(file_t* stream);

int C_fseek(file_t* stream, long offset, int whence);

int C_seek_set(void);

int C_seek_end(void);

int C_fflush(file_t* stream);

int C_fread(void *ptr, size_t size, size_t num, file_t *stream);

int C_fwrite(const void *ptr, size_t size, size_t num, file_t *stream);

int C_fprintf(file_t *stream, const char *format, ...);

int C_vfprintf(file_t *stream, const char *format, va_list argp);

int C_rename(const char *oldname, const char *newname);

int C_remove(const char *filename);

// math.h

static inline double C_fabs(double x) { return x >= 0 ? x : -x; }

// ctype.h

int C_toupper(int c);

int C_isspace(int c);

// errno.h

int C_errno(void);

int C_e_is_dir(void);

// extras

int C_mkdir(const char *path);

int C_int_str(const int *int_str, char *str, size_t size);

#endif /* #ifndef __C_LIB__ */
