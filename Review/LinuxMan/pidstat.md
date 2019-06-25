## pidstat
```
PIDSTAT(1)                    Linux User's Manual                   PIDSTAT(1)

NAME
       pidstat - Report statistics for Linux tasks.

SYNOPSIS
       pidstat  [ -d ] [ -H ] [ -h ] [ -I ] [ -l ] [ -R ] [ -r ] [ -s ] [ -t ]
       [ -U [ username ] ] [ -u ] [ -V ] [ -v ] [ -w  ]  [  -C  comm  ]  [  -G
       process_name  ]  [  --human ] [ -p { pid [,...] | SELF | ALL } ] [ -T {
       TASK | CHILD | ALL } ] [ interval [ count ] ] [ -e program args ]

DESCRIPTION
       The pidstat command is used for monitoring individual  tasks  currently
       being managed by the Linux kernel.  It writes to standard output activ‐
       ities for every task selected with option -p or for every task  managed
       by  the  Linux kernel if option -p ALL has been used. Not selecting any
       tasks is equivalent to specifying -p ALL but only active  tasks  (tasks
       with non-zero statistics values) will appear in the report.

       The pidstat command can also be used for monitoring the child processes
       of selected tasks.  Read about option -T below.

       The interval parameter specifies the amount of time in seconds  between
       each  report.   A  value  of 0 (or no parameters at all) indicates that
       tasks statistics are to be reported for the time since  system  startup
       (boot).   The  count parameter can be specified in conjunction with the
       interval parameter if this one is not set to zero. The value  of  count
       determines  the  number of reports generated at interval seconds apart.
       If the interval parameter is specified without the count parameter, the
       pidstat command generates reports continuously.

       You  can select information about specific task activities using flags.
       Not specifying any flags selects only CPU activity.

OPTIONS
       -C comm
              Display only tasks whose command name includes the string  comm.
              This string can be a regular expression.

       -d     Report I/O statistics (kernels 2.6.20 and later only).  The fol‐
              lowing values may be displayed:

              UID
                     The real user identification number  of  the  task  being
                     monitored.

              USER
                     The  name  of  the  real user owning the task being moni‐
                     tored.

              PID
                     The identification number of the task being monitored.

              kB_rd/s
                     Number of kilobytes the task has caused to be  read  from
                     disk per second.

              kB_wr/s
                     Number  of  kilobytes the task has caused, or shall cause
                     to be written to disk per second.

              kB_ccwr/s
                     Number of kilobytes whose writing to disk has  been  can‐
                     celled  by  the  task. This may occur when the task trun‐
                     cates some dirty pagecache. In this case, some  IO  which
                     another  task  has been accounted for will not be happen‐
                     ing.

              iodelay
                     Block I/O delay of the task being monitored, measured  in
                     clock  ticks. This metric includes the delays spent wait‐
                     ing for sync block I/O completion and  for  swapin  block
                     I/O completion.

              Command
                     The command name of the task.

       -e program args
              Execute  program  with  given arguments args and monitor it with
              pidstat.  pidstat stops when program terminates.

       -G process_name
              Display only processes whose command name  includes  the  string
              process_name.   This  string  can  be  a  regular expression. If
              option -t is used together  with  option  -G  then  the  threads
              belonging to that process are also displayed (even if their com‐
              mand name doesn't include the string process_name).

       -H     Display timestamp in seconds since the epoch.

       -h     Display all activities horizontally on a single  line,  with  no
              average statistics at the end of the report. This is intended to
              make it easier to be parsed by other programs.

       --human
              Print sizes in human readable format (e.g. 1k, 1.23M, etc.)  The
              units  displayed  with  this  option supersede any other default
              units (e.g.  kilobytes, sectors...) associated with the metrics.

       -I     In an SMP environment, indicate that tasks CPU  usage  (as  dis‐
              played  by  option -u ) should be divided by the total number of
              processors.

       -l     Display the process command name and all its arguments.

       -p { pid [,...] | SELF | ALL }
              Select  tasks  (processes)  for  which  statistics  are  to   be
              reported.   pid  is  the process identification number. The SELF
              keyword indicates that statistics are to  be  reported  for  the
              pidstat  process  itself, whereas the ALL keyword indicates that
              statistics are to be reported for all the tasks managed  by  the
              system.

       -R     Report realtime priority and scheduling policy information.  The
              following values may be displayed:

              UID
                     The real user identification number  of  the  task  being
                     monitored.

              USER
                     The  name  of  the  real user owning the task being moni‐
                     tored.

              PID
                     The identification number of the task being monitored.

              prio
                     The realtime priority of the task being monitored.

              policy
                     The scheduling policy of the task being monitored.

              Command
                     The command name of the task.

       -r     Report page faults and memory utilization.

              When reporting statistics for individual  tasks,  the  following
              values may be displayed:

              UID
                     The  real  user  identification  number of the task being
                     monitored.

              USER
                     The name of the real user owning  the  task  being  moni‐
                     tored.

              PID
                     The identification number of the task being monitored.

              minflt/s
                     Total  number  of minor faults the task has made per sec‐
                     ond, those which have not required loading a memory  page
                     from disk.

              majflt/s
                     Total  number  of major faults the task has made per sec‐
                     ond, those which have required loading a memory page from
                     disk.

              VSZ
                     Virtual  Size: The virtual memory usage of entire task in
                     kilobytes.

              RSS
                     Resident Set Size: The non-swapped physical  memory  used
                     by the task in kilobytes.

              %MEM
                     The  tasks's  currently  used share of available physical
                     memory.

              Command
                     The command name of the task.

              When reporting global statistics for tasks and all  their  chil‐
              dren, the following values may be displayed:

              UID
                     The  real user identification number of the task which is
                     being monitored together with its children.

              USER
                     The name of the real user owning the task which is  being
                     monitored together with its children.

              PID
                     The identification number of the task which is being mon‐
                     itored together with its children.

              minflt-nr
                     Total number of minor faults made by the task and all its
                     children, and collected during the interval of time.

              majflt-nr
                     Total number of major faults made by the task and all its
                     children, and collected during the interval of time.

              Command
                     The command name of the task  which  is  being  monitored
                     together with its children.

       -s     Report  stack  utilization.   The  following  values may be dis‐
              played:

              UID
                     The real user identification number  of  the  task  being
                     monitored.

              USER
                     The  name  of  the  real user owning the task being moni‐
                     tored.

              PID
                     The identification number of the task being monitored.

              StkSize
                     The amount of memory in kilobytes reserved for  the  task
                     as stack, but not necessarily used.

              StkRef
                     The  amount  of memory in kilobytes used as stack, refer‐
                     enced by the task.

              Command
                     The command name of the task.

       -T { TASK | CHILD | ALL }
              This option specifies what has to be monitored  by  the  pidstat
              command.  The  TASK  keyword indicates that statistics are to be
              reported for individual  tasks  (this  is  the  default  option)
              whereas  the  CHILD  keyword indicates that statistics are to be
              globally reported for the selected tasks and all their children.
              The ALL keyword indicates that statistics are to be reported for
              individual tasks and globally for the selected tasks  and  their
              children.

              Note: Global statistics for tasks and all their children are not
              available for all options of pidstat.  Also these statistics are
              not  necessarily  relevant to current time interval: The statis‐
              tics of a child process are collected only when it  finishes  or
              it is killed.

       -t     Also  display  statistics  for  threads associated with selected
              tasks.

              This option adds the following values to the reports:

              TGID
                     The identification number of the thread group leader.

              TID
                     The identification number of the thread being monitored.

       -U [ username ]
              Display the real user name of the tasks being monitored  instead
              of the UID.  If username is specified, then only tasks belonging
              to the specified user are displayed.

       -u     Report CPU utilization.

              When reporting statistics for individual  tasks,  the  following
              values may be displayed:

              UID
                     The  real  user  identification  number of the task being
                     monitored.

              USER
                     The name of the real user owning  the  task  being  moni‐
                     tored.

              PID
                     The identification number of the task being monitored.

              %usr
                     Percentage of CPU used by the task while executing at the
                     user level (application), with or without nice  priority.
                     Note  that this field does NOT include time spent running
                     a virtual processor.

              %system
                     Percentage of CPU used by the task while executing at the
                     system level (kernel).

              %guest
                     Percentage  of  CPU  spent by the task in virtual machine
                     (running a virtual processor).

              %wait
                     Percentage of CPU spent by the task while waiting to run.

              %CPU
                     Total percentage of CPU time used by the task. In an  SMP
                     environment,  the task's CPU usage will be divided by the
                     total number of CPU's if option -I has  been  entered  on
                     the command line.

              CPU
                     Processor number to which the task is attached.

              Command
                     The command name of the task.

              When  reporting  global statistics for tasks and all their chil‐
              dren, the following values may be displayed:

              UID
                     The real user identification number of the task which  is
                     being monitored together with its children.

              USER
                     The  name of the real user owning the task which is being
                     monitored together with its children.

              PID
                     The identification number of the task which is being mon‐
                     itored together with its children.

              usr-ms
                     Total  number  of  milliseconds spent by the task and all
                     its children while executing at the user level  (applica‐
                     tion),  with or without nice priority, and collected dur‐
                     ing the interval of time. Note that this field  does  NOT
                     include time spent running a virtual processor.

              system-ms
                     Total  number  of  milliseconds spent by the task and all
                     its children while executing at the  system  level  (ker‐
                     nel), and collected during the interval of time.

              guest-ms
                     Total  number  of  milliseconds spent by the task and all
                     its children in virtual machine (running a  virtual  pro‐
                     cessor).

              Command
                     The  command  name  of  the task which is being monitored
                     together with its children.

       -V     Print version number then exit.

       -v     Report values of some kernel tables. The following values may be
              displayed:

              UID
                     The  real  user  identification  number of the task being
                     monitored.

              USER
                     The name of the real user owning  the  task  being  moni‐
                     tored.

              PID
                     The identification number of the task being monitored.

              threads
                     Number of threads associated with current task.

              fd-nr
                     Number of file descriptors associated with current task.

              Command
                     The command name of the task.

       -w     Report  task switching activity (kernels 2.6.23 and later only).
              The following values may be displayed:

              UID
                     The real user identification number  of  the  task  being
                     monitored.

              USER
                     The  name  of  the  real user owning the task being moni‐
                     tored.

              PID
                     The identification number of the task being monitored.

              cswch/s
                     Total number of voluntary context switches the task  made
                     per  second.   A  voluntary  context switch occurs when a
                     task blocks  because  it  requires  a  resource  that  is
                     unavailable.

              nvcswch/s
                     Total  number  of non voluntary context switches the task
                     made per second.   A  involuntary  context  switch  takes
                     place  when  a task executes for the duration of its time
                     slice and then is forced to relinquish the processor.

              Command
                     The command name of the task.

ENVIRONMENT
       The pidstat command takes into account the following environment  vari‐
       ables:

       S_COLORS
              When  this  variable  is set, display statistics in color on the
              terminal.  Possible values for this variable are  never,  always
              or auto (the latter is the default).

              Please  note  that  the  color (being red, yellow, or some other
              color) used to display a value is not indicative of any kind  of
              issue  simply  because of the color. It only indicates different
              ranges of values.

       S_COLORS_SGR
              Specify the colors and other attributes used to display  statis‐
              tics  on  the  terminal.  Its value is a colon-separated list of
              capabilities            that             defaults             to
              H=31;1:I=32;22:M=35;1:N=34;1:Z=34;22.    Supported  capabilities
              are:

              H=     SGR (Select Graphic Rendition) substring  for  percentage
                     values greater than or equal to 75%.

              I=     SGR  substring  for item values like PID, UID or CPU num‐
                     ber.

              M=     SGR substring for percentage values in the range from 50%
                     to 75%.

              N=     SGR  substring  for  non-zero  statistics  values and for
                     tasks names.

              Z=     SGR substring for zero values and for threads names.

       S_TIME_FORMAT
              If this variable exists and its value is ISO  then  the  current
              locale  will  be  ignored  when  printing the date in the report
              header.  The pidstat  command  will  use  the  ISO  8601  format
              (YYYY-MM-DD) instead.  The timestamp will also be compliant with
              ISO 8601 format.

EXAMPLES
       pidstat 2 5
              Display five reports of CPU statistics for every active task  in
              the system at two second intervals.

       pidstat -r -p 1643 2 5
              Display  five  reports  of page faults and memory statistics for
              PID 1643 at two second intervals.

       pidstat -C "fox|bird" -r -p ALL
              Display global page faults and memory  statistics  for  all  the
              processes  whose  command  name  includes  the  string  "fox" or
              "bird".

       pidstat -T CHILD -r 2 5
              Display five reports of page faults  statistics  at  two  second
              intervals  for  the  child processes of all tasks in the system.
              Only child processes with non-zero statistics  values  are  dis‐
              played.

BUGS
       /proc filesystem must be mounted for the pidstat command to work.

FILES
       /proc contains various files with system statistics.

AUTHOR
       Sebastien Godard (sysstat <at> orange.fr)

SEE ALSO
       sar(1), top(1), ps(1), mpstat(1), iostat(1), vmstat(8)

       http://pagesperso-orange.fr/sebastien.godard/

Linux                              JULY 2017                        PIDSTAT(1)
```
## 翻译

### 名称
    pidstats - 报告linux任务的统计信息。
### 概要
    pidstat  [ -d ] [ -H ] [ -h ] [ -I ] [ -l ] [ -R ] [ -r ] [ -s ] [ -t ]
           [ -U [ username ] ] [ -u ] [ -V ] [ -v ] [ -w  ]  [  -C  comm  ]  [  -G
           process_name  ]  [  --human ] [ -p { pid [,...] | SELF | ALL } ] [ -T {
           TASK | CHILD | ALL } ] [ interval [ count ] ] [ -e program args ]
### 描述
     pidstat命令用于监视当前由Linux内核管理各个任务。它写入标准输出活动通过选项-p或
      如果使用选项-p ALL时则由Linux内核提供管理的每个任务都可以使用。
      没有选择任何任务等同于指定-p ALL但仅指定活动任务（任务报告中将显示非零统计值）。
    
    pidstat命令还可用于监视子进程选定的任务。阅读下面的选项-T。
    
    interval参数指定之间的时间量（以秒为单位）每份报告。
    值0（或根本没有参数）表示任务统计信息将在系统启动后报告（引导）。 
    count参数可以与interval参数一起指定，如果此参数未设置为零。 
    count的值确定以间隔秒间隔生成的报告数。
    如果指定了interval参数而没有count参数，则pidstat命令不断生成报告。
    
    您可以使用标志选择有关特定任务活动的信息。不指定任何标志仅选择CPU活动。
### 选项
    - '-C' comm
            仅显示其命令名称包含字符串comm的任务。该字符串可以是正则表达式。

    - '-d'
            报告I / O统计信息（仅内核2.6.20及更高版本）。下面的值可能会显示：
        - UID
            正在进行监控的任务的真实用户标识号。
        - USER
            正在进行监控的任务的真实拥有的用户名称。
        - PID
            增在进行监控的任务识别码。
        - KB_rd/s
            任务导致读取的千字节数每秒磁盘数。
        - KB_wr/s
            任务导致或将导致的千字节数每秒写入磁盘。
        - KB_ccwr/s
            写入磁盘的任务已取消的千字节数。 当任务截断一些脏pagecache时，可能会发生这种情况。 在这种情况下，将会发生一些已经考虑了另一个任务的IO。
        - iodelay
            正在监视的任务的阻塞I / O延迟时间，该指标包括等待的延迟用于同步块I / O完成和swapin块I / O完成。
        - Command
            任务命令名称
    - '-e' 程序参数
        使用给定的参数args执行程序并使用它进行监视pidstat。当程序终止时，pidstat停止。
    - '-G' 进程名称
        仅显示其命令名称包含字符串的进程PROCESS_NAME。该字符串可以是正则表达式。
        如果选项-t与选项-G和线程一起使用属于该过程的也会显示（即使他们的mand name不包含字符串process_name）。
    - '-H' 显示自纪元以来的秒数
    - '-h' 
        显示在一行上水平显示所有活动，没有报告结尾的平均统计数据。这是为了使其他程序更容易解析。
    - '--human' 
        以人类可读格式打印尺寸（例如1k，1.23M等）使用此选项显示的单位将取代任何其他默认值与度量相关联的单位（例如千字节，扇区......）。
    - '-I'
        在SMP环境中，指示任务CPU使用情况（如选项-u）播放应该除以总数处理器。
    - '-l'
        显示进程的命令和所有的参数。
    - '-p { pid [,...] | SELF | ALL }'
        选择要统计的任务（进程）报道。 pid是进程标识号。 
        self关键字表示要为其报告统计信息pidstat进程本身，
        而ALL关键字表示将报告由管理的所有任务的统计信息系统。
    - '-R'
        报告实时优先级和调度策略信息。可能会显示以下值：
        - UID
            被监控任务的真实用户识别码
        - USER
            被监控任务的拥有用户的名称。
        - PID
            被监控任务的识别码。
        - prio
            被监控任务的实时优先级。
        - policy
            被监控任务的调度策略信息。
        - Command
            任务的命令名称
    - '-r'
        报告页面错误和内存利用率。
        报告单个任务的统计信息时，如下所示值可能会显示：
        - UID
            被监控任务的真实用户识别码
        - USER
            被监控任务的拥有用户的名称
        - PID
            被监控任务的识别码
        - minflt/s
            每秒任务所产生的次要故障总数，即不需要从磁盘加载内存页的故障总数。
        - majflt/s
            每秒任务所产生的主要故障总数，即需要从磁盘加载内存页的故障总数。
        - VSZ
            虚拟大小：整个任务的虚拟内存使用量，以千字节为单位。
        - RSS
            驻留集大小：任务使用的非交换物理内存，以千字节为单位。
        - %MEM
            当前任务使用物理内存的百分比
        - Command
            当前任务的命令名称
        当报告全部任务和他们子任务的统计信息时，会显示下面的值：
        - UID
            与其子项一起监视的任务的真实用户标识号。
        - USER
            与其子项一起监控的任务的真实用户名称。
        - PID
            与其子项一起监控的任务的识别号。
        - minflt-nr
            在间隔时间内任务与其子项产生的次要错误总数。
        - majflt-nr
            在间隔时间内任务与其子项产生的主要错误总数。
        - Command
            与其子项一起监控的任务的命令名称。
    - '-s'
        报告栈利用率。下面的值可能会出现：
        - UID
            被监控任务的真实用户识别码
        - USER
            被监控任务的真是用户名称
        - PID
            被监控任务的识别码
        - StkSize
            以堆栈形式保留的任务的内存量（以千字节为单位），但不一定使用。
        - StkRef
            作为堆栈使用的以千字节为单位的内存量，由任务引用。
        - Command
            任务的命令名称
    - '-T { TASK | CHILD | ALL }'
        此选项指定pidstat命令必须监视的内容。 
        TASK关键字表示统计信息报告单个任务（这是默认选项），
        CHILD关键字表示要为所选任务及其所有子项全局报告统计信息，
        ALL关键字表示要为单个任务报告统计信息，并为所选任务和他们的孩子全局报告统计信息。
        
        注意：pidstat的所有选项都不能使用任务及其所有子项的全局统计信息。 此外，这些统计数据不一定与当前时间间隔相关：子进程的统计信息仅在完成或被杀死时收集。
        
    - '-t'
        显示所选任务相关线程的统计信息。
        这个选项会添加如下值进行显示：
        - TGID
            线程组的识别编号
        - TID
            被监控线程的识别编号
    - U [username]
        显示正在监视的任务的真实用户名UID。 如果指定了username，则只有属于的任务显示指定的用户。
    - u
     报告CPU的利用率。当报告单个任务的统计信息时，下面的值会被被显示：
        - UID
            被监控任务的真实用户识别编号
        - USER
            被监控任务的真实用户的名称
        - PID
            被监控任务的识别编号
        - %usr
            在用户级别（应用程序）执行时任务使用的CPU百分比，包含有优先级和没有优先级。请注意，此字段不包括运行虚拟处理器所花费的时间。
        - %system
            在内核级别执行时任务使用CPU的百分比。
        - %guest
            任务在虚拟机器（运行虚拟处理器）使用CPU的百分比。
        - %wait
            任务等待运行时使用CPU的百分比
        - %CPU
            任务使用CPU百分比总和，
        - CPU
            执行任务的CPU编号
        - Command
            任务的命令名称
        当报告任务与其子项的全部统计信息时，以下信息会被显示：
        - UID
            与其子项一起的任务的真实用户识别编号
        - USER
            与其子项一起的任务的真实的用户名称
        - PID  
            与其子项一起的任务的识别编号
        - usr-ms
            在间隔时间内收集用户级别（应用程序）执行时，任务及其所有子节点在有或没有优先级的情况下花费的总毫秒数。 请注意，此字段不包括运行虚拟处理器所花费的时间。
        - system-ms
            在间隔时间内收集内核级别执行时，任务及其所有子节点执行花费的总毫秒数。
        - guest-ms
            在间隔时间内收集在虚拟机器（虚拟处理器）执行时，任务机器所有子节点花费的总毫秒数。
        - Command
            与其子项一起的任务的命令名称
     - '-V'
        打印版本数字然后退出。
     - '-v'
        报告一些内核表格的值，下面的值会被显示：
        - UID
            被监控任务的真实用户识别码
        - USER
            被监控任务的真是用户名称
        - PID
            被监控任务的识别码
        - threads
            当前任务相关的线程数
        - fd-nr
            当前任务的相关的文件描述符数
        - Command
            任务的命令名称
     - '-w'
        报告任务切换活动（仅限内核2.6.23及更高版本）。可能会显示以下值：
         - UID
            被监控任务的真实用户识别码
         - USER
            被监控任务的真实用户名称
         - PID
            被监控任务的识别编号
         - cswch/s
            每秒任务所做的自愿上下文切换的总数。 当任务阻塞时会发生自愿上下文切换，因为它需要一个不可用的资源。
         - nvcswch/s
            每秒任务所做的非自愿上下文切换的总数。 当任务在其时间片的持续时间内执行时，发生非自愿的上下文切换，然后被迫放弃处理器。
         - Command
            任务命令名称
            
### 示例
    - pidstat 2 5
        显示5次每间隔2s每个活跃任务的CPU统计信息。
    - pidstat -r -p 1643 2 5
        显示5次每间隔2sPID为1643的页面错误和内存统计信息。
    - pidstat -C "fox|bird" -r -p ALL
        显示执行命令中包含字符串"fox"或字符串"bird"的任务的页面错误和内存统计信息。
    - podstat -T CHILD -r 2 5
        显示5次每间隔2s系统中所有任务的子进程的页面错误统计信息，只有子进程数不为0的进程才会显示出来。