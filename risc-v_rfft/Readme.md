RISC_V RFFT计算：

如何使用：

1、包含头文件`user_rfft.h`，包含源文件`user_rfft.c`，在`user_rfft.c`中已经调用了所有需要使用的源文件。

2、初始化函数为：

```
riscv_rfft_fast_instance_f32 S = {0};
riscv_rfft_fast_init_f32(&S, FFT_LEN);
```

3、计算函数为：（0为FFT，1为IFFT）

```
riscv_rfft_fast_f32(&S, rfft_in, rfft_out, 0);
riscv_rfft_fast_f32(&S, rfft_out, rfft_in, 1);
```

4、计算结果呈以下结构排列：

> 0hz（实部）、fs/2（虚部）、频域（实部）、虚部、实部、虚部……

