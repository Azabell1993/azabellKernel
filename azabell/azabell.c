#include <linux/kernel.h>
#include <linux/syscalls.h>

SYSCALL_DEFINE0(azabell) {
	printk("azabell kernel\n");
	return (0);
}
