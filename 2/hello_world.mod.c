#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
 .name = KBUILD_MODNAME,
 .init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
 .exit = cleanup_module,
#endif
 .arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0xaa8a822b, "module_layout" },
	{ 0x9bce482f, "__release_region" },
	{ 0x2e5810c6, "__aeabi_unwind_cpp_pr1" },
	{ 0xe9ce8b95, "omap_ioremap" },
	{ 0xadf42bd5, "__request_region" },
	{ 0x788fe103, "iomem_resource" },
	{ 0x27e1a049, "printk" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "334FD6D9E56906650781C2C");