/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonjour.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <jpepin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 03:17:45 by jpepin            #+#    #+#             */
/*   Updated: 2016/10/06 03:49:39 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <libproc.h>
#include <mach/mach_time.h>
#include <sys/sysctl.h>
#include <mach-o/ldsyms.h>
#include <sys/wait.h>
#include <sys/syscall.h>
#include <mach/mach_vm.h>
#include <mach/mach.h>
#include <mach/mach_types.h>
#include <mach/thread_status.h>
#include <mach/thread_act.h>

void error(char *msg)
{
  printf("[!] error: %s.\n",msg);
  exit(1);
}

int main(int ac, char **av)
{
  x86_thread_state_t ppc_state;
  mach_msg_type_number_t sc = x86_THREAD_STATE_COUNT;
  long thread = 0; // for first thread
  thread_act_port_array_t thread_list;
  mach_msg_type_number_t thread_count;
  task_t port;
  pid_t pid;
  if(ac != 2) {
    printf("usage: %s <pid>\n",av[0]);
    exit(1);
  }
  pid = atoi(av[1]);
  if(task_for_pid(mach_task_self(), pid, &port))
    error("cannot get port");
  if(task_suspend(port)) error("suspending the task");
  if(task_threads(port, &thread_list, &thread_count))
    error("cannot get list of tasks");
  if(thread_get_state(
        thread_list[thread],
        x86_THREAD_STATE,
        (thread_state_t)&ppc_state,
        &sc
        )) error("getting state from thread");
  printf("tsh::0x%x, ts32::0x%x, ts64::0x%x\n", ppc_state.tsh, ppc_state.uts.ts32, ppc_state.uts.ts64);
//  ppc_state.tsh = 0xdeadbeef;
  if(thread_set_state(
        thread_list[thread],
        x86_THREAD_STATE,
        (thread_state_t)&ppc_state,
        sc
        )) error("setting state");
  if(task_resume(port)) error("cannot resume the task");
  return 0;
}
