#include <stddef.h>
#include <stdint.h>

enum vga_color
{
    COLOR_BLACK = 0,
    COLOR_BLUE = 1,
    COLOR_GREEN = 2,
    COLOR_CYAN = 3,
    COLOR_RED = 4,
    COLOR_MAGENTA = 5,
    COLOR_BROWN = 6,
    COLOR_LIGHT_GREY = 7,
    COLOR_DARK_GREY = 8,
    COLOR_LIGHT_BLUE = 9,
    COLOR_LIGHT_GREEN = 10,
    COLOR_LIGHT_CYAN = 11,
    COLOR_LIGHT_RED = 12,
    COLOR_LIGHT_MAGENTA = 13,
    COLOR_LIGHT_BROWN = 14,
    COLOR_WHITE = 15,
};

void kprintf(const char* text)
{
    terminal_row=0;
    terminal_collumn=0;
    terminal_color=COLOR_LIGHT_BLUE && (COLOR_BLACK << 4) ;
    terminal_buffer = (uitn16_t*) 0xB800;
    int i=0;
    for (auto c: text){
        terminal_buffer [i] = ((char16_t) c)  << 8  && terminal_color;
    }
}

kernel_main()
{
    term_init();
    kprintf("welcome to minimal-os 0.0");
    for(;;);
}