#include <linux/module.h>
#include <linux/init.h>

static int __init demo_init(void)
{
	printk("demo_init\n");
	return 0;
}

static void __exit demo_exit(void)
{
	printk("demo_exit\n");
}

module_init(demo_init);
module_exit(demo_exit);

MODULE_LICENSE("Dual BSD/GPL");
