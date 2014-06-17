/*
** makelist.c for myls in /u/a1/vigier_n/c/rendu/mp/myls
**
** Made by nicolas vigier
** Login   <vigier_n@epita.fr>
**
** Started on  Wed Oct 16 18:23:38 2002 nicolas vigier
** Last update Wed Oct 23 07:11:52 2002 nicolas vigier
*/

#include <dirent.h>
#include <unistd.h>
#include <time.h>
#include "myls.h"

#ifdef major
# define MAJOR major
#else
# define MAJOR(x)        ((((x) & 0x000fff00) >>  8))
#endif
#ifdef minor
# define MINOR
#else
# define MINOR(x)        (((((x) & 0xfff00000) >> 12) | \
                                   (((x) & 0x000000ff) >>  0)))
#endif

static char	filetype(mode_t mode)
{
  if (S_ISFIFO(mode))
    return 'p';
  else if (S_ISREG(mode))
    return '-';
  else if (S_ISLNK(mode))
    return 'l';
  else if (S_ISCHR(mode))
    return 'c';
  else if (S_ISDIR(mode))
    return 'd';
  else if (S_ISBLK(mode))
    return 'b';
  else if (S_ISSOCK(mode))
    return 's';
  else
    return 'w';
}

static char	*get_mode_str(mode_t mode)
{
  char		*res;
  int		i;

  i = 0;
  res = malloc(11);
  res[i++] = filetype(mode);
  res[i++] = (mode & S_IRUSR) ? 'r' : '-';
  res[i++] = (mode & S_IWUSR) ? 'w' : '-';
  res[i++] = (mode & S_IXUSR) ? ((mode & S_ISUID) ? 's' : 'x') :
    ((mode & S_ISUID) ? 'S' : '-');
  res[i++] = (mode & S_IRGRP) ? 'r' : '-';
  res[i++] = (mode & S_IWGRP) ? 'w' : '-';
  res[i++] = (mode & S_IXGRP) ? ((mode & S_ISGID) ? 's' : 'x') :
    ((mode & S_ISGID) ? 'S' : '-');
  res[i++] = (mode & S_IROTH) ? 'r' : '-';
  res[i++] = (mode & S_IWOTH) ? 'w' : '-';
  res[i++] = (mode & S_IXOTH) ? ((mode & S_ISVTX) ? 't' : 'x') :
    ((mode & S_ISVTX) ? 'T' : '-');
  res[i] = 0;
  return res;
}

static char	*get_owner(struct passwd *owner)
{
  return owner ? my_strdup(owner->pw_name) : 0;
}

static char	*get_group(struct group *grp)
{
  return grp ? my_strdup(grp->gr_name) : 0;
}

static int		set_fileinfos_long(t_file *file, struct stat *filestat,
				   int flags, char *fname)
{
  file->filemode = get_mode_str(filestat->st_mode);
  file->filesize = filestat->st_size;
  file->nblinks = filestat->st_nlink;
  file->owner = get_owner(getpwuid(filestat->st_uid));
  file->uid = filestat->st_uid;
  file->group = get_group(getgrgid(filestat->st_gid));
  file->gid = filestat->st_gid;
  file->blocks = filestat->st_blocks;
  file->modifdate = localtime(&(filestat->st_mtime));
  file->modifdatestr = malloc(13);
  strftime(file->modifdatestr, 12, "%b %d %R", file->modifdate);
  file->modifdatestr[12] = 0;
  if (S_ISCHR(filestat->st_mode) || S_ISBLK(filestat->st_mode))
    {
      file->minor = MINOR(filestat->st_rdev);
      file->major = MAJOR(filestat->st_rdev);
      file->specfile = 1;
    }
  else
    file->specfile = 0;
  if (S_ISLNK(filestat->st_mode))
    {
      file->link = malloc(500);
      *(readlink(fname, file->link, 499) +
	file->link) = 0;
    }
  else
    file->link = NULL;
  return 1;
}

static int	is_dotspecrep(char *filename)
{
  int		i;

  return ((i = my_strlen(filename) <= 2) &&
	  !my_strncmp(filename, "..", i));
}

static t_file	*get_fileinfos(struct s_filepath *filename, int flags,
			       int rec, int showrep)
{
  struct stat	*filestat;
  t_file	*new_file;
  int		i;
  char		*tmp;

  filestat = malloc(sizeof (struct stat));
  if (!(flags & (LSOPT_ALL | LSOPT_A)) && (*filename->filename == '.'))
    return NULL;
  if (!(flags & LSOPT_A) && is_dotspecrep(filename->filename))
    return NULL;
  tmp = concatpath(filename->path, filename->filename);
  if (lstat(tmp, filestat) < 0)
    {
      write(2, "myls: ", 8);
      perror(tmp);
      free(filestat);
      return NULL;
    }
  new_file = malloc(sizeof (t_file));
  new_file->rec = (rec && S_ISDIR(filestat->st_mode) &&
		   !is_dotspecrep(filename->filename));
  new_file->showfile = (new_file->rec) ? showrep : 1;
  new_file->name = my_strdup(filename->filename);
  new_file->name_len = my_strlen(filename->filename);
  i = ((flags & LSOPT_LONG) && set_fileinfos_long(new_file, filestat, flags, tmp));
  free(filestat);
  free(tmp);
  return new_file;
}

t_file			*makelist_rep(const char *reppath, int flags, int rec)
{
  t_file		*list;
  t_file		*new_elt;
  DIR			*directory;
  struct dirent		*dirinfo;
  int			(*sortfunc)(const t_file *, const t_file *);
  struct s_filepath	newfile;

  sortfunc = &compare_str;
  list = NULL;
  newfile.path = reppath;
  if (!(directory = opendir(reppath)))
    {
      write(2, "myls: ", 6);
      perror(reppath);
      return NULL;
    }
  while ((dirinfo = readdir(directory)))
    {
      newfile.filename = dirinfo->d_name;
      if ((new_elt = get_fileinfos(&newfile, flags, rec, 1)))
	list = list_insert_sorted(list, new_elt, sortfunc);
    }
  closedir(directory);
  return list;
}

t_file			*makelist_files(char *files[], int argv, int flags)
{
  t_file		*list;
  t_file		*file;
  int			(*sortfunc)(const t_file *, const t_file *);
  struct s_filepath	filename;

  filename.path = "";
  sortfunc = &compare_str;
  list = NULL;
  while (argv--)
    {
      filename.filename = files[argv];
      if ((file = get_fileinfos(&filename, flags | LSOPT_A, 1, 0)))
	list = list_insert_sorted(list, file, sortfunc);
    }
  return list;
}
