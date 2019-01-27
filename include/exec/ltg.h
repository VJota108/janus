#ifndef _EXEC_LTG_H_
#define _EXEC_LTG_H_

#include "exec.h"

struct ltg_critical_path_t {
  struct jupiter_located_switch_t **sws;

  int    num_switches;
  int    idx;
  int    priority;
  bw_t   bandwidth;
};

struct ltg_upgrade_plan_t {
  struct ltg_critical_path_t *paths;
  int num_paths;
};


struct exec_ltg_t {
  struct exec_t;
  struct rvar_t          **steady_packet_loss;
  struct traffic_stats_t *pod_stats;
  struct traffic_stats_t *core_stats;
  uint32_t num_pods;

  struct ltg_upgrade_plan_t *plan;

  int *pods;
};

struct exec_t *exec_ltg_create(void);

#endif // _EXEC_PUG_H_