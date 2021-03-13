#include <linux/init.h>
#include <linux/module.h>

static int hello_driver_init(void){
	printk(KERN_ALERT "Hello World!\n");
	return 0;
}

static void hello_driver_exit(void){
	printk(KERN_ALERT "Goodbye World :)");
}

module_init(hello_driver_init);
module_exit(hello_driver_exit);
