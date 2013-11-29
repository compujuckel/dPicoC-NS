#include <nspireio/nspireio.h>

static nio_console csl;

void dConsoleInit ()
{
	nio_init(&csl,NIO_MAX_COLS,NIO_MAX_ROWS,0,0,NIO_COLOR_WHITE,NIO_COLOR_BLACK,TRUE);
	nio_set_default(&csl);
}
void dConsoleCleanUp()
{
	nio_free(&csl);
}

void dConsolePut(const char * str)
{
	nio_puts(str);
}
void dConsolePutChar(char c)
{
	 nio_putchar(c);
}
int	dPrintf	(const char *format,...)
{
	char	buf[512];
	int		length;
	va_list	arg_list;

	va_start(arg_list,format);
	length = vsprintf(buf,format,arg_list);
	va_end(arg_list);

	dConsolePut (buf);

	return length;
}

void dConsoleCls()
{
	nio_clear(&csl);
}
void dConsoleRefresh()
{
	nio_fflush(&csl);
}
void dConsoleGets(char * s)
{
	nio_gets(s);
}