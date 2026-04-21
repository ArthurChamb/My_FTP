/*
** ftp.h for include in /home/arthok/Rendu/C/PSU_2016_myftp
** 
** Made by Arthur XXXXXX
** Login   <arthur.XXXXXX@epitech.eu>
** 
** Started on  Mon May 15 14:30:07 2017 Arthur XXXXXX
** Last update Sun May 21 18:26:51 2017 Arthur XXXXXX
*/

#ifndef _FTP_H_
# define _FTP_H_

# define ACCEPT "Error: Can't accept this request"
# define USER "Error: Please retry with another User/Pass"
# define SOCKET "Error: Can't create the Socket"
# define BIND "Error: There were a problem during the BIND"
# define LISTEN "Error: Can't listen"
# define CONNEX "Error: Can't connect to the server"
# define WRITE "Error: Can't write on the remote server"
# define USAGE "Usage: ./server Port Path"
# define PATH "Error: The PATH you chosed is invalid !"
# define READ "Error: Can't read the line"

# define _120_ "120 Service ready in 1 minutes.\r\n"
# define _125_ "125 Data connection already open; transfer starting.\r\n"
# define _150_ "150 File status okay; about to open data connection.\r\n"
# define _200_ "200 Command okay.\r\n"
# define _214_ "214 Welcome in this help.\r\n"
# define _220_ "220 Service ready for new user.\r\n"
# define _221_ "221 Service closing control connection.\r\n"
# define _226_ "226 Closing data connection.\r\n"
# define _227_ "227 Entering Passive Mode (h1,h2,h3,h4,p1,p2)\r\n"
# define _230_ "230 User logged in, proceed.\r\n"
# define _250_ "250 Requested file action okay, completed.\r\n"
# define _331_ "331 Please specify the password.\r\n"
# define _332_ "332 Need account for login.\r\n"
# define _430_ "430 Invalid username or password.\r\n"
# define _500_ "500 Command not implemented.\r\n"
# define _530_ "530 Not logged in.\r\n"
# define _550_ "550 Can't access this directory.\r\n"
# define _XXX_ "XXX Error.\r\n"

typedef	struct	s_server
{
  char	*path;
}		t_server;

void	error_print(char *str);
void	check_args(int ac, char **av);
void	launch_command(int socket_client, int co, t_server *server);
void	server_launch(int socket_id, t_server *server);
char	**my_str_to_wordtab(char *str);
void	my_putstr(char *str);
int	my_strcmp(char *str, char *str2);
int	check_command(char **tab, int socket_client, t_server *server);
int	user_connection(int co, char **tab, int socket_client);
char	*read_line(char *line, int socket_line);
void	my_write(char *str, int socket_client);
int	help(int socket_client, char **tab);
int	checker(char **tab, int socket_client);
int	pwd(int socket_client, t_server *server);
int	cdup(int socket_client, t_server *server);
int	cwd(char **tab, int socket_client, t_server *server);

#endif
