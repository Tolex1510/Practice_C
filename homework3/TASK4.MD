nm file1.o/file2.o/main.o

С помощью команды можно nm можно посмотреть таблицу имен файла.
В данном случае видны имена global_var, printf, print_from_file (функция) и static_var.
Так как мы объявляем переменные global_var и static_var в file1, их видно в таблице, в других файлах адреса необъявленных переменных не указаны, так как они будут браться из этого файла и в ходе линковки будут подставлены из него.

Ошибки линковки из-за объявления global_var в двух файлах, а также из-за попытки взять static_var, но из .text нельзя взять

После исправления ошибки static_var пропал из таблицы имен file2.o

objdump -t file1.o - .data и .text хранятся в нулях, .data static_var и global_var - 04, .text print_from_file1 - 3f
objdump -t file2.o - .text в нулях, .text print_from_file2 - 0023. остальное undefined
objdump -t main.o - .text в нулях, .text main - 3b, остальное undefined

strings program - видно команду printf в строке "printf" и "printf@GLIBC_2.2.5"

objdump -x program выводит полную таблицу всех имен программы, их адреса и какой тип контента (text, data, rodata, dynamic etc)

после статической компиляции все содержимое библиотек появилось в программе, поэтому таблица становится забитой различными ссылками на объекты из библиотек.

nm program:
0000000000004020 B __bss_start - начало работы
                 w __cxa_finalize@GLIBC_2.2.5
0000000000004008 D __data_start
0000000000004008 W data_start
0000000000004010 D __dso_handle
0000000000003de0 d _DYNAMIC
0000000000004020 D _edata
0000000000004028 B _end
00000000000011d8 T _fini
0000000000003fe8 d _GLOBAL_OFFSET_TABLE_
0000000000004018 D global_var
                 w __gmon_start__
0000000000002074 r __GNU_EH_FRAME_HDR
0000000000001000 T _init
0000000000002000 R _IO_stdin_used
                 w _ITM_deregisterTMCloneTable
                 w _ITM_registerTMCloneTable
                 U __libc_start_main@GLIBC_2.34
000000000000119b T main
                 U printf@GLIBC_2.2.5
0000000000001139 T print_from_file1
0000000000001178 T print_from_file2
0000000000001040 T _start
000000000000401c d static_var
0000000000004020 D __TMC_END__

objdump -t program

SYMBOL TABLE:
0000000000000000 l    df *ABS*  0000000000000000              file1.c
000000000000401c l     O#.data  0000000000000004              static_var
0000000000000000 l    df *ABS*  0000000000000000              file2.c
0000000000000000 l    df *ABS*  0000000000000000              main.c
0000000000000000 l    df *ABS*  0000000000000000              
0000000000003de0 l     O .dynamic       0000000000000000              _DYNAMIC
0000000000002074 l       .eh_frame_hdr  0000000000000000              __GNU_EH_FRAME_HDR
0000000000003fe8 l     O .got.plt       0000000000000000              _GLOBAL_OFFSET_TABLE_
0000000000000000       F *UND*  0000000000000000              __libc_start_main@GLIBC_2.34
0000000000000000  w      *UND*  0000000000000000              _ITM_deregisterTMCloneTable
0000000000004008  w     #.data  0000000000000000              data_start
0000000000001178 g     F#.text  0000000000000023              print_from_file2
0000000000004020 g      #.data  0000000000000000              _edata
00000000000011d8 g     F .fini  0000000000000000              .hidden _fini
0000000000000000       F *UND*  0000000000000000              printf@GLIBC_2.2.5
0000000000004018 g     O#.data  0000000000000004              global_var
0000000000004008 g      #.data  0000000000000000              __data_start
0000000000000000  w      *UND*  0000000000000000              __gmon_start__
0000000000004010 g     O#.data  0000000000000000              .hidden __dso_handle
0000000000002000 g     O#.rodata        0000000000000004              _IO_stdin_used
0000000000004028 g      #.bss   0000000000000000              _end
0000000000001040 g     F#.text  0000000000000026              _start
0000000000001139 g     F#.text  000000000000003f              print_from_file1
0000000000004020 g      #.bss   0000000000000000              __bss_start
000000000000119b g     F#.text  000000000000003b              main
0000000000004020 g     O#.data  0000000000000000              .hidden __TMC_END__
0000000000000000  w      *UND*  0000000000000000              _ITM_registerTMCloneTable
0000000000000000  w    F *UND*  0000000000000000              __cxa_finalize@GLIBC_2.2.5
0000000000001000 g     F .init  0000000000000000              .hidden _init

символ # указывает на важные секции (.data, .text, .rdata, .bss)

objdump -x program показывает какие ссылки нужны:
Версии ссылок:
  требуется из libc.so.6:
    0x09691a75 0x00 03 GLIBC_2.2.5
    0x069691b4 0x00 02 GLIBC_2.34

почему global_var есть в .data - потому что не статическая переменная, а static_var создается один раз в file1 и сохряняется в .text