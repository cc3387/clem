#ifndef GETCH_1_23_2014_HPP
#	define GETCH_1_23_2014_HPP
#	if defined (__unix__) || (defined (__APPLE__) && defined (__MACH__))
#		include <termios.h>
#		include <unistd.h>
int getch(void)
{
    struct termios oldt, newt;
    int ch;
    
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    
    return ch;
}
#	elif defined(_WIN32)
#		include <conio.h>
#	else
#		error getch is not available on the target system
#	endif
#endif //GETCH_1_23_2014_HPP