/*
** EPITECH PROJECT, 2018
** PSU_strace_2017
** File description:
**        syscall_table.c
*/


#include "strace.h"

const system_call_t SYSCALL_NAMES[] = {
	{0, "read", 3, UNSIGNED_INT, STRING, UNSIGNED_INT, 0, 0, 0},
	{1, "write", 3, UNSIGNED_INT, STRING, UNSIGNED_INT, 0, 0, 0},
	{2, "open", 3, STRING, INT, INT, 0, 0, 0},
	{3, "close", 1, UNSIGNED_INT, 0, 0, 0, 0, 0},
	{4, "stat", 2, STRING, OTHER, 0, 0, 0, 0},
	{5, "fstat", 2, UNSIGNED_INT, OTHER, 0, 0, 0, 0},
	{6, "lstat", 2, STRING, OTHER, 0, 0, 0, 0},
	{7, "poll", 3, OTHER, UNSIGNED_INT, OTHER, 0, 0, 0},
	{8, "lseek", 3, UNSIGNED_INT, OTHER, UNSIGNED_INT, 0, 0, 0},
	{9, "mmap", 6, OTHER, OTHER, OTHER, OTHER, OTHER, OTHER},
	{10, "mprotect", 3, OTHER, UNSIGNED_INT, OTHER, 0, 0, 0},
	{11, "munmap", 2, OTHER, UNSIGNED_INT, 0, 0, 0, 0},
	{12, "brk", 1, OTHER, 0, 0, 0, 0, 0},
	{13, "rt_sigaction", 4, INT, OTHER, OTHER, UNSIGNED_INT, 0, 0},
	{14, "rt_sigprocmask", 4, INT, OTHER, OTHER, UNSIGNED_INT, 0, 0},
	{15, "rt_sigreturn", 1, OTHER, 0, 0, 0, 0, 0},
	{16, "ioctl", 3, UNSIGNED_INT, UNSIGNED_INT, OTHER, 0, 0, 0},
	{17, "pread64", 4, OTHER, STRING, UNSIGNED_INT, OTHER, 0, 0},
	{18, "pwrite64", 4, UNSIGNED_INT, STRING, UNSIGNED_INT, OTHER, 0, 0},
	{19, "readv", 3, OTHER, OTHER, OTHER, 0, 0, 0},
	{20, "writev", 3, OTHER, OTHER, OTHER, 0, 0, 0},
	{21, "access", 2, STRING, INT, 0, 0, 0, 0},
	{22, "pipe", 1, INT, 0, 0, 0, 0, 0},
	{23, "select", 5, INT, OTHER, OTHER, OTHER, OTHER, 0},
	{24, "sched_yield", 0, 0, 0, 0, 0, 0, 0},
	{25, "mremap", 5, OTHER, OTHER, OTHER, OTHER, OTHER, 0},
	{26, "msync", 3, OTHER, UNSIGNED_INT, INT, 0, 0, 0},
	{27, "mincore", 3, OTHER, UNSIGNED_INT, STRING, 0, 0, 0},
	{28, "madvise", 3, OTHER, UNSIGNED_INT, INT, 0, 0, 0},
	{29, "shmget", 3, OTHER, UNSIGNED_INT, INT, 0, 0, 0},
	{30, "shmat", 3, INT, STRING, INT, 0, 0, 0},
	{31, "shmctl", 3, INT, INT, OTHER, 0, 0, 0},
	{32, "dup", 1, UNSIGNED_INT, 0, 0, 0, 0, 0},
	{33, "dup2", 2, UNSIGNED_INT, UNSIGNED_INT, 0, 0, 0, 0},
	{34, "pause", 0, 0, 0, 0, 0, 0, 0},
	{35, "nanosleep", 2, OTHER, OTHER, 0, 0, 0, 0},
	{36, "getitimer", 2, INT, OTHER, 0, 0, 0, 0},
	{37, "alarm", 1, UNSIGNED_INT, 0, 0, 0, 0, 0},
	{38, "setitimer", 3, INT, OTHER, OTHER, 0, 0, 0},
	{39, "getpid", 0, 0, 0, 0, 0, 0, 0},
	{40, "sendfile", 4, INT, INT, OTHER, UNSIGNED_INT, 0, 0},
	{41, "socket", 3, INT, INT, INT, 0, 0, 0},
	{42, "connect", 3, INT, OTHER, INT, 0, 0, 0},
	{43, "accept", 3, INT, OTHER, INT, 0, 0, 0},
	{44, "sendto", 6, INT, OTHER, UNSIGNED_INT, OTHER, OTHER, INT},
	{45, "recvfrom", 6, INT, OTHER, UNSIGNED_INT, OTHER, OTHER, INT},
	{46, "sendmsg", 3, INT, OTHER, OTHER, 0, 0, 0},
	{47, "recvmsg", 3, INT, OTHER, UNSIGNED_INT, 0, 0, 0},
	{48, "shutdown", 2, INT, INT, 0, 0, 0, 0},
	{49, "bind", 3, INT, OTHER, INT, 0, 0, 0},
	{50, "listen", 2, INT, INT, 0, 0, 0, 0},
	{51, "getsockname", 3, INT, OTHER, INT, 0, 0, 0},
	{52, "getpeername", 3, INT, OTHER, INT, 0, 0, 0},
	{53, "socketpair", 4, INT, INT, INT, INT, 0, 0},
	{54, "setsockopt", 5, INT, INT, INT, STRING, INT, 0},
	{55, "getsockopt", 5, INT, INT, INT, STRING, INT, 0},
	{56, "clone", 4, OTHER, OTHER, OTHER, OTHER, 0, 0},
	{57, "fork", 0, 0, 0, 0, 0, 0, 0},
	{58, "vfork", 0, 0, 0, 0, 0, 0, 0},
	{59, "execve", 3, STRING, STRING, STRING, 0, 0, 0},
	{60, "exit", 1, INT, 0, 0, 0, 0, 0},
	{61, "wait4", 4, INT, INT, INT, OTHER, 0, 0},
	{62, "kill", 2, INT, INT, 0, 0, 0, 0},
	{63, "uname", 1, OTHER, 0, 0, 0, 0, 0},
	{64, "semget", 3, OTHER, INT, INT, 0, 0, 0},
	{65, "semop", 3, INT, OTHER, OTHER, 0, 0, 0},
	{66, "semctl", 4, INT, INT, INT, OTHER, 0, 0},
	{67, "shmdt", 1, STRING, 0, 0, 0, 0, 0},
	{68, "msgget", 2, OTHER, INT, 0, 0, 0, 0},
	{69, "msgsnd", 4, INT, OTHER, UNSIGNED_INT, INT, 0, 0},
	{70, "msgrcv", 5, INT, OTHER, UNSIGNED_INT, OTHER, INT, 0},
	{71, "msgctl", 3, INT, INT, OTHER, 0, 0, 0},
	{72, "fcntl", 3, UNSIGNED_INT, UNSIGNED_INT, OTHER, 0, 0, 0},
	{73, "flock", 2, UNSIGNED_INT, UNSIGNED_INT, 0, 0, 0, 0},
	{74, "fsync", 1, UNSIGNED_INT, 0, 0, 0, 0, 0},
	{75, "fdatasync", 1, UNSIGNED_INT, 0, 0, 0, 0, 0},
	{76, "truncate", 2, STRING, OTHER, 0, 0, 0, 0},
	{77, "ftruncate", 2, UNSIGNED_INT, OTHER, 0, 0, 0, 0},
	{78, "getdents", 3, UNSIGNED_INT, OTHER, UNSIGNED_INT, 0, 0, 0},
	{79, "getcwd", 2, STRING, OTHER, 0, 0, 0, 0},
	{80, "chdir", 1, STRING, 0, 0, 0, 0, 0},
	{81, "fchdir", 1, UNSIGNED_INT, 0, 0, 0, 0, 0},
	{82, "rename", 2, STRING, STRING, 0, 0, 0, 0},
	{83, "mkdir", 2, STRING, INT, 0, 0, 0, 0},
	{84, "rmdir", 1, STRING, 0, 0, 0, 0, 0},
	{85, "creat", 2, STRING, INT, 0, 0, 0, 0},
	{86, "link", 2, STRING, STRING, 0, 0, 0, 0},
	{87, "unlink", 1, STRING, 0, 0, 0, 0, 0},
	{88, "symlink", 2, STRING, STRING, 0, 0, 0, 0},
	{89, "readlink", 3, STRING, STRING, INT, 0, 0, 0},
	{90, "chmod", 2, STRING, OTHER, 0, 0, 0, 0},
	{91, "fchmod", 2, UNSIGNED_INT, OTHER, 0, 0, 0, 0},
	{92, "chown", 3, STRING, OTHER, OTHER, 0, 0, 0},
	{93, "fchown", 3, UNSIGNED_INT, OTHER, OTHER, 0, 0, 0},
	{94, "lchown", 3, STRING, OTHER, OTHER, 0, 0, 0},
	{95, "umask", 1, INT, 0, 0, 0, 0, 0},
	{96, "gettimeofday", 2, OTHER, OTHER, 0, 0, 0, 0},
	{97, "getrlimit", 2, UNSIGNED_INT, OTHER, 0, 0, 0, 0},
	{98, "getrusage", 2, INT, OTHER, 0, 0, 0, 0},
	{99, "sysinfo", 1, OTHER, 0, 0, 0, 0, 0},
	{100, "times", 1, OTHER, 0, 0, 0, 0, 0},
	{101, "ptrace", 4, OTHER, OTHER, OTHER, OTHER, 0, 0},
	{102, "getuid", 0, 0, 0, 0, 0, 0, 0},
	{103, "syslog", 3, INT, STRING, INT, 0, 0, 0},
	{104, "getgid", 0, 0, 0, 0, 0, 0, 0},
	{105, "setuid", 1, OTHER, 0, 0, 0, 0, 0},
	{106, "setgid", 1, OTHER, 0, 0, 0, 0, 0},
	{107, "geteuid", 0, 0, 0, 0, 0, 0, 0},
	{108, "getegid", 0, 0, 0, 0, 0, 0, 0},
	{109, "setpgid", 2, INT, INT, 0, 0, 0, 0},
	{110, "getppid", 0, 0, 0, 0, 0, 0, 0},
	{111, "getpgrp", 0, 0, 0, 0, 0, 0, 0},
	{112, "setsid", 0, 0, 0, 0, 0, 0, 0},
	{113, "setreuid", 2, OTHER, OTHER, 0, 0, 0, 0},
	{114, "setregid", 2, OTHER, OTHER, 0, 0, 0, 0},
	{115, "getgroups", 2, INT, OTHER, 0, 0, 0, 0},
	{116, "setgroups", 2, INT, OTHER, 0, 0, 0, 0},
	{117, "setresuid", 3, OTHER, OTHER, OTHER, 0, 0, 0},
	{118, "getresuid", 3, OTHER, OTHER, OTHER, 0, 0, 0},
	{119, "setresgid", 3, OTHER, OTHER, OTHER, 0, 0, 0},
	{120, "getresgid", 3, OTHER, OTHER, OTHER, 0, 0, 0},
	{121, "getpgid", 1, INT, 0, 0, 0, 0, 0},
	{122, "setfsuid", 1, OTHER, 0, 0, 0, 0, 0},
	{123, "setfsgid", 1, OTHER, 0, 0, 0, 0, 0},
	{124, "getsid", 1, INT, 0, 0, 0, 0, 0},
	{125, "capget", 2, OTHER, OTHER, 0, 0, 0, 0},
	{126, "capset", 2, OTHER, OTHER, 0, 0, 0, 0},
	{127, "rt_sigpending", 2, OTHER, UNSIGNED_INT, 0, 0, 0, 0},
	{128, "rt_sigtimedwait", 4, OTHER, OTHER, OTHER, UNSIGNED_INT, 0, 0},
	{129, "rt_sigqueueinfo", 3, INT, INT, OTHER, 0, 0, 0},
	{130, "rt_sigsuspend", 2, OTHER, UNSIGNED_INT, 0, 0, 0, 0},
	{131, "sigaltstack", 2, OTHER, OTHER, 0, 0, 0, 0},
	{132, "utime", 2, STRING, OTHER, 0, 0, 0, 0},
	{133, "mknod", 3, STRING, OTHER, OTHER, 0, 0, 0},
	{134, "uselib", 1, OTHER, 0, 0, 0, 0, 0},
	{135, "personality", 1, UNSIGNED_INT, 0, 0, 0, 0, 0},
	{136, "ustat", 2, OTHER, OTHER, 0, 0, 0, 0},
	{137, "statfs", 2, STRING, OTHER, 0, 0, 0, 0},
	{138, "fstatfs", 2, UNSIGNED_INT, OTHER, 0, 0, 0, 0},
	{139, "sysfs", 3, INT, OTHER, OTHER, 0, 0, 0},
	{140, "getpriority", 2, INT, INT, 0, 0, 0, 0},
	{141, "setpriority", 3, INT, INT, INT, 0, 0, 0},
	{142, "sched_setparam", 2, INT, OTHER, 0, 0, 0, 0},
	{143, "sched_getparam", 2, INT, OTHER, 0, 0, 0, 0},
	{144, "sched_setscheduler", 3, INT, INT, OTHER, 0, 0, 0},
	{145, "sched_getscheduler", 1, INT, 0, 0, 0, 0, 0},
	{146, "sched_get_priority_max", 1, INT, 0, 0, 0, 0, 0},
	{147, "sched_get_priority_min", 1, INT, 0, 0, 0, 0, 0},
	{148, "sched_rr_get_interval", 2, INT, INT, 0, 0, 0, 0},
	{149, "mlock", 2, OTHER, UNSIGNED_INT, 0, 0, 0, 0},
	{150, "munlock", 2, OTHER, UNSIGNED_INT, 0, 0, 0, 0},
	{151, "mlockall", 1, INT, 0, 0, 0, 0, 0},
	{152, "munlockall", 0, 0, 0, 0, 0, 0, 0},
	{153, "vhangup", 0, 0, 0, 0, 0, 0, 0},
	{154, "modify_ldt", 3, INT, OTHER, OTHER, 0, 0, 0},
	{155, "pivot_root", 2, STRING, STRING, 0, 0, 0, 0},
	{156, "_sysctl", 1, OTHER, 0, 0, 0, 0, 0},
	{157, "prctl", 5, INT, OTHER, OTHER, OTHER, 0, OTHER},
	{158, "arch_prctl", 3, OTHER, INT, OTHER, 0, 0, 0},
	{159, "adjtimex", 1, OTHER, 0, 0, 0, 0, 0},
	{160, "setrlimit", 2, UNSIGNED_INT, OTHER, 0, 0, 0, 0},
	{161, "chroot", 1, STRING, 0, 0, 0, 0, 0},
	{162, "sync", 0, 0, 0, 0, 0, 0, 0},
	{163, "acct", 1, STRING, 0, 0, 0, 0, 0},
	{164, "settimeofday", 2, OTHER, OTHER, 0, 0, 0, 0},
	{165, "mount", 5, STRING, STRING, STRING, OTHER, OTHER, 0},
	{166, "umount2", 2, STRING, INT, 0, 0, 0, 0},
	{167, "swapon", 2, STRING, INT, 0, 0, 0, 0},
	{168, "swapoff", 1, STRING, 0, 0, 0, 0, 0},
	{169, "reboot", 4, INT, INT, UNSIGNED_INT, OTHER, 0, 0},
	{170, "sethostname", 2, STRING, INT, 0, 0, 0, 0},
	{171, "setdomainname", 2, STRING, INT, 0, 0, 0, 0},
	{172, "iopl", 2, UNSIGNED_INT, OTHER, 0, 0, 0, 0},
	{173, "ioperm", 3, OTHER, OTHER, INT, 0, 0, 0},
	{174, "create_module", 1, OTHER, 0, 0, 0, 0, 0},
	{175, "init_module", 3, OTHER, OTHER, STRING, 0, 0, 0},
	{176, "delete_module", 2, OTHER, UNSIGNED_INT, 0, 0, 0, 0},
	{177, "get_kernel_syms", 1, OTHER, 0, 0, 0, 0, 0},
	{178, "query_module", 1, OTHER, 0, 0, 0, 0, 0},
	{179, "quotactl", 4, UNSIGNED_INT, STRING, OTHER, OTHER, 0, 0},
	{180, "nfsservctl", 1, OTHER, 0, 0, 0, 0, 0},
	{181, "getpmsg", 1, OTHER, 0, 0, 0, 0, 0},
	{182, "putpmsg", 1, OTHER, 0, 0, 0, 0, 0},
	{183, "afs_syscall", 1, OTHER, 0, 0, 0, 0, 0},
	{184, "tuxcall", 1, OTHER, 0, 0, 0, 0, 0},
	{185, "security", 1, OTHER, 0, 0, 0, 0, 0},
	{186, "gettid", 0, 0, 0, 0, 0, 0, 0},
	{187, "readahead", 3, INT, OTHER, UNSIGNED_INT, 0, 0, 0},
	{188, "setxattr", 5, STRING, STRING, OTHER, UNSIGNED_INT, INT, 0},
	{189, "lsetxattr", 5, STRING, STRING, OTHER, UNSIGNED_INT, INT, 0},
	{190, "fsetxattr", 5, INT, STRING, OTHER, UNSIGNED_INT, INT, 0},
	{191, "getxattr", 4, STRING, STRING, OTHER, UNSIGNED_INT, 0, 0},
	{192, "lgetxattr", 4, STRING, STRING, OTHER, UNSIGNED_INT, 0, 0},
	{193, "fgetxattr", 4, INT, OTHER, OTHER, UNSIGNED_INT, 0, 0},
	{194, "listxattr", 3, STRING, STRING, UNSIGNED_INT, 0, 0, 0},
	{195, "llistxattr", 3, STRING, STRING, UNSIGNED_INT, 0, 0, 0},
	{196, "flistxattr", 3, INT, STRING, UNSIGNED_INT, 0, 0, 0},
	{197, "removexattr", 2, STRING, STRING, 0, 0, 0, 0},
	{198, "lremovexattr", 2, STRING, STRING, 0, 0, 0, 0},
	{199, "fremovexattr", 2, INT, STRING, 0, 0, 0, 0},
	{200, "tkill", 2, INT, OTHER, 0, 0, 0, 0},
	{201, "time", 1, OTHER, 0, 0, 0, 0, 0},
	{202, "futex", 6, OTHER, INT, OTHER, OTHER, OTHER, OTHER},
	{203, "sched_setaffinity", 3, INT, UNSIGNED_INT, OTHER, 0, 0, 0},
	{204, "sched_getaffinity", 3, INT, UNSIGNED_INT, OTHER, 0, 0, 0},
	{205, "set_thread_area", 1, OTHER, 0, 0, 0, 0, 0},
	{206, "io_setup", 2, OTHER, OTHER, 0, 0, 0, 0},
	{207, "io_destroy", 1, OTHER, 0, 0, 0, 0, 0},
	{208, "io_getevents", 4, OTHER, OTHER, OTHER, OTHER, 0, 0},
	{209, "io_submit", 3, OTHER, OTHER, OTHER, 0, 0, 0},
	{210, "io_cancel", 3, OTHER, OTHER, OTHER, 0, 0, 0},
	{211, "get_thread_area", 1, OTHER, 0, 0, 0, 0, 0},
	{212, "lookup_dcookie", 3, OTHER, OTHER, OTHER, 0, 0, 0},
	{213, "epoll_create", 1, INT, 0, 0, 0, 0, 0},
	{214, "epoll_ctl_old", 1, OTHER, 0, 0, 0, 0, 0},
	{215, "epoll_wait_old", 1, OTHER, 0, 0, 0, 0, 0},
	{216, "remap_file_pages", 5, OTHER, OTHER, OTHER, OTHER, OTHER, 0},
	{217, "getdents64", 3, UNSIGNED_INT, OTHER, UNSIGNED_INT, 0, 0, 0},
	{218, "set_tid_address", 1, INT, 0, 0, 0, 0, 0},
	{219, "restart_syscall", 0, 0, 0, 0, 0, 0, 0},
	{220, "semtimedop", 4, INT, OTHER, OTHER, OTHER, 0, 0},
	{221, "fadvise64", 4, INT, OTHER, UNSIGNED_INT, INT, 0, 0},
	{222, "timer_create", 3, OTHER, OTHER, OTHER, 0, 0, 0},
	{223, "timer_settime", 4, OTHER, INT, OTHER, OTHER, 0, 0},
	{224, "timer_gettime", 2, OTHER, OTHER, 0, 0, 0, 0},
	{225, "timer_getoverrun", 1, OTHER, 0, 0, 0, 0, 0},
	{226, "timer_delete", 1, OTHER, 0, 0, 0, 0, 0},
	{227, "clock_settime", 2, OTHER, OTHER, 0, 0, 0, 0},
	{228, "clock_gettime", 2, OTHER, OTHER, 0, 0, 0, 0},
	{229, "clock_getres", 2, OTHER, OTHER, 0, 0, 0, 0},
	{230, "clock_nanosleep", 4, OTHER, INT, OTHER, OTHER, 0, 0},
	{231, "exit_group", 1, INT, 0, 0, 0, 0, 0},
	{232, "epoll_wait", 4, INT, OTHER, INT, INT, 0, 0},
	{233, "epoll_ctl", 4, INT, INT, INT, OTHER, 0, 0},
	{234, "tgkill", 3, INT, INT, INT, 0, 0, 0},
	{235, "utimes", 2, STRING, OTHER, 0, 0, 0, 0},
	{236, "vserver", 1, OTHER, 0, 0, 0, 0, 0},
	{237, "mbind", 6, OTHER, OTHER, OTHER, OTHER, OTHER, OTHER},
	{238, "set_mempolicy", 3, INT, OTHER, OTHER, 0, 0, 0},
	{239, "get_mempolicy", 5, INT, OTHER, OTHER, OTHER, OTHER, 0},
	{240, "mq_open", 4, STRING, INT, OTHER, OTHER, 0, 0},
	{241, "mq_unlink", 1, STRING, 0, 0, 0, 0, 0},
	{242, "mq_timedsend", 5, OTHER, STRING, UNSIGNED_INT,
	UNSIGNED_INT, OTHER, 0},
	{243, "mq_timedreceive", 5, OTHER, STRING, UNSIGNED_INT,
	UNSIGNED_INT, OTHER, 0},
	{244, "mq_notify", 2, OTHER, OTHER, 0, 0, 0, 0},
	{245, "mq_getsetattr", 3, OTHER, OTHER, OTHER, 0, 0, 0},
	{246, "kexec_load", 4, OTHER, OTHER, OTHER, OTHER, 0, 0},
	{247, "waitid", 5, INT, INT, OTHER, INT, OTHER, 0},
	{248, "add_key", 4, STRING, STRING, OTHER, UNSIGNED_INT, 0, 0},
	{249, "request_key", 4, STRING, STRING, STRING, OTHER, 0, 0},
	{250, "keyctl", 5, INT, OTHER, OTHER, OTHER, OTHER, 0},
	{251, "ioprio_set", 3, INT, INT, INT, 0, 0, 0},
	{252, "ioprio_get", 2, INT, INT, 0, 0, 0, 0},
	{253, "inotify_init", 0, 0, 0, 0, 0, 0, 0},
	{254, "inotify_add_watch", 3, INT, STRING, OTHER, 0, 0, 0},
	{255, "inotify_rm_watch", 2, INT, OTHER, 0, 0, 0, 0},
	{256, "migrate_pages", 4, INT, OTHER, OTHER, OTHER, 0, 0},
	{257, "openat", 4, INT, STRING, INT, INT, 0, 0},
	{258, "mkdirat", 3, INT, STRING, INT, 0, 0, 0},
	{259, "mknodat", 4, INT, STRING, INT, OTHER, 0, 0},
	{260, "fchownat", 5, INT, STRING, OTHER, OTHER, INT, 0},
	{261, "futimesat", 3, INT, STRING, OTHER, 0, 0, 0},
	{262, "newfstatat", 4, INT, STRING, OTHER, INT, 0, 0},
	{263, "unlinkat", 3, INT, STRING, INT, 0, 0, 0},
	{264, "renameat", 4, INT, STRING, INT, STRING, 0, 0},
	{265, "linkat", 5, INT, STRING, INT, STRING, INT, 0},
	{266, "symlinkat", 3, STRING, INT, STRING, 0, 0, 0},
	{267, "readlinkat", 4, INT, STRING, STRING, INT, 0, 0},
	{268, "fchmodat", 3, INT, STRING, OTHER, 0, 0, 0},
	{269, "faccessat", 3, INT, STRING, INT, 0, 0, 0},
	{270, "pselect6", 6, INT, OTHER, OTHER, OTHER, OTHER, OTHER},
	{271, "ppoll", 5, OTHER, UNSIGNED_INT, OTHER, OTHER, UNSIGNED_INT, 0},
	{272, "unshare", 1, OTHER, 0, 0, 0, 0, 0},
	{273, "set_robust_list", 2, OTHER, UNSIGNED_INT, 0, 0, 0, 0},
	{274, "get_robust_list", 3, INT, OTHER, UNSIGNED_INT, 0, 0, 0},
	{275, "splice", 6, INT, OTHER, INT, OTHER, UNSIGNED_INT, UNSIGNED_INT},
	{276, "tee", 4, INT, INT, UNSIGNED_INT, UNSIGNED_INT, 0, 0},
	{277, "sync_file_range", 4, OTHER, OTHER, OTHER, OTHER, 0, 0},
	{278, "vmsplice", 4, INT, OTHER, OTHER, UNSIGNED_INT, 0, 0},
	{279, "move_pages", 6, INT, OTHER, OTHER, INT, INT, INT},
	{280, "utimensat", 4, INT, STRING, OTHER, INT, 0, 0},
	{281, "epoll_pwait", 6, INT, OTHER, INT, INT, OTHER, UNSIGNED_INT},
	{282, "signalfd", 3, INT, OTHER, UNSIGNED_INT, 0, 0, 0},
	{283, "timerfd_create", 2, INT, INT, 0, 0, 0, 0},
	{284, "eventfd", 1, UNSIGNED_INT, 0, 0, 0, 0, 0},
	{285, "fallocate", 4, OTHER, OTHER, OTHER, OTHER, 0, 0},
	{286, "timerfd_settime", 4, INT, INT, OTHER, OTHER, 0, 0},
	{287, "timerfd_gettime", 2, INT, OTHER, 0, 0, 0, 0},
	{288, "accept4", 4, INT, OTHER, INT, INT, 0, 0},
	{289, "signalfd4", 4, INT, OTHER, UNSIGNED_INT, INT, 0, 0},
	{290, "eventfd2", 2, UNSIGNED_INT, INT, 0, 0, 0, 0},
	{291, "epoll_create1", 1, INT, 0, 0, 0, 0, 0},
	{292, "dup3", 3, UNSIGNED_INT, UNSIGNED_INT, INT, 0, 0, 0},
	{293, "pipe2", 2, INT, INT, 0, 0, 0, 0},
	{294, "inotify_init1", 1, INT, 0, 0, 0, 0, 0},
	{295, "preadv", 5, OTHER, OTHER, OTHER, OTHER, OTHER, 0},
	{296, "pwritev", 5, OTHER, OTHER, OTHER, OTHER, OTHER, 0},
	{297, "rt_tgsigqueueinfo", 4, INT, INT, INT, OTHER, 0, 0},
	{298, "perf_event_open", 5, OTHER, INT, INT, INT, OTHER, 0},
	{299, "recvmmsg", 5, INT, OTHER, UNSIGNED_INT, UNSIGNED_INT, OTHER, 0},
	{300, "fanotify_init", 2, UNSIGNED_INT, UNSIGNED_INT, 0, 0, 0, 0},
	{301, "fanotify_mark", 5, OTHER, OTHER, OTHER, OTHER, OTHER, 0},
	{302, "prlimit64", 4, INT, UNSIGNED_INT, OTHER, OTHER, 0, 0},
	{303, "name_to_handle_at", 5, INT, STRING, OTHER, INT, INT, 0},
	{304, "open_by_handle_at", 5, INT, STRING, OTHER, INT, INT, 0},
	{305, "clock_adjtime", 2, OTHER, OTHER, 0, 0, 0, 0},
	{306, "syncfs", 1, INT, 0, 0, 0, 0, 0},
	{307, "sendmmsg", 4, INT, OTHER, UNSIGNED_INT, UNSIGNED_INT, 0, 0},
	{308, "setns", 2, INT, INT, 0, 0, 0, 0},
	{309, "getcpu", 3, OTHER, OTHER, OTHER, 0, 0, 0},
	{310, "process_vm_readv", 6, INT, OTHER, OTHER, OTHER, OTHER, OTHER},
	{311, "process_vm_writev", 6, INT, OTHER, OTHER, OTHER, OTHER, OTHER},
	{312, "kcmp", 5, INT, INT, INT, OTHER, OTHER, 0},
	{313, "finit_module", 3, INT, CHAR, INT, 0, 0, 0},
	{314, "sched_setattr", 3, INT, OTHER, UNSIGNED_INT, 0, 0, 0},
	{315, "sched_getattr", 4, INT, OTHER, UNSIGNED_INT, UNSIGNED_INT, 0, 0},
	{316, "renameat2", 5, INT, CHAR, INT, CHAR, UNSIGNED_INT, 0},
	{317, "seccomp", 3, UNSIGNED_INT, UNSIGNED_INT, CHAR, 0, 0, 0},
	{318, "getrandom", 3, CHAR, UNSIGNED_INT, UNSIGNED_INT, 0, 0, 0},
	{319, "memfd_create", 2, CHAR, INT, 0, 0, 0, 0},
	{320, "kexec_file_load", 5, INT, INT, OTHER, CHAR, OTHER, 0},
	{321, "bpf", 3, INT, OTHER, UNSIGNED_INT, 0, 0, 0},
	{322, "stub_execveat", 5, INT, CHAR, CHAR, CHAR, INT, 0},
	{323, "userfaultfd", 1, INT, 0, 0, 0, 0, 0},
	{324, "membarrier", 2, INT, INT, 0, 0, 0, 0},
	{325, "mlock2", 3, OTHER, UNSIGNED_INT, INT, 0, 0, 0},
	{326, "copy_file_range", 6, INT, OTHER, INT, OTHER, UNSIGNED_INT,
	UNSIGNED_INT},
	{327, "preadv2", 6, OTHER, OTHER, OTHER, OTHER, OTHER, INT},
	{328, "pwritev2", 6, OTHER, OTHER, OTHER, OTHER, OTHER, INT}
};
