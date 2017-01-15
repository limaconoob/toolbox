/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 03:37:32 by jpepin            #+#    #+#             */
/*   Updated: 2017/01/15 07:35:49 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <mach/mach.h>
#include <libproc.h>
#include <mach/mach_time.h>
#include <sys/sysctl.h>
#include <mach-o/ldsyms.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/syscall.h>
#include <mach/mach_vm.h>

void report_memory(void)
{ struct task_events_info info;
  mach_msg_type_number_t size = sizeof(info);
  kern_return_t kerr = task_info(mach_task_self(), TASK_EVENTS_INFO, (task_info_t)&info, &size);
  if (kerr == KERN_SUCCESS)
  { printf("Nsys::%d\n", info.syscalls_unix);
    printf("Nmac::%d\n", info.syscalls_mach);
    printf("Sent::%d\n", info.messages_sent);
    printf("Rece::%d\n", info.messages_received); }
  else
  { printf("Error with task_info(): %s", mach_error_string(kerr)); }}


void procpid(pid_t pid)
{ struct proc_bsdinfo proc;
struct proc_vnodepathinfo vpi;
  char pathbuf[PROC_PIDPATHINFO_MAXSIZE];
int ret = proc_pidinfo(pid, PROC_PIDVNODEPATHINFO, 0, &vpi, sizeof(vpi));
  int st = proc_pidinfo(pid, PROC_PIDTBSDINFO, 0, &proc, PROC_PIDTBSDINFO_SIZE);
  proc_pidpath(pid, pathbuf, sizeof(pathbuf));
printf(" cwd: %s\n", vpi.pvi_cdir.vip_path);
  printf("path: %s\n", pathbuf);
  printf("name: %s\n", proc.pbi_name);
  printf("comm: %s\n", proc.pbi_comm);
  printf("flag: %d\n", (int)proc.pbi_flags);
  printf("stat: %d\n", (int)proc.pbi_status);
  printf("xsta: %d\n", (int)proc.pbi_xstatus);
  printf(" pid: %d\n", (int)proc.pbi_pid);
  printf("ppid: %d\n", (int)proc.pbi_ppid);
  printf(" uid: %d\n", (int)proc.pbi_uid);
  printf(" gid: %d\n", (int)proc.pbi_gid);
  printf("ruid: %d\n", (int)proc.pbi_ruid);
  printf("rgid: %d\n", (int)proc.pbi_rgid);
  printf("suid: %d\n", (int)proc.pbi_svuid);
  printf("sgid: %d\n", (int)proc.pbi_svgid);
  printf("nfil: %d\n", (int)proc.pbi_nfiles);
  printf("pgid: %d\n", (int)proc.pbi_pgid);
  printf("pjob: %d\n", (int)proc.pbi_pjobc);
  printf("tdev: %d\n", (int)proc.e_tdev);
  printf("tgid: %d\n", (int)proc.e_tpgid);
  printf("nice: %d\n", (int)proc.pbi_nice);
  printf(" tvs: %lld\n", proc.pbi_start_tvsec);
  printf("tvus: %d\n", (int)proc.pbi_start_tvusec);
}

void pidlist(void)
{ int bufsize = proc_listpids(PROC_ALL_PIDS, 0, NULL, 0);
  pid_t pids[2 * bufsize / sizeof(pid_t)];
  bufsize = proc_listchildpids(38777, pids, sizeof(pids));
  size_t num_pids = bufsize / sizeof(pid_t);
  printf("size::%d, pids::%zu\n", bufsize, num_pids);
  int i = 0;
  while (i < 5)
  { printf("pid[%d]::%d\n", i, pids[i]);
    procpid(pids[i]);
    printf("\n-------------------------------\n\n");
    i += 1; }}
/*
  bufsize = proc_listpids(PROC_ALL_PIDS, 0, pids, sizeof(pids));
  size_t num_pids = bufsize / sizeof(pid_t);
  printf("size::%d, pids::%zu\n", bufsize, num_pids);
  int i = 0;
  while (i < num_pids)
  { printf("pid[%d]::%d\n", i, pids[i]);
    procpid(pids[i]);
    printf("\n-------------------------------\n\n");
    i += 1; }}
*/
void usefork(void)
{ pid_t father;
  char buf;
  int buffer[1024];
  int k;
  k = 0;
  while (42)
  { father = fork();
    printf("fath: %d\n", father);
    struct proc_bsdinfo proc;
    if (father > 0)
    { proc_pidinfo(father, PROC_PIDTBSDINFO, 0, &proc, PROC_PIDTBSDINFO_SIZE);
      k = proc_listchildpids(proc.pbi_ppid, buffer, 1024);
      while (k > -1)
      { printf("ppid[%d]::%d\n", k, buffer[k]);
        k -= 1 ; }
      while (read(0, &buf, 1))
      { if (buf == '\n' || buf == 'q')
        { break ; }}
      if (buf == 'q')
      { break ; }
      wait(NULL); }
    else if (father == 0)
    { exit(EXIT_SUCCESS); }
    wait(NULL); }}

void maxprocess(void)
{ int mib[2];
  int maxproc;
  size_t len;
  mib[0] = CTL_KERN;
  mib[1] = KERN_MAXPROC;
  len = sizeof(maxproc);
  sysctl(mib, 2, &maxproc, &len, NULL, 0);
  printf("Mproc::%d\n", maxproc); }

void process_entries(void)
{ int mib[2];
  size_t len;
  struct kinfo_proc info;
  mib[0] = CTL_KERN;
  mib[1] = KERN_PROC;
  len = sizeof(int);
  sysctl(mib, 2, &info, &len, NULL, 0);
  printf("jobc::%d, pflag::%d, pstat::%d, ppid::%d, poppid::%d, dupfd::%d, userstack::%s, exitthread::%s, debug::%d, sigwait::%d, pestcpu::%d, pcpsticks::%d, ppctcpu::%d, sleepaddress::%s, sleepreason::%s, pswtime::%d, pslptime::%d, /*prealtimer::, prtime::,*/ ptraceflag::%d, ptracep::%p, psiglist::%d, \n", info.kp_eproc.e_jobc,
  info.kp_proc.p_flag,
  (int)info.kp_proc.p_stat,
  info.kp_proc.p_pid,
  info.kp_proc.p_oppid,
  info.kp_proc.p_dupfd,
  info.kp_proc.user_stack,
  info.kp_proc.exit_thread,
  info.kp_proc.p_debugger,
  info.kp_proc.sigwait,
  info.kp_proc.p_estcpu,
  info.kp_proc.p_cpticks,
  info.kp_proc.p_pctcpu,
  info.kp_proc.p_wchan,
  info.kp_proc.p_wmesg,
  info.kp_proc.p_swtime,
  info.kp_proc.p_slptime,
/*  info.kp_proc.p_realtimer,
  info.kp_proc.p_rtime,
  info.kp_proc.p_uticks,
  info.kp_proc.p_sticks,
  info.kp_proc.p_iticks,
*/  info.kp_proc.p_traceflag,
  info.kp_proc.p_tracep,
  info.kp_proc.p_siglist/*,
  info.kp_proc.p_textvp,
  info.kp_proc.p_holdcnt,
  info.kp_proc.p_sigmask,
  info.kp_proc.p_sigignore,
  info.kp_proc.p_sigcatch,
  info.kp_proc.p_priority,
  info.kp_proc.p_usrpri,
  info.kp_proc.p_nice,
  info.kp_proc.p_comm,
  info.kp_proc.p_pgrp,
  info.kp_proc.p_addr,
  info.kp_proc.p_xstat,
  info.kp_proc.p_acflag,
  info.kp_proc.p_ru*/);
}

/*
kern_return_t   task_get_emulation_vector
(task_t task,
 int vector_start,
 emulation_vector_t emulation_vector,
 mach_msg_type_number_t* emulation_vector_count);

kern_return_t   task_set_emulation
(task_t task,
 vm_address_t routine_entry_pt,
 int syscall_number);
*/

void use_mach()
{ void* ptr = malloc(100);
  char buf;
  unsigned long long vmsize;
  unsigned long long address = (unsigned long long)ptr;
  vm_region_basic_info_data_t info;
  mach_msg_type_number_t info_count = VM_REGION_BASIC_INFO_COUNT;
  memory_object_name_t object;
  task_t the_task = mach_task_self();
  kern_return_t status = mach_vm_region(the_task, &address, &vmsize, VM_REGION_BASIC_INFO, (vm_region_info_t)&info, &info_count, &object);
  if (status)
  { perror("vm_region"); }
  while (read(0, &buf, 1))
  { if (buf == '\n')
    { break ; }}
  kern_return_t kerr = task_set_emulation(the_task, address, SYS_read);
  printf("address::%lld\n", address);
  while (read(0, &buf, 1))
  { if (buf == '\n')
    { break ; }}
  if (kerr == KERN_SUCCESS)
  { write(1, "Bonjour\n", 8); }}

int main()
{// process_entries();
 // report_memory();
  pidlist();
 // usefork();
 // maxprocess();
 // report_memory();
 // use_mach();
  return(1); }
