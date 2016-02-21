#include "gssa.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

struct systemConf GSSAStepPure(struct GSSAState state, struct GSSADef system, double r1, double r2) {
  system.alpha0 = system.alpha1;

  double tau = (1 / system.alpha0) * log(1 / r1);

  state.time += tau;

  if (r2 > 0 && r2 < (system.alpha1 / system.alpha0)) {
    state.numberOfMolecules--;
  }

  state.reactionNumber++;

  struct systemConf newConf = {.state = state, .system = system};

  return newConf;
}

struct systemConf GSSAStep(struct GSSAState state, struct GSSADef system) {
  double r1 = RAND_DBL;
  double r2 = RAND_DBL;
  return GSSAStepPure(state, system, r1, r2);
}


int main(void) {
  // Seed rng
  srand(time(NULL));
  struct GSSAState initial =
    {.time = 0.0, .reactionNumber = 0, .numberOfMolecules = 100};
  struct GSSADef system =
    {.k1 = 0.5, .alpha1 = 0.5};
  struct systemConf new = GSSAStep(initial, system);
  struct GSSAState result = new.state;
  printf("State:\n\tTime = %f\n\tReaction no. = %d\n\tNo. molecules = %d\n", result.time, result.reactionNumber, result.numberOfMolecules);
  return 0;
}
