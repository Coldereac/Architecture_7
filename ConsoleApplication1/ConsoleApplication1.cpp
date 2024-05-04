

#include <iostream>

//2*c + b*23 - 12
//a/4 - d

int main()
{
    int8_t a = 16, c = 4; //змінні 1 байт
    int16_t b = 6, d = 1; //змінні 2 байти
    int16_t rem, quot; //залишок та частка
    __asm {
        mov al, a //надаємо регістру al значення a
        sar al, 2 //множимо al на 4
        cbw //розширюємо al до ax
        mov bx, d //надаємо регістру bx значення d
        sub ax, bx // віднімаємо від ax bx і результат зберігаємо в ax
        mov cx, ax // надаємо регістру cx значення регістру ax

        mov al, c//надаємо регістру al значення c
        cbw//розширюємо al до ax
        sal ax, 1//множимо ax на 2
        mov bx, b//надаємо регістру bx значення b
        imul bx, 23//множимо bx на 23
        add ax, bx// віднімаємо від ax bx і результат зберігаємо в ax
        sub ax, 12 // віднімаємо від ax 12 і результат зберігаємо в ax
        cwd //розширюємо ax до ax:dx
        idiv cx //ділимо ax на cx, залишок буде в ax, а частка в dx
        mov rem, ax //надаємо змінній rem значення регістру ax
        mov quot, dx //надаємо змінній quot значення регістру dx
    }
    std::cout << "quotient: " << (int)rem << "\n"; //виведення
    std::cout << "remainder: " << (int)quot << "\n"; 
    system("pause");
    return 0;
}
