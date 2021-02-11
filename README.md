# anv_bench
RT-Thread 函数性能测试软件包

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

可以看到不同函数执行 1000 次所需时间：

     \ | /
    - RT -     Thread Operating System
     / | \     4.0.3 build Feb 11 2021
     2006 - 2021 Copyright by rt-thread team
    msh />ac
    msh />a
    anv_bench_example
    msh />anv_bench_example

    ===================================================================================== n. 01
    test_func_a(&a, 2, 3)                              calls: 1000     value: 1000
    test_func_b(2, 3)                                  calls: 1000     value: 2000
    ===================================================================================== n. 02
    test_func_a(&a, 2, 3)                              calls: 1000     value: 1000
    test_func_b(2, 3)                                  calls: 1000     value: 2000
    ===================================================================================== n. 03
    test_func_a(&a, 2, 3)                              calls: 1000     value: 1000
    test_func_b(2, 3)                                  calls: 1000     value: 2000
    ===================================================================================== n. 04
    test_func_a(&a, 2, 3)                              calls: 1000     value: 1000
    test_func_b(2, 3)                                  calls: 1000     value: 2000
    ===================================================================================== n. 05
    test_func_a(&a, 2, 3)                              calls: 1000     value: 1000
    test_func_b(2, 3)                                  calls: 1000     value: 2000
    ===================================================================================== n. 06
    test_func_a(&a, 2, 3)                              calls: 1000     value: 1000
    test_func_b(2, 3)                                  calls: 1000     value: 2000
    ===================================================================================== n. 07
    test_func_a(&a, 2, 3)                              calls: 1000     value: 1000
    test_func_b(2, 3)                                  calls: 1000     value: 2000
    ===================================================================================== n. 08
    test_func_a(&a, 2, 3)                              calls: 1000     value: 1000
    test_func_b(2, 3)                                  calls: 1000     value: 2000
    ===================================================================================== n. 09
    test_func_a(&a, 2, 3)                              calls: 1000     value: 1000
    test_func_b(2, 3)                                  calls: 1000     value: 2000
    ===================================================================================== n. 10
    test_func_a(&a, 2, 3)                              calls: 1000     value: 1000
    test_func_b(2, 3)                                  calls: 1000     value: 2000
