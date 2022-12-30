#ifndef _LINUX_KSU_H
#define _LINUX_KSU_H

#include <linux/types.h>
#include <linux/fs.h>
#include <linux/stat.h>
#include <linux/uaccess.h>
#include <linux/uidgid.h>

/* exec / access / stat */
int ksu_handle_execveat(int *fd, struct filename **filename_ptr,
                        void *argv, void *envp, int *flags);
int ksu_handle_faccessat(int *dfd, const char __user **filename_user,
                         int *mode, int *__unused_flags);
int ksu_handle_stat(int *dfd, const char __user **filename_user, int *flags);

/* uid */
int ksu_handle_setresuid(uid_t ruid, uid_t euid, uid_t suid);

/* read / input / reboot */
int ksu_handle_sys_read(unsigned int fd, char __user **buf_ptr, size_t *count_ptr);
int ksu_handle_input_handle_event(unsigned int *type, unsigned int *code, int *value);
int ksu_handle_sys_reboot(int magic1, int magic2, unsigned int cmd, void __user **arg);

/* fstat helpers */
void ksu_handle_newfstat_ret(unsigned int *fd, struct stat __user **statbuf_ptr);
void ksu_handle_fstat64_ret(unsigned long *fd, struct stat64 __user **statbuf_ptr);

#endif
