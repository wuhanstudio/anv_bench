#include <rtthread.h>
#include <anv_bench.h>

ANV_BENCH_NOINLINE void test_func_a(int *a, int b, int c)
{
    *a += (b - c) * 2 + *a;
    rt_thread_mdelay(1);
}

ANV_BENCH_NOINLINE int test_func_b(int b, int c)
{
    rt_thread_mdelay(2);
    return (b + c) / 2;
}

int anv_bench_group_example(int argc, char const *argv[])
{
    int a = 0;
    rt_kprintf("\n");
    ANV_BENCH_BEGIN(stdout, 10, 1000);
        ANV_BENCH_ADD(test_func_a, &a, 2, 3);
        ANV_BENCH_ADD(test_func_b, 2, 3);
    ANV_BENCH_END();
	return 0;
}
MSH_CMD_EXPORT(anv_bench_group_example, anv bench group example);
