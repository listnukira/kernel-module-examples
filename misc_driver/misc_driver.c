#include <linux/init.h>
#include <linux/module.h>
#include <linux/miscdevice.h>
#include <linux/uaccess.h>
#include <linux/fs.h>

#define MISC_ID	"misc_driver"

static ssize_t misc_read(struct file *file, char __user *buf,
			      size_t count, loff_t *ppos)
{
	count = strlen(MISC_ID);
	copy_to_user(buf, MISC_ID, count);
	return count;
}

static ssize_t misc_write(struct file *file, const char __user *buf,
			       size_t count, loff_t *ppos)
{
	if (strcmp(buf, MISC_ID) == 0)
		return count;

	return -EINVAL;
}

static const struct file_operations misc_fops = {
	.owner	= THIS_MODULE,
	.read	= misc_read,
	.write	= misc_write,
};

static struct miscdevice misc_dev = {
	.minor	= MISC_DYNAMIC_MINOR,
	.name	= "misc_driver",
	.fops	= &misc_fops,
};

static int __init misc_init(void)
{
	int err = 0;

	pr_debug("misc driver: misc driver init\n");

	err = misc_register(&misc_dev);
	if (err < 0)
		return err;
	return 0;
}

static void __exit misc_exit(void)
{
	pr_debug("misc driver: misc driver exit\n");

	misc_deregister(&misc_dev);
}
module_init(misc_init);
module_exit(misc_exit);
MODULE_LICENSE("Dual BSD/GPL");
