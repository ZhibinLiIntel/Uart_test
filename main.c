typedef struct {
	volatile unsigned long GPHCON;
	volatile unsigned long GPHUP;
	volatile unsigned long ULCON;
	volatile unsigned long UCON;
	volatile unsigned long UFCON;
	volatile unsigned long UMCON;
	volatile unsigned long UTRSTAT;
	volatile unsigned long UERSTAT;
	volatile unsigned long UFSTAT;
	volatile unsigned long UMSTAT;
	volatile unsigned char UTXH;
	volatile unsigned char res1[3];
	volatile unsigned char URXH;
	volatile unsigned char res2[3];
	volatile unsigned long UBRDIV;
	volatile unsigned long UDIVSLOT;
} UART ;
void uart_init() {
	volatile UART *uart = (UART *)0x50000000;
	uart->GPHCON |= 0xa0;
	uart->GPHUP = 0;
	uart->UFCON = 0;
	uart->UMCON = 0;
	uart->ULCON = 0x3;
	uart->UCON = 0x5;
	uart->UBRDIV = 0x22;
	//uart->UDIVSLOT = 0x1FFF;
}
void uart_putc(char c) {
	volatile UART *uart = (UART *)0x50000000;
	while (!(uart->UTRSTAT & 0x2));
		uart->UTXH = c;
}
int main() {
	uart_init();
	uart_putc('h');
	uart_putc('e');
	uart_putc('l');
	uart_putc('l');
	uart_putc('o');
	uart_putc(' ');
	uart_putc('w');
	uart_putc('o');
	uart_putc('r');
	uart_putc('l');
	uart_putc('d');
	while(1);
	return 0;
}