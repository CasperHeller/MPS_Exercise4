#include <linux/init.h>
#include <linux/module.h>
#include <linux/gpio.h>
#include <linux/ioport.h>
#include <asm/io.h>

MODULE_LICENSE("Dual BSD/GPL");

static int __init hello_init(void)
{
  printk(KERN_ALERT "hello_world loaded\n");
  
  // Pointers til OE and DOUT:
  volatile unsigned long *REG_GPIO6_OE; 
  volatile unsigned long *REG_GPIO6_DOUT;
  
  // Bede kernen om lov til at benytte memory området
  if (request_mem_region (0x49058034, 12, "hello_world") == NULL) {
	printk ("Allocation for I/O memory range failed\n");
	return 0;
    }

  // Tildele addresser til pointere (mappet til en anden end den fysiske)
  REG_GPIO6_OE = ioremap(0x49058034, 4);
  REG_GPIO6_DOUT = ioremap(0x4905803c, 4); 

  // Læs 32-bit
  unsigned long GPIO6_OE = ioread32(REG_GPIO6_OE);
  unsigned long GPIO6_DOUT = ioread32(REG_GPIO6_DOUT);
  
  // Skriv 32-bit
  iowrite32(GPIO6_OE & 0xffffffef, REG_GPIO6_OE);
  iowrite32(GPIO6_DOUT & 0xffffffef, REG_GPIO6_DOUT);

  return 0;
}

static void __exit hello_exit(void)
{
  // Pointers til OE and DOUT:
  volatile unsigned long *REG_GPIO6_OE; 
  volatile unsigned long *REG_GPIO6_DOUT;
  
  // Tildele addresser til pointere (mappet til en anden end den fysiske)
  REG_GPIO6_OE = ioremap( 0x49058034, 4);
  REG_GPIO6_DOUT = ioremap(0x4905803c, 4); 
  
  // Læs 32-bit
  unsigned long GPIO6_OE = ioread32(REG_GPIO6_OE);
  unsigned long GPIO6_DOUT = ioread32(REG_GPIO6_DOUT);
  
  // Skriv 32-bit
  iowrite32(GPIO6_OE | 1<<4, REG_GPIO6_OE);
  iowrite32(GPIO6_DOUT | 1<<4, REG_GPIO6_DOUT);
  
  // Frigør memory
  release_mem_region (0x49058034, 12);
  
  printk(KERN_ALERT "hello_world unloaded\n");
}

module_init(hello_init);
module_exit(hello_exit);

