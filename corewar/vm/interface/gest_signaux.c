#include "aff.h"

int	gl_redraw;

void	resize(int signal)
{
  gl_redraw = 1;
}

void	quit(int signal)
{
  cl_screen();
  the_write(gl_termfd, MY_NORM, strlen(MY_NORM));
  close(gl_termfd);
  exit(1);
}

void	init_signaux(void)
{
  struct sigaction	sig, sig2;

  sig.sa_handler = resize;
  sig2.sa_handler = quit;
  sig.sa_flags = 0;
  sig2.sa_flags = 0;
  sigaction(SIGWINCH, &sig, NULL);
  sigaction(SIGINT, &sig2, NULL);
}
