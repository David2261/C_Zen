#include "point.h"
#include "namedPoint.h"
#include <stdio.h>

/*
 * Наследование
*/

int main(int argc, char** argv) {
    struct NamedPoint* origin = makeNamedPoint(0.0, 0.0, "origin");
    struct NamedPoint* upperRight = makeNamedPoint(1.0, 1.0, "upperRight");
    printf("distance=%f\n", distance(
            (struct Point*) origin,
            (struct Point*) upperRight));
    return 0;
}
