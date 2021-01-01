#include "linux/module.h"

static int __init helloworld_init(void)
{
    pr_info("Hello world");
    return (0);
}

static void __exit helloworld_cleanup(void)
{
    pr_info("Hello world");
}

module_init(helloworld_init);
module_exit(helloworld_cleanup);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("ME");
MODULE_DESCRIPTION("A simp");
MODULE_INFO(board, "ihudfg");