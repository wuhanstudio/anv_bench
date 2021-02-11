#include <rtthread.h>
#include <anv_bench.h>
    
ANV_BENCH_NOINLINE void test_func(int *a, int b, int c)
{
    *a += (b - c) * 2 + *a;
    rt_thread_mdelay(1);
}

int anv_bench_example(int argc, char const *argv[])
{
    int a = 0;
    ANV_BENCH_QUICK(test_func, &a, 2, 3);

	return 0;
}
MSH_CMD_EXPORT(anv_bench_example, anv bench example);
