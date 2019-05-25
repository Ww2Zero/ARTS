## mpstat
```
MPSTAT(1)                                                                                   Linux User's Manual                                                                                  MPSTAT(1)

NAME
       mpstat - Report processors related statistics.

SYNOPSIS
       mpstat [ -A ] [ -n ] [ -u ] [ -V ] [ -I { keyword [,...] | ALL } ] [ -N { node_list | ALL } ] [ -o JSON ] [ -P { cpu_list | ON | ALL } ] [ interval [ count ] ]

DESCRIPTION
       The  mpstat  command  writes  to  standard output activities for each available processor, processor 0 being the first one.  Global average activities among all processors are also reported.  The
       mpstat command can be used both on SMP and UP machines, but in the latter, only global average activities will be printed. If no activity has been selected, then the default  report  is  the  CPU
       utilization report.

       The  interval  parameter  specifies the amount of time in seconds between each report.  A value of 0 (or no parameters at all) indicates that processors statistics are to be reported for the time
       since system startup (boot).  The count parameter can be specified in conjunction with the interval parameter if this one is not set to zero. The value of count determines the number  of  reports
       generated at interval seconds apart. If the interval parameter is specified without the count parameter, the mpstat command generates reports continuously.

OPTIONS
       -A     This option is equivalent to specifying -n -u -I ALL -N ALL -P ALL

       -I { keyword [,...] | ALL }
              Report interrupts statistics.

              Possible keywords are CPU, SCPU, and SUM.

              With the CPU keyword, the number of each individual interrupt received per second by the CPU or CPUs is displayed. Interrupts are those listed in /proc/interrupts file.

              With  the SCPU keyword, the number of each individual software interrupt received per second by the CPU or CPUs is displayed. This option works only with kernels 2.6.31 and later. Software
              interrupts are those listed in /proc/softirqs file.

              With the SUM keyword, the mpstat command reports the total number of interrupts per processor.  The following values are displayed:

              CPU
                     Processor number. The keyword all indicates that statistics are calculated as averages among all processors.

              intr/s
                     Show the total number of interrupts received per second by the CPU or CPUs.

              The ALL keyword is equivalent to specifying all the keywords above and therefore all the interrupts statistics are displayed.

       -N { node_list | ALL }
              Indicate the NUMA nodes for which statistics are to be reported.  node_list is a list of comma-separated values or range of values (e.g., 0,2,4-7,12-).  Note that node all  is  the  global
              average among all nodes. The ALL keyword indicates that statistics are to be reported for all nodes.

       -n     Report summary CPU statistics based on NUMA node placement. The following values are displayed:

              NODE
                     Node number. The keyword all indicates that statistics are calculated as averages among all nodes.

              All the other fields are the same as those displayed with option -u (see below).

       -o JSON
              Display the statistics in JSON (Javascript Object Notation) format.  JSON output field order is undefined, and new fields may be added in the future.

       -P { cpu_list | ON | ALL }
              Indicate  the  processors for which statistics are to be reported.  cpu_list is a list of comma-separated values or range of values (e.g., 0,2,4-7,12-).  Note that processor 0 is the first
              processor, and processor all is the global average among all processors.  The ON keyword indicates that statistics are to be reported for every online processor, whereas  the  ALL  keyword
              indicates that statistics are to be reported for all processors.

       -u     Report CPU utilization. The following values are displayed:

              CPU
                     Processor number. The keyword all indicates that statistics are calculated as averages among all processors.

              %usr
                     Show the percentage of CPU utilization that occurred while executing at the user level (application).

              %nice
                     Show the percentage of CPU utilization that occurred while executing at the user level with nice priority.

              %sys
                     Show  the percentage of CPU utilization that occurred while executing at the system level (kernel). Note that this does not include time spent servicing hardware and software inter‐
                     rupts.

              %iowait
                     Show the percentage of time that the CPU or CPUs were idle during which the system had an outstanding disk I/O request.

              %irq
                     Show the percentage of time spent by the CPU or CPUs to service hardware interrupts.

              %soft
                     Show the percentage of time spent by the CPU or CPUs to service software interrupts.

              %steal
                     Show the percentage of time spent in involuntary wait by the virtual CPU or CPUs while the hypervisor was servicing another virtual processor.

              %guest
                     Show the percentage of time spent by the CPU or CPUs to run a virtual processor.

              %gnice
                     Show the percentage of time spent by the CPU or CPUs to run a niced guest.

              %idle
                     Show the percentage of time that the CPU or CPUs were idle and the system did not have an outstanding disk I/O request.

              Note: On SMP machines a processor that does not have any activity at all is a disabled (offline) processor.

       -V     Print version number then exit.

ENVIRONMENT
       The mpstat command takes into account the following environment variable:

       S_COLORS
              When this variable is set, display statistics in color on the terminal.  Possible values for this variable are never, always or auto (the latter is the default).

              Please note that the color (being red, yellow, or some other color) used to display a value is not indicative of any kind of issue simply because of the color. It only indicates  different
              ranges of values.

       S_COLORS_SGR
              Specify   the   colors   and   other   attributes   used   to   display   statistics   on   the   terminal.   Its  value  is  a  colon-separated  list  of  capabilities  that  defaults  to
              H=31;1:I=32;22:M=35;1:N=34;1:Z=34;22.  Supported capabilities are:

              H=     SGR (Select Graphic Rendition) substring for percentage values greater than or equal to 75%.

              I=     SGR substring for CPU number.

              M=     SGR substring for percentage values in the range from 50% to 75%.

              N=     SGR substring for non-zero statistics values.

              Z=     SGR substring for zero values.

       S_TIME_FORMAT
              If this variable exists and its value is ISO then the current locale will be ignored when printing the date in the report  header.   The  mpstat  command  will  use  the  ISO  8601  format
              (YYYY-MM-DD) instead.  The timestamp will also be compliant with ISO 8601 format.

EXAMPLES
       mpstat 2 5
              Display five reports of global statistics among all processors at two second intervals.

       mpstat -P ALL 2 5
              Display five reports of statistics for all processors at two second intervals.

BUGS
       /proc filesystem must be mounted for the mpstat command to work.

       Only a few activities are given by the Linux kernel for each processor.

FILES
       /proc contains various files with system statistics.

AUTHOR
       Sebastien Godard (sysstat <at> orange.fr)

SEE ALSO
       sar(1), pidstat(1), iostat(1), vmstat(8)

       http://pagesperso-orange.fr/sebastien.godard/

Linux                                                                                            MAY 2017                                                                                        MPSTAT(1)
```
## 翻译
### 名称
报告处理器相关的统计信息。
### 概要
```
mpstat [ -A ] [ -n ] [ -u ] [ -V ] [ -I { keyword [,...] | ALL } ] [ -N { node_list | ALL } ] [ -o JSON ] [ -P { cpu_list | ON | ALL } ] [ interval [ count ] ]
```
### 描述
mpstat命令展示每个可用处理器的标准输出活动，第一行显示处理器0的活动信息，同时报告所有处理器的平均活动信息。可以在SMP和UP机器上使用mpstat命令，但只有在UP机器上，只会显示出全局平均活动信息。如果没有选择任何活动，默认报告输出CPU的使用情况。
- 这个间隔参数（interval）指定每个输出报告的间隔时间。间隔参数为0或没有间隔参数时将输出系统启动以来的处理器活动统计信息。
- 这个统计参数（count）关联间隔参数（interval），当间隔参数不为0时，指定以间隔（interval）秒间隔生成的报告数。
- 如果设置了间隔参数没有设置统计参数，mpstat将不断的输出报告信息。
### 选项
- **-A** 相当于指定了`-n -u -I ALL -N ALL -P ALL`参数
- **-I { keyword [,...] | ALL }** 输出中断统计报告。
       - keyword可以是 *CPU*,*SCPU*,*SUM*,*ALL*等选项值
       - 当keyword是*CPU*时，显示CPU每秒接收不同类型中断的数量。中断被监控在 */proc/interrupt*文件中。
       - 当keyword是 *SCPU*时，显示CPU每秒接收软中断的数量，这个参数只在内核2.6.31之后可用，软中断被监控在*/proc/softirqs*文件中。
       - 当keyword是 *SUM*时，mpstat将输出每个处理器的中断数量总和，以下的参数将会显示：
              - *CPU* 处理器数量，指定所有处理器计算的统计信息。
              - *intr/s* 显示CPU每秒接收的中中断数。
       - 当keyword是 *ALL*时，相当于指定了上面的所有参数，显示处理器的所有中断统计信息。
- **-N { node_list | ALL }** 输出指定NUMA节点的统计信息。
       - node_list是一个逗号分割值或值范围的列表，例如（0,2,4-7,12-），all节点是全局所有节点的平均值。
       - *ALL*表示输出所有NUMA节点的统计信息。
- **-n** 输出基于NUMA节点的CPU统计信息。以下的值将会显示：
       - *NODE* 节点的编号，统计所有节点的平均值。 
       - 其他所有显示的字段和 **-u**参数显示的字段一样。
- **-o JSON** 以JSON的形式展示统计信息，JSON输出字段排序未定义，未来将会有信息的字段添加。
- **-P { cpu_list | ON | ALL }** 输出指定处理器的统计报告。
       - cpu_list是一个逗号分割值或值范围的列表，例如（0,2,4-7,12-），注意CPU 0 是第一个处理器，CPU all是所有处理器的平均值。
       - *ON* 表示每一个在线的CPU都会显示。
       - *ALL* 表示输出所有处理器的统计信息。
- **-u** 输出CPU的使用情况。以下字段会被显示：
       - *CPU* 处理器的编号，值为‘all’时表示所有处理器的平均值。
       - *%usr* 显示用户级别执行时利用CPU利用率的百分比
       - *%nice* 显示在具有良好优先级的用户级别执行时发生的CPU利用率百分比。
       - *%sys* 显示内核级别执行时使用CPU利用率的百分比，注意这个不包含硬件中断和软件中断。
       - *%iowait* 显示系统未完成的磁盘I / O请求的CPU或CPU空闲的时间百分比。
       - *%irq* 显示CPU服务硬中断的时间的百分比。
       - *%soft* 显示CPU服务软中断的时间的百分比。
       - *%steal* 显示虚拟机管理程序为另一个虚拟处理器提供服务时虚拟CPU或CPU在非自愿等待中花费的时间百分比。
       - *%guest* 显示CPU运行虚拟处理器的时间的百分比。
       - *%gnice* 显示CPU或CPU运行niced guest虚拟机所花费的时间百分比。
       - *%idle* 显示CPU处于空闲状态和没有未完成的I/O请求的时间百分比。
       - 注意：在SMP机器上，根本没有任何活动的处理器是禁用（离线）处理器。
- **-V** 打印版本信息并退出。

## 环境
mpstat命令考虑以下环境变量：
- **S_COLORS** 当该参数设置时，在终端中彩色显示统计信息，这个参数是可能的值为*never*，*always*，*auto*(默认值)。请注意，用于显示值的颜色（红色，黄色或其他颜色）并不仅仅因为颜色而表示任何类型的问题。 它仅表示不同的值范围。
- **S_COLORS_SGR** 指定用于在终端上显示统计信息的颜色和其他属性。 它的值是以冒号分隔的能力列表，默认为H=31;1:I=32;22:M=35;1:N=34;1:Z=34;22。支持如下的设置：
       - *H=* 选择图形绘制大于或等于75％百分比值子字符串。
       - *I=* 选择图形绘制CPU编号子字符串。
       - *M=* 选择图形绘制50%～75%的百分比值子字符串。
       - *N=* 选择图形绘制不为0的统计值。
       - *Z=* 选择图形绘制为0的值。
- **S_TIME_FORMAT** 如果此变量存在且其值为ISO，则在报表标题中打印日期时将忽略当前区域设置。 mpstat命令将使用ISO 8601格式（YYYY-MM-DD）代替。 时间戳也符合ISO 8601格式。

## 示例
- **mpstat 2 5** 显示5次所有处理器间隔2s的全部统计信息。
- **mpstat -P ALL 2 5** 显示5次所有处理器间隔2s的统计信息。