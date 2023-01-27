#ifndef _NAMEDPOINT_H_
#define _NAMEDPOINT_H_

struct NamedPoint;

struct NamedPoint* makeNamedPoint(double x, double y, char* name);
void setName(struct NamedPoint* np, char* name);
char* getName(struct NamedPoint* np);


#endif // _NAMEDPOINT_H_

