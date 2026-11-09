#ifndef _ID2_H_
#define _ID2_H_

#define ID 10
#define DYN 11
#define F_DIR 12
#define APPX 13

typedef enum state {
  BEGIN,
  MIDDLE,
  END,
} LSTATE;

struct OPE {
  char *name;
  int type;
  int type2;
  LSTATE state;
};

#endif