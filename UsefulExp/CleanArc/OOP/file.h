#ifndef _FILE_H_
#define _FILE_H_

struct FILE {
    void (*open)(char* name, int mode);
    void (*close)();
    int (*read)();
    void (*write)(char);
    void (*seek)(long index, int mode);
};

#endif // _FILE_H_ 
