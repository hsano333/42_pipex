/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsano </var/mail/hsano>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 09:31:44 by hsano             #+#    #+#             */
/*   Updated: 2022/09/05 06:58:44 by hsano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <sys/wait.h>

int	main(int argc, char **argv)
{
	int			fd_in;
	//char		**cmds;
	int			i;
	t_heredoc	heredoc;
	int		last_pid;
	//int			*pid_array;
	int			status;

	if (argc != 5)
		kill_process(22, "Argument list size is only four\n");
	if ((fd_in = open(argv[1], O_RDONLY)) < 0)
		kill_process(0, NULL);

	//pid_array = (int *)malloc(sizeof(int *) * argc);
	heredoc.valid = false;
	i = 1;
	while (++i < (argc - 1))
	{
		fd_in = pipex(argv[i], fd_in, heredoc, &last_pid);
	}
	fd_in = pipex("tee test_tee.txt", fd_in, heredoc, &last_pid);
	waitpid(last_pid, &status, 0);
	close(fd_in);
	//free(cmds);
	return (0);
}
