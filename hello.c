#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/printk.h>

#include <linux/types.h>

MODULE_AUTHOR("DonSosiska <don.sosiska339@gmail.com>");
MODULE_DESCRIPTION("Helloooooooooooooo!");
MODULE_LICENSE("Dual BSD/GPL");

static uint repetitions = 1;
module_param(repetitions,uint,S_IRUGO);
MODULE_PARM_DESC(repetitions, "The amount of times to print hello world");

static int __init initter(void)
{
  uint i = 1;
  printk(KERN_INFO "Repetitions: %d\n", repetitions);
  if(repetitions == 0) {
    printk(KERN_WARNING "The parameter is 0");
  }else if(repetitions >=5 && repetitions <= 10) {
    printk(KERN_WARNING "The parameter is between 5 and 10");
  } else if(repetitions > 10) {
    printk(KERN_ERR "The parameter is greater than 10");
    return -EINVAL;
  }
  for(i = 0; i < repetitions; i++){
    printk(KERN_INFO "Hello, world!\n");
  }
  return 0;
}

static void __exit exitter(void)
{
  /* Do nothing here right now */
}

module_init(initter);
module_exit(exitter);
