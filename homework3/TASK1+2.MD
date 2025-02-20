1. global_var в секции .data
2. unitialized_global_var в секции .bss
3. static_var в секции .data
4. global_point в секции .data
5. local_var в стеке функции print_message; static_local_var в .data
6. auto_var в стеке функции main
7. память для dynamic_var будет выделена в куче с помощью malloc
8. stack_point в стеке функции main