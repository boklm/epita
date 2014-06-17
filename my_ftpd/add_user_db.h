/*
** add_user_db.h for my_ftpd in .
**
** Made by jean-yves tourtet
** Login   <tourte_j@epita.fr>
**
** Started on  Tue Dec  3 01:28:26 2002 jean-yves tourtet
** Last update Tue Dec  3 22:09:22 2002 jean-yves tourtet
*/

#ifndef ADD_USER_DB_H
#define ADD_USER_DB_H

void	create_user_db(char *username, char *crypt_passwd,
		       char *homedirectory);
void	add_user_db(char *username, char *passwd, char *homedirectory);

#endif /* !ADD_USER_DB_H */
