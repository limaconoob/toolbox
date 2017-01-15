#include <mach/mach.h>
#include <libproc.h>
#include <mach/mach_time.h>
#include <sys/sysctl.h>
#include <mach-o/ldsyms.h>

struct proc_bsdinfo {
  uint32_t    pbi_flags;    /* 64bit; emulated etc */
  uint32_t    pbi_status;
  uint32_t    pbi_xstatus;
  uint32_t    pbi_pid;
  uint32_t    pbi_ppid;
  uid_t     pbi_uid;
  gid_t     pbi_gid;
  uid_t     pbi_ruid;
  gid_t     pbi_rgid;
  uid_t     pbi_svuid;
  gid_t     pbi_svgid;
  uint32_t    rfu_1;      /* reserved */
  char      pbi_comm[MAXCOMLEN];
  char      pbi_name[2*MAXCOMLEN];  /* empty if no name is registered */
  uint32_t    pbi_nfiles;
  uint32_t    pbi_pgid;
  uint32_t    pbi_pjobc;
  uint32_t    e_tdev;     /* controlling tty dev */
  uint32_t    e_tpgid;    /* tty process group id */
  int32_t     pbi_nice;
  uint64_t    pbi_start_tvsec;
  uint64_t    pbi_start_tvusec;
};

struct proc_bsdshortinfo {
  uint32_t                pbsi_pid;   /* process id */
  uint32_t                pbsi_ppid;    /* process parent id */
  uint32_t                pbsi_pgid;    /* process perp id */
  uint32_t                pbsi_status;    /* p_stat value, SZOMB, SRUN, etc */
  char                    pbsi_comm[MAXCOMLEN]; /* upto 16 characters of process name */
  uint32_t                pbsi_flags;              /* 64bit; emulated etc */
  uid_t                   pbsi_uid;   /* current uid on process */
  gid_t                   pbsi_gid;   /* current gid on process */
  uid_t                   pbsi_ruid;    /* current ruid on process */
  gid_t                   pbsi_rgid;    /* current tgid on process */
  uid_t                   pbsi_svuid;   /* current svuid on process */
  gid_t                   pbsi_svgid;   /* current svgid on process */
  uint32_t                pbsi_rfu;   /* reserved for future use*/
};

