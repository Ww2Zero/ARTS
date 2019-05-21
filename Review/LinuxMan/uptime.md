
## uptime
```bash
UPTIME(1)                        User Commands                       UPTIME(1)

NAME
       uptime - Tell how long the system has been running.

SYNOPSIS
       uptime [options]

DESCRIPTION
       uptime gives a one line display of the following information.  The cur‐
       rent time, how long the system has been running,  how  many  users  are
       currently  logged  on,  and the system load averages for the past 1, 5,
       and 15 minutes.

       This is the same information contained in the header line displayed  by
       w(1).

       System load averages is the average number of processes that are either
       in a runnable or uninterruptable state.  A process in a runnable  state
       is  either using the CPU or waiting to use the CPU.  A process in unin‐
       terruptable state is waiting for some I/O access, eg waiting for  disk.
       The  averages  are  taken over the three time intervals.  Load averages
       are not normalized for the number of CPUs in a system, so a load  aver‐
       age  of 1 means a single CPU system is loaded all the time while on a 4
       CPU system it means it was idle 75% of the time.

OPTIONS
       -p, --pretty
              show uptime in pretty format

       -h, --help
              display this help text

       -s, --since
              system up since, in yyyy-mm-dd HH:MM:SS format

       -V, --version
              display version information and exit

FILES
       /var/run/utmp
              information about who is currently logged on

       /proc  process information

AUTHORS
       uptime was written by Larry Greenfield ⟨greenfie@gauss.rutgers.edu⟩ and
       Michael K. Johnson ⟨johnsonm@sunsite.unc.edu⟩

SEE ALSO
       ps(1), top(1), utmp(5), w(1)

REPORTING BUGS
       Please send bug reports to ⟨procps@freelists.org⟩

procps-ng                        December 2012                       UPTIME(1)
```
## 翻译
###名称
**uptime** 打印系统的总共运行时间。
###详细描述
**uptime**主要通过一行来展示`当前时间`，`系统总共运行时间`，`登陆用户数`，过去1分钟，5分钟，15分钟的`平均负载`等信息。
这些信息和_w_命令所展示的第一行信息相同。
- **系统平均负载**是当前处于可运行状态或不可中断状态下进程的平均进程数。
   - 可运行状态的进程是指正在使用cpu或者正在等待cpu的进程。处于R状态（running或runnable）的进程。
   - 不可中断状态的进程是指正在等I/O响应的内核态关键流程中的进程。处于D状态（uninterruptible Sleep 也称 Disk Sleep）进程。
   - 平均负载的值是在3个不同时间段获取的。
   - 平均负载的值对于系统的cpu没有一个标准的值，当平均负载为1时对于4个逻辑cpu的系统而言有75%的处于空闲状态。
###参数选项
- **-p --pretty** 以漂亮的格式展示uptime信息
- **-h --help** 显示帮助信息
- **-s --since** 显示从指定时间开始的信息 
- **-V --version** 显示版本信息
