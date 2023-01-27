# Software program

## Tools
- C
- Debian 10.2.1-6
- gcc 10.2.1
- GNU Make 4.3

## Description
*All programs are written by [ME](https://github.com/David2261 "Bulat Nasyrov") in C!
To compile the file more easily, I wrote a Makefile, with
which you can also run programs.
All binary files are stored in the build directory.*

## Log program # 1
_Output: [LOG] 00:04:36 **(Your time)** Module_load_success_

### Start
```bash
make print_module
```

## Succes program # 2 and # 3
_Output: SUCCESS
SUCCESS
SUCCESS_

### Start
```bash
make create_test
make insert_test
```

## Table program # 4
_Output: 
3 |5 |6 |
5 |3 |6 |
6 |5 |3 |
3 |4 |5 |6 |
5 |3 |4 |6 |
6 |5 |3 |4 |_

### Start
```bash
make traverse_test
```

## Clear
_Output: Clear all files format out and binaries_

### Start
```bash
make clear
```

## Example
```c
void print_log(int (*print)(char), char* message) {
    time_t t = time(NULL);
    struct tm* aTm = localtime(&t);
    char  buffer[200];
    int j = 0;

    j  = sprintf(buffer, Log_prefix);
    j += sprintf(buffer + j, " %02d:%02d:%02d ", aTm->tm_hour, aTm->tm_min, aTm->tm_sec);
    j += sprintf(buffer + j, "%s", message);
    j = 0;
    while (buffer[j] != '\0') {
        (*print)(buffer[j]);
        j++; }
}
```

