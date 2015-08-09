#include <linux/module.h>
#include <linux/init.h>
#include <linux/timer.h>

static struct timer_list demo_timer;
static unsigned int cnt = 1;

static void timer_function(unsigned long data)
{
	printk("expired jiffies: %lu\n", jiffies);

	cnt++;
	mod_timer(&demo_timer, jiffies + cnt * HZ);
}

static int __init demo_init(void)
{
	printk("demo_init\n");

	init_timer(&demo_timer);

	demo_timer.expires = jiffies + 1 * HZ;
	demo_timer.data = 0;
	demo_timer.function = timer_function;

	printk("init jiffies: %lu\n", jiffies);
	add_timer(&demo_timer);

	return 0;
}

static void __exit demo_exit(void)
{
	printk("delete demo_timer\n");
	del_timer_sync(&demo_timer);

	printk("demo_exit\n");
}

module_init(demo_init);
module_exit(demo_exit);

MODULE_LICENSE("Dual BSD/GPL");
