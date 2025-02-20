Для начала создаем файлы main.c, navigation.c, fuel.c и ship.h (в директории task3)
Далее компилируем файлы C с помощью команды <gcc -c "файл".c>
После создадим программу через команду <gcc -o ship main.o navigation.o fuel.o>

Доп:

nm main.o:
                 U calculate_distance
                 U check_fuel
                 U __isoc99_scanf
0000000000000000 T main
                 U printf
                 U puts
                 U __stack_chk_fail

nm fuel.o:
0000000000000000 T check_fuel

nm navigation.o:
0000000000000000 T calculate_distance

nm ship:
0000000000004030 B __bss_start
0000000000001298 T calculate_distance
00000000000012b6 T check_fuel
                 w __cxa_finalize@GLIBC_2.2.5
0000000000004020 D __data_start
0000000000004020 W data_start
0000000000004028 D __dso_handle
0000000000003de0 d _DYNAMIC
0000000000004030 D _edata
0000000000004038 B _end
00000000000012d4 T _fini
0000000000003fe8 d _GLOBAL_OFFSET_TABLE_
                 w __gmon_start__
0000000000002050 r __GNU_EH_FRAME_HDR
0000000000001000 T _init
0000000000002000 R _IO_stdin_used
                 U __isoc99_scanf@GLIBC_2.7
                 w _ITM_deregisterTMCloneTable
                 w _ITM_registerTMCloneTable
                 U __libc_start_main@GLIBC_2.34
0000000000001169 T main
                 U printf@GLIBC_2.2.5
                 U puts@GLIBC_2.2.5
                 U __stack_chk_fail@GLIBC_2.4
0000000000001070 T _start
0000000000004030 D __TMC_END__

В результате линковки к тем функциям, которые были объявлены в main, но были в других файлах, были добавлены адреса из файлов для использования их. Также были добавлены адреса из библиотек и для запуска и работы программы