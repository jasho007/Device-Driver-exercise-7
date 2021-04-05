#include <linux/module.h>
#include <linux/kernel.h>
#include<linux/kthread.h>
#include<linux/sched.h>
#include<linux/time.h>

int method2(void) {
	int x = 3, *a;
	a = &x;
	*a = *a + 3;
	a = NULL;
	return 0;
	
}
int method1(void){
printk("in method2\n");
method2();
return 0;
}

int init_module(void){
printk("inserting kernel memory error\n");
method1();
return 0;
}

void cleanup_module(void)
{
printk(KERN_INFO "bye\n");
}
MODULE_LICENSE("GPL");
