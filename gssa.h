#include <inttypes.h>

#define RAND_DBL ((double) rand() / (double) RAND_MAX)

struct GSSAState {
  double time;
  int32_t reactionNumber;
  int32_t numberOfMolecules;
};

struct GSSADef {
  double k1;
  double alpha0;
  double alpha1;
};

struct systemConf {
  struct GSSAState state;
  struct GSSADef system;
};

struct systemConf GSSAStepPure(
  struct GSSAState state, struct GSSADef system, double r1, double r2
);

struct systemConf GSSAStep(
  struct GSSAState state, struct GSSADef system
);
