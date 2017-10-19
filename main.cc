#include <cstddef>
#include <cstdint>
#include <cstring>

enum vga_color
{
    COLOR_BLACK = 0,
//    COLOR_BLUE = 1,
//    COLOR_GREEN = 2,
//    COLOR_CYAN = 3,
//    COLOR_RED = 4,
//    COLOR_MAGENTA = 5,
//    COLOR_BROWN = 6,
//    COLOR_LIGHT_GREY = 7,
//    COLOR_DARK_GREY = 8,
    COLOR_LIGHT_BLUE = 9,
//    COLOR_LIGHT_GREEN = 10,
//    COLOR_LIGHT_CYAN = 11,
//    COLOR_LIGHT_RED = 12,
//    COLOR_LIGHT_MAGENTA = 13,
//    COLOR_LIGHT_BROWN = 14,
//    COLOR_WHITE = 15,
};

void kPrint(const char *text)
{
//    int terminal_row = 0;
//    int terminal_column = 0;
    uint8_t terminal_color = COLOR_LIGHT_BLUE | (COLOR_BLACK << 4) ;
    auto terminal_buffer = (uint16_t*) 0xB800;
    size_t dataLength = strlen(text);
    for (int i=0;i<dataLength; ++i){
        terminal_buffer [i] = (((char16_t) text[i])  << 8) | terminal_color;
    }
}

void kernel_main()
{
    kPrint("welcome to minimal-os 0.0");
    for(;;);
}